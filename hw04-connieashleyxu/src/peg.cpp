// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Connie Xu
// Email: caxu@usc.edu
// Platform: Mac
#include "peg.h"
#include "disk.h"

// Name:
//        Peg()
// Input:
//
// Output:
//
// Summary:
//         default constructor
Peg::Peg()
{
    mH = 400;
    mW = 10;
    mX = 390;
    mY = 200;
    color = "BLACK";
}

// Name:
//        Peg(int x, int y, int height, int width)
// Input:
//
// Output:
//
// Summary:
//         parameterized constructor
Peg::Peg(int x, int y, int height, int width)
{
    mX = x;
    mY = y;
    mH = height;
    mW = width;
}

// Name:
//        draw(GWindow &gw)
// Input:
//        Gwindow
// Output:
//
// Summary:
//         draw function for peg
void Peg::draw(GWindow &gw)
{
    gw.setColor("BLACK");
    gw.fillRect(getX(), getY(), getWidth(), getHeight());
}

// Name:
//        addDisk(Disk)
// Input:
//        disk object
// Output:
//
// Summary:
//         add disk function for peg
void Peg::addDisk(Disk disk)
{
    int x = mX + (mW - disk.getWidth()) / 2;
    int y = mY + mH - disk.getHeight() * (diskVect.size() + 1);

    disk.setX(x);
    disk.setY(y);

    diskVect.push_back(disk);
}

// Name:
//        removeDisk()
// Input:
//
// Output:
//        removed disk
// Summary:
//         remove the last Disk on that Peg and return it
Disk Peg::removeDisk()
{
    if (diskVect.empty())
    {
        return Disk();
    }
    else
    {
        Disk removedDisk = diskVect.back();

        diskVect.pop_back();

        return removedDisk;
    }
}

// Name:
//        getHeight()
// Input:
//
// Output:
//        height
// Summary:
//         getter function for height
int Peg::getHeight()
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
int Peg::getWidth()
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
int Peg::getX()
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
int Peg::getY()
{
    return mY;
}

// Name:
//        getDisks()
// Input:
//
// Output:
//        diskVect
// Summary:
//         vector getter function for disk
std::vector<Disk> &Peg::getDisks()
{
    return diskVect;
}