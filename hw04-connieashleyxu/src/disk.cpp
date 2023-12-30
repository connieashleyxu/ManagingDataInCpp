// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Connie Xu
// Email: caxu@usc.edu
// Platform: Mac

#include "disk.h"

// Name:
//        Disk()
// Input:
//
// Output:
//
// Summary:
//         default constructor
Disk::Disk()
{
    mX = 0;
    mY = 0;
    mH = 30;
    mW = 20;
}

// Name:
//        Disk(int, int, int, int)
// Input:
//        x, y, height, and width
// Output:
//
// Summary:
//         parameterized constructor
Disk::Disk(int x, int y, int height, int width)
{
    mX = x;
    mY = y;
    mH = height;
    mW = width;
}

// Name:
//        draw(GWindow &gw)
// Input:
//        graphical interface window, gw
// Output:
//
// Summary:
//         draw function for disk
void Disk::draw(GWindow &gw)
{
    gw.setColor(mColor);
    gw.fillRect(getX(), getY(), getWidth(), getHeight());
    gw.setColor("BLACK");
    gw.drawRect(getX(), getY(), getWidth(), getHeight());
}

// Name:
//        setX(int x)
// Input:
//        x
// Output:
//
// Summary:
//         setter function for x
void Disk::setX(int x)
{
    mX = x;
}

// Name:
//        setY(int y)
// Input:
//        y
// Output:
//
// Summary:
//         setter function for y
void Disk::setY(int y)
{
    mY = y;
}

// Name:
//        getHeight()
// Input:
//
// Output:
//        height
// Summary:
//         getter function for height
int Disk::getHeight()
{
    return mH;
}

// Name:
//        getWidth()
// Input:
//
// Output:
//        width
// Summary:
//         getter function for width
int Disk::getWidth()
{
    return mW;
}

// Name:
//        getX()
// Input:
//
// Output:
//        x
// Summary:
//         getter function for x
int Disk::getX()
{
    return mX;
}

// Name:
//        getY()
// Input:
//
// Output:
//        y
// Summary:
//         getter function for y
int Disk::getY()
{
    return mY;
}

// Name:
//        (const std::string &color)
// Input:
//        color
// Output:
//
// Summary:
//         setter function for disk color
void Disk::setColor(const std::string &color)
{
    mColor = color;
}