// �2023 Nathan Greenfield
// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Connie Xu
// Email: caxu@usc.edu
// Platform: Mac
#pragma once

#include "disk.h"
#include "peg.h"
#include "gwindow.h"

#include <vector>

int promptForDisks();
void promptForPegs(int &, int &);
int promptForPause();
void promptForWindowSize(int &, int &);
void draw(GWindow &, std::vector<Peg> &, int);
void moveDisk(GWindow &, std::vector<Peg> &, int, int, int);
void towerSolve(GWindow &, std::vector<Peg> &, int, int, int, int);
int towerRun();

const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;

// Add consts
const int DISK_HEIGHT = 50;
const int PEG_WIDTH = 20;
const double SCREEN_PADDING_PERC = 0.3;
