#include <iostream>

#pragma once
class Object
{
private:
	int _rowPos;
	int _colPos;
	char _objectTile;

public:
	enum Direction { N, NE, E, SE, S, SW, W, NW};

	Object();
	Object(int rowPos, int colPos, char objectTile);
	~Object();	

	int getRowPos();
	void setRowPos(int amount);
	int getColPos();
	void setColPos(int amount);
	char getObjectTile();
	void setObjectTile(char symbol);

	bool isColliding(int objectRow, int objectCol, char emptyTile, Direction direction, char** field);
	void draw(char tile, char** field);		// удалить в будущем и исправить логику
	void draw(int row, int col, char tile, char** field);
	void clear(char emptyTile, char** field);	//удалить и исправить взаимосвязи
	void clear(int rowPos, int colPos, char emptyTile, char** field);
	void move(Direction direction, char obectTile, char emptyTile, char** field);
};