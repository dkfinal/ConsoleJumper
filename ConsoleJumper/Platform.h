#pragma once
#include "Object.h"
#include <cstdlib>
class Platform : protected Object
{
private:
	int _speed;
	char _platformTile;
	int _platformASize = 10;
	int _platformBSize = 0;
	int _platformCSize = 0;

public:
	enum PlatformType {A, B, C};

	Platform(int speed, int headStartRow, int headStartCol, char platformTile, PlatformType type, char emptyTile, char** field);
	~Platform();
	
	int getSpeed();
	void setSpeed(int amount);
	int getHeadRow();
	int getHeadCol();

	bool isColliding(int platformHeadRow, int platformHeadCol, char emptyTile, Object::Direction direction, char** field);
	void move(PlatformType type, char emptyTile, char** field);
	void build(PlatformType type, char emptyTile, char** field);
	void buildA(char emptyTile, char** field);
	void destroy(PlatformType type, char emptyTile, char** field);
	void destroyA(char emptyTile, char** field);
};

