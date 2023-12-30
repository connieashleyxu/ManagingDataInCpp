// �2023 Nathan Greenfield
// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Connie Xu
// Email: caxu@usc.edu
// Platform: Mac
#pragma once

#include <string>

#include <vector>
#include "gwindow.h"

#include "disk.h"

class Peg
{
public:
	Peg();
	Peg(int, int, int, int);

	void draw(GWindow &);
	void addDisk(Disk);
	Disk removeDisk();

	// Add getters
	int getHeight();
	int getWidth();
	int getX();
	int getY();
	std::vector<Disk> &getDisks();

private:
	int mX;
	int mY;
	int mW;
	int mH;
	int xCenter;
	int curTop;

	std::string color;

	std::vector<Disk> diskVect;
};