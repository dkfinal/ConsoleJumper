#include "Player.h"

Player::Player(int life, int jumpForce, int speed, char playerTile, int playerStartRow, int playerStartCol, char** field)
	: Object(playerStartRow, playerStartCol, playerTile)
{
	_life = life;
	_jumpForce = jumpForce;
	_speed = speed;
	Object::draw(playerTile, field);
}

Player::~Player()
{
}

int Player::getLife()
{
	return _life;
}

void Player::setLife(int amount)
{
	_life = amount;
}

int Player::getJumpForce()
{
	return _jumpForce;
}

void Player::setJumpForce(int amount)
{
	_jumpForce = amount;
}

char Player::getPlayerTile()
{
	return Object::getObjectTile();
}

int Player::getRowPos()
{
	return Object::getRowPos();
}

void Player::setRowPos(int amount)
{
	Object::setRowPos(amount);
}

int Player::getColPos()
{
	return Object::getColPos();
}

void Player::setColPos(int amount)
{
	Object::setColPos(amount);
}

void Player::move(char emptyTile, Direction direction, char** field)
{
	if ((direction != Object::N) && (direction != Object::S)) {
		for (int i = 0; i < _speed; i++) {
			if (!(Object::isColliding(getRowPos(), getColPos(), emptyTile, direction, field))) {
				Object::move(direction, getObjectTile(), emptyTile, field);
			}
		}
	}
	else if (direction == Object::N) {
		if (Object::isColliding(getRowPos(), getColPos(), emptyTile, Object::S, field)) {
			for (int i = 0; i < _jumpForce; i++) {
				if (!(Object::isColliding(getRowPos(), getColPos(), emptyTile, Object::N, field))) {
					Object::move(direction, getObjectTile(), emptyTile, field);
				}
			}
		}
	}
	else if (direction == Object::S) {
		if (!(Object::isColliding(getRowPos(), getColPos(), emptyTile, direction, field))) {
			Object::move(direction, getObjectTile(), emptyTile, field);
		}
	}
}

bool Player::isColliding(char emptyTile, Object::Direction direction, char** field)
{
	return Object::isColliding(getRowPos(), getColPos(), emptyTile, direction, field);
}
