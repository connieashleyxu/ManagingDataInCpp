// �2023 Nathan Greenfield
// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Connie Xu
// Email: caxu@usc.edu
// Platform: Mac
#pragma once

#include <iostream>
#include <string>
#include "gwindow.h"

class Disk
{
public:
	Disk();
	Disk(int, int, int, int);

	void draw(GWindow &gw);

	void setX(int);
	void setY(int);

	int getHeight();

	// Add getters
	int getWidth();
	int getX();
	int getY();

	// set color of disk
	void setColor(const std::string &color);

private:
	int mX;
	int mY;
	int mW;
	int mH;
	std::string mColor;
};