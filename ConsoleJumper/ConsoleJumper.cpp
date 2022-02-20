#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include "Player.h"
#include "Platform.h"

int main() {
    bool session = true;    // параметры
    int fieldRows = 15;
    int fieldCols = 90;
    const char emptyTile = ' ';
    const char boundTile = '#';
    const char playerTile = '@';
    const char platformTile = '*';
    char** field;
    int playerStartRow = 13;
    int playerStartCol = 45;
    int playerLife = 1;
    int playerJumpForce = 5;
    int playerSpeed = 3;
    int platformSpeed = 2;
   // int platformHeadStartRow = 2; 
    int platformHeadStartCol = fieldCols - 2;
    std::vector<Platform> platformStore;
    int timeCounter = 0;


    field = new char* [fieldRows];  // Создание поля
    for (int i = 0; i < fieldRows; i++) {
        field[i] = new char[fieldCols];
    }

    for (int i = 0; i < fieldRows; i++) {   // Заполнение поля
        for (int j = 0; j < fieldCols; j++) {
            if (i == 0 || i == (fieldRows - 1) || j == 0 || j == (fieldCols - 1)) {
                field[i][j] = boundTile;
            }
            else {
                field[i][j] = emptyTile;
            }            
        }
    }

    Player* player = new Player(playerLife, playerJumpForce, playerSpeed, playerTile, playerStartRow, playerStartCol, field);

    while (session == true) {
        if (!(player->isColliding(emptyTile, Object::S, field))) {    // Гравитация
            player->move(emptyTile, Object::S, field);
        }

        if ((timeCounter % 2) == 0) {       // Спавнер платформ
            platformStore.emplace_back(platformSpeed, (std::rand() % (fieldRows - 2) + 1), platformHeadStartCol, platformTile, Platform::A, emptyTile, field);
        }


        if (_kbhit()) { // Управление
            int key = _getch();
            if (key == 0 || key == 224)
                key = _getch();

            if (key != 13) {
                switch (key) {
                case 119:   // W
                case 72:    // Up
                case 32:    // Space
                        player->move(emptyTile, Object::N, field);
                    break;
                case 97:    // A
                case 75:    // Left
                    player->move(emptyTile, Object::W, field);
                    break;
                case 100:   // D
                case 77:    // Right
                    player->move(emptyTile, Object::E, field);
                    break;
                default:
                    break;
                }
            }
            else {
                session = false;
            }
        }

        for (int i = 0; i < platformStore.size(); i++) {        // двигатель и уничтожитель платформ
            Platform& platform = platformStore[i];
            if (!(platform.isColliding(platform.getHeadRow(), platform.getHeadCol(), emptyTile, Object::W, field))) {
                platform.move(Platform::A, emptyTile, field);
                if (!(platform.isColliding(platform.getHeadRow(), platform.getHeadCol(), boundTile, Object::W, field))) {
                    platform.destroy(Platform::A, emptyTile, field);
                    platformStore.erase(platformStore.begin() + i);
                }
            }
        }

        system("cls");
        for (int i = 0; i < fieldRows; i++) { // Вывод на экран
            for (int j = 0; j < fieldCols; j++) {
                std::cout << field[i][j];
            }
            std::cout << std::endl;
        }
        Sleep(500);
        timeCounter += 1;
    }




    delete player;
    for (int i = 0; i < fieldRows; i++) {
        delete field[i];
    }
    delete[] field;
    std::cout << "The End!\n";
}