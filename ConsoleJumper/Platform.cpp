#include "Platform.h"

Platform::Platform(int speed, int headStartRow, int headStartCol, char platformTile, PlatformType type, char emptyTile, char** field)
	: Object(headStartRow, headStartCol, platformTile)
{
	_speed = speed;
	_platformTile = platformTile;
	draw(headStartRow, headStartCol, platformTile, field);
	build(type, emptyTile, field);
}

Platform::~Platform()
{
	//destroy(type, emptyTile, field);
}

int Platform::getSpeed()
{
	return _speed;
}

void Platform::setSpeed(int amount)
{
	_speed = amount;
}

int Platform::getHeadRow()
{
	return Object::getRowPos();
}

int Platform::getHeadCol()
{
	return Object::getColPos();
}



bool Platform::isColliding(int platformHeadRow, int platformHeadCol, char emptyTile, Object::Direction direction, char** field)
{
	return Object::isColliding(platformHeadRow, platformHeadCol, emptyTile, direction, field);
}

void Platform::move(PlatformType type, char emptyTile, char** field)
{
	for (int i = 0; i < _speed; i++) {
		if (!(isColliding(getRowPos(), getColPos(), emptyTile, Object::W, field))) {
			destroy(Platform::A, emptyTile, field);
			Object::move(Object::W, getObjectTile(), emptyTile, field);
			build(Platform::A, emptyTile, field);
		}
	}
}

void Platform::build(PlatformType type, char emptyTile, char** field)
{
	switch (type)
	{
	case Platform::A:
		buildA(emptyTile, field);
		break;
	case Platform::B:
		break;
	case Platform::C:
		break;
	default:
		break;
	}
}

void Platform::buildA(char emptyTile, char** field)
{
	int i = 1;
	while (!(isColliding(getRowPos(), getColPos() + i, emptyTile, E, field)) && (i < _platformASize))	{
		Object::draw(Object::getRowPos(), Object::getColPos() + i, _platformTile, field);
		i += 1;
	}
}

void Platform::destroy(PlatformType type, char emptyTile, char** field)
{
	switch (type)
	{
	case Platform::A:
		destroyA(emptyTile, field);
		break;
	case Platform::B:
		break;
	case Platform::C:
		break;
	default:
		break;
	}
}

void Platform::destroyA(char emptyTile, char** field)
{
	int i = 1;
	while (!(isColliding(getRowPos(), getColPos() + i, emptyTile, E, field)) && (i < _platformASize)) {
		Object::clear(getRowPos(), getColPos() + i, emptyTile, field);
		i += 1;
	}
}