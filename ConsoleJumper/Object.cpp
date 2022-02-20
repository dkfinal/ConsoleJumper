#include "Object.h"

Object::Object()
{
	_rowPos = 0;
	_colPos = 0;
	_objectTile = '?';
}

Object::Object(int rowPos, int rowCol, char objectTile)
{

	_rowPos = rowPos;
	_colPos = rowCol;
	_objectTile = objectTile;
}

Object::~Object()
{
}

int Object::getRowPos()
{
	return _rowPos;
}

void Object::setRowPos(int amount)
{
	_rowPos = amount;
}

int Object::getColPos()
{
	return _colPos;
}

void Object::setColPos(int amount)
{
	_colPos = amount;
}

char Object::getObjectTile()
{
	return _objectTile;
}

void Object::setObjectTile(char symbol)
{
	_objectTile = symbol;
}

bool Object::isColliding(int objectRow, int objectCol, char emptyTile, Direction direction, char** field)
{
	switch (direction)
	{
	case Object::N:
		return ((field[objectRow - 1][objectCol] != emptyTile) && (field[objectRow - 1][objectCol] != getObjectTile()));
		break;
	case Object::NE:
		break;
	case Object::E:
		return ((field[objectRow][objectCol + 1] != emptyTile) && (field[objectRow][objectCol + 1] != getObjectTile()));
		break;
	case Object::SE:
		break;
	case Object::S:
		return ((field[objectRow + 1][objectCol] != emptyTile) && (field[objectRow + 1][objectCol] != getObjectTile()));
		break;
	case Object::SW:
		break;
	case Object::W:
		return ((field[objectRow][objectCol - 1] != emptyTile) && (field[objectRow][objectCol - 1] != getObjectTile()));
		break;
	case Object::NW:
		break;
	default:
		break;
	}
}

void Object::draw(char tile, char** field)
{
	field[_rowPos][_colPos] = tile;
}

void Object::draw(int row, int col, char tile, char** field)
{
	field[row][col] = tile;
}

void Object::clear(char emptyTile, char** field)
{
	field[_rowPos][_colPos] = emptyTile;
}

void Object::clear(int rowPos, int colPos, char emptyTile, char** field)
{
	field[rowPos][colPos] = emptyTile;
}

void Object::move(Direction direction, char obectTile, char emptyTile, char** field)
{
	switch (direction)
	{
	case Object::N:
		clear(emptyTile, field);
		_rowPos -= 1;
		draw(obectTile, field);
		break;
	case Object::NE:
		clear(emptyTile, field);
		_rowPos -= 1;
		_colPos += 1;
		draw(obectTile, field);
		break;
	case Object::E:
		clear(emptyTile, field);
		_colPos += 1;
		draw(obectTile, field);
		break;
	case Object::SE:
		clear(emptyTile, field);
		_rowPos += 1;
		_colPos += 1;
		draw(obectTile, field);
		break;
	case Object::S:
		clear(emptyTile, field);
		_rowPos += 1;
		draw(obectTile, field);
		break;
	case Object::SW:
		clear(emptyTile, field);
		_rowPos += 1;
		_colPos -= 1;
		draw(obectTile, field);
		break;
	case Object::W:
		clear(emptyTile, field);
		_colPos -= 1;
		draw(obectTile, field);
		break;
	case Object::NW:
		clear(emptyTile, field);
		_rowPos -= 1;
		_colPos -= 1;
		draw(obectTile, field);
		break;
	}
}
