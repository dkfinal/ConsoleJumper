#include "Object.h"
#include <string.h>
#include <iostream>
#pragma once
class Player : protected Object
{
private:
	int _life;
	int _jumpForce;
	int _speed;


public:
	Player(int life, int jumpForce, int speed, char playerTile, int playerStartRow, int playerStartCol, char** field);
	~Player();

	int getLife();
	void setLife(int amount);
	int getJumpForce();
	void setJumpForce(int amount);
	char getPlayerTile();
	int getRowPos();
	void setRowPos(int amount);
	int getColPos();
	void setColPos(int amount);

	void move(char emptyTile, Direction direction, char** field);
	bool isColliding(char emptyTile, Direction direction, char** field);
};

