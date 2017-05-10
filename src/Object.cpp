#include "Object.h"
#include <iostream>
using namespace std;

Object::Object() {
	xPos = 0;
	yPos = 0;
	xVel = 0;
	yVel = 0;
	xAcc = 0;
	yAcc = 0;
}

void Object::setPos(double xPos, double yPos) {
	this->xPos = xPos;
	this->yPos = yPos;
	updatePosition();
	return;
}

void Object::setXPos(double xPos) {
	this->xPos = xPos;
	updatePosition();
	return;
}

void Object::setYPos(double yPos) {
	this->yPos = yPos;
	updatePosition();
	return;
}

void Object::setXVel(double xVel) {
	this->xVel = xVel;
	return;
}

void Object::setYVel(double yVel) {
	this->yVel = yVel;
	return;
}

void Object::setXAcc(double xAcc) {
	this->xAcc = xAcc;
	return;
}

void Object::setYAcc(double yAcc) {
	this->yAcc = yAcc;
	return;
}

double Object::getXPos() const {
	return xPos;
}

double Object::getYPos() const {
	return yPos;
}

double Object::getXVel() const {
	return xVel;
}

double Object::getYVel() const {
	return yVel;
}

double Object::getXAcc() const {
	return xAcc;
}

double Object::getYAcc() const {
	return yAcc;
}

void Object::update() {
	xVel += xAcc;
	yVel += yAcc;
	if (xVel > MAX_VELOCITY) xVel = MAX_VELOCITY;
	if (xVel < -MAX_VELOCITY) xVel = -MAX_VELOCITY;
	if (yVel > MAX_VELOCITY) yVel = MAX_VELOCITY;
	if (yVel < -MAX_VELOCITY) yVel = -MAX_VELOCITY;
	xPos += xVel;
	yPos += yVel;
	updatePosition();
	return;
}

void Object::updatePosition() {
	if (xPos < 0) xPos += WINDOW_X;
	if (xPos >= WINDOW_X) xPos -= WINDOW_X;
	if (yPos < 0) yPos += WINDOW_Y;
	if (yPos >= WINDOW_Y) yPos -= WINDOW_Y;
	shape->setPosition(xPos, yPos);
}

void Object::draw(RenderWindow* window) {
	FloatRect box = shape->getGlobalBounds();
	if (box.left <= 0) {
		shape->setPosition(xPos+WINDOW_X, yPos);
		window->draw(*shape);
	}
	if (box.left+box.width > WINDOW_X) {
		shape->setPosition(xPos-WINDOW_X, yPos);
		window->draw(*shape);
	}
	if (box.top <= 0) {
		shape->setPosition(xPos, yPos+WINDOW_Y);
		window->draw(*shape);
	}
	if (box.top+box.height > WINDOW_Y) {
		shape->setPosition(xPos, yPos-WINDOW_Y);
		window->draw(*shape);
	}
	if (box.left <= 0 && box.top <= 0) {
		shape->setPosition(xPos+WINDOW_X, yPos+WINDOW_Y);
		window->draw(*shape);
	}
	if (box.left+box.width > WINDOW_X && box.top+box.height > WINDOW_Y) {
		shape->setPosition(xPos-WINDOW_X, yPos-WINDOW_Y);
		window->draw(*shape);
	}
	updatePosition();
	window->draw(*shape);
	return;
}