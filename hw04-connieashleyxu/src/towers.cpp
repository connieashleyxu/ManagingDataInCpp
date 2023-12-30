// ITP 365 Spring 2023
// HW04 – Towers of Hanoi
// Name: Connie Xu
// Email: caxu@usc.edu
// Platform: Mac
#include "towers.h"

// Name:
//        promptForDisks()
// Input:
//
// Output:
//        number of disks the user requested
// Summary:
//         prompts the user for disks (2 to 10, inclusive)
int promptForDisks()
{
    while (true)
    {
        std::cout << "Enter the number of disks (2 to 10, inclusive) to use: ";
        std::string numDisks;
        std::cin >> numDisks;

        if (stoi(numDisks) >= 2 && stoi(numDisks) <= 10)
        {
            return stoi(numDisks);
        }
        else
        {
            std::cout << "Invalid input. Starting Peg must be 2 to 10, inclusive. Please try again." << std::endl;
        }
    }
}

// Name:
//        promptForPegs(int &startPeg, int &endPeg)
// Input:
//        startPeg, endPeg
// Output:
//
// Summary:
//         prompts the user for starting peg and ending peg (must be 1, 2, or 3)
void promptForPegs(int &startPeg, int &endPeg)
{
    while (true)
    {
        std::cout << "Enter starting Peg (1, 2, or 3): ";
        std::cin >> startPeg;

        if (startPeg == 1 || startPeg == 2 || startPeg == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Starting Peg must be 1, 2, or 3. Please try again." << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Enter ending Peg (1, 2, or 3): ";
        std::cin >> endPeg;

        if (endPeg == 1 || endPeg == 2 || endPeg == 3)
        {
            if (endPeg != startPeg)
            {
                break;
            }
            else
            {
                std::cout << "Ending Peg cannot be the same as the starting Peg. Please try again." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid input. Ending Peg must be 1, 2, or 3. Please try again." << std::endl;
        }
    }
}

// Name:
//        promptForPause()
// Input:
//
// Output:
//         pause duration
// Summary:
//         prompts the user for how long to pause between images in animation (from 1 to 1000000, invlusive)
int promptForPause()
{
    int pauseDuration;
    const int MIN_PAUSE = 1;
    const int MAX_PAUSE = MAXPAUSELEN;

    while (true)
    {
        std::cout << "Enter pause duration in milliseconds (" << MIN_PAUSE << " - " << MAX_PAUSE << ", inclusive): ";
        std::cin >> pauseDuration;

        if (pauseDuration >= MIN_PAUSE && pauseDuration <= MAX_PAUSE)
        {
            return pauseDuration;
        }
        else
        {
            std::cout << "Invalid input. Pause duration must be between " << MIN_PAUSE << " and " << MAX_PAUSE << ", inclusive. Please try again." << std::endl;
        }
    }
}

// Name:
//        promptForWindowSize(int &height, int &width)
// Input:
//        height, width
// Output:
//
// Summary:
//         prompts the user for window size (has to be in valid range of consts in towers.h)
void promptForWindowSize(int &height, int &width)
{
    const int MIN_WIDTH = MINSCREENWIDTH;
    const int MAX_WIDTH = MAXSCREENWIDTH;
    const int MIN_HEIGHT = MINSCREENHEIGHT;
    const int MAX_HEIGHT = MAXSCREENHEIGHT;

    while (true)
    {
        std::cout << "Enter window width (" << MIN_WIDTH << " - " << MAX_WIDTH << "): ";
        std::cin >> width;

        if (width >= MIN_WIDTH && width <= MAX_WIDTH)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Window width must be between " << MIN_WIDTH << " and " << MAX_WIDTH << ". Please try again." << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Enter window height (" << MIN_HEIGHT << " - " << MAX_HEIGHT << "): ";
        std::cin >> height;

        if (height >= MIN_HEIGHT && height <= MAX_HEIGHT)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Window height must be between " << MIN_HEIGHT << " and " << MAX_HEIGHT << ". Please try again." << std::endl;
        }
    }
}

// Name:
//        draw(GWindow &gw, std::vector<Peg> &pegs, int pauseDuration)
// Input:
//        GWindow, Peg Vector, pauseDuration
// Output:
//
// Summary:
//         clear, then draw all pegs (and therefore all disks), then pause
void draw(GWindow &gw, std::vector<Peg> &pegVect, int pauseDuration)
{
    gw.clear();

    for (Peg &peg : pegVect)
    {
        peg.draw(gw);

        for (Disk &disk : peg.getDisks())
        {
            disk.draw(gw);
        }
    }

    pause(pauseDuration);
}

// Name:
//        moveDisk(GWindow &gw, std::vector<Peg> &pegVect, int startPeg, int endPeg, int pauseDuration)
// Input:
//        GWindow, Peg Vector, starting Peg, destination Peg, pauseDuration
// Output:
//
// Summary:
//         remove the top most disk from the start peg, add it to destination peg, then call draw
void moveDisk(GWindow &gw, std::vector<Peg> &pegVect, int startPeg, int destPeg, int pauseDuration)
{
    if (startPeg < 1 || startPeg > NUMPEGS || destPeg < 1 || destPeg > NUMPEGS || startPeg == destPeg)
    {
        std::cerr << "Invalid start or destination peg. Aborting moveDisk." << std::endl;
        return;
    }

    Peg &start = pegVect[startPeg - 1];
    Peg &dest = pegVect[destPeg - 1];

    Disk diskToMove = start.removeDisk();
    dest.addDisk(diskToMove);
    draw(gw, pegVect, pauseDuration);
}

// Name:
//        towerSolve(GWindow &gw, std::vector<Peg> &pegVect, int startPeg, int destPeg, int numDisks, int pauseDuration)
// Input:
//        GWindow, Peg Vector, starting Peg, destination Peg, number of disks to move, pauseDuration
// Output:
//
// Summary:
//         solve the towers of hanoi (recursively)
void towerSolve(GWindow &gw, std::vector<Peg> &pegVect, int startPeg, int destPeg, int numDisks, int pauseDuration)
{
    if (numDisks == 1)
    {
        moveDisk(gw, pegVect, startPeg, destPeg, pauseDuration);
    }
    else
    {
        int tempPeg = 6 - startPeg - destPeg;

        towerSolve(gw, pegVect, startPeg, tempPeg, numDisks - 1, pauseDuration);

        moveDisk(gw, pegVect, startPeg, destPeg, pauseDuration);

        towerSolve(gw, pegVect, tempPeg, destPeg, numDisks - 1, pauseDuration);
    }
}

// Name:
//        towerRun()
// Input:
//
// Output:
//         int
// Summary:
//         run tower simulator
int towerRun()
{
    int screenHeight, screenWidth;
    promptForWindowSize(screenHeight, screenWidth);
    GWindow gw(screenHeight, screenWidth);

    int numDisks = promptForDisks();
    int startPeg, endPeg;

    promptForPegs(startPeg, endPeg);

    int pauseDuration = promptForPause();

    std::vector<Peg> pegVect;
    int numPegs = NUMPEGS;

    int pegWidth = PEG_WIDTH;
    int pegHeight = DISK_HEIGHT * (numDisks + 1);

    int totalPegWidth = screenHeight * (1 - SCREEN_PADDING_PERC);

    int startX = (screenHeight - totalPegWidth) / 2;

    int pegSpacing = totalPegWidth / (numPegs - 1);

    for (int i = 0; i < numPegs; ++i)
    {
        Peg peg(startX + i * pegSpacing, screenWidth - pegHeight, pegHeight, pegWidth);
        pegVect.push_back(peg);
    }

    int spaceBetweenDisks = totalPegWidth / (numDisks + 1);

    // vector of 10 colors
    std::vector<std::string> diskColors = {"PINK", "RED", "ORANGE", "YELLOW", "GREEN", "CYAN", "BLUE", "MAGENTA", "DARK_GRAY", "GRAY"};

    for (int i = numDisks - 1; i >= 0; i--)
    {
        int availableSpace = totalPegWidth - PEG_WIDTH + (i * spaceBetweenDisks);
        int currDiskWidth = std::max(availableSpace / (numDisks * 2), PEG_WIDTH);
        Peg &sourcePeg = pegVect[startPeg - 1];
        Disk disk(sourcePeg.getX() + (PEG_WIDTH / 2) - (currDiskWidth / 2), screenWidth - DISK_HEIGHT * (numDisks - i), DISK_HEIGHT, currDiskWidth);
        disk.setColor(diskColors[i]);
        sourcePeg.addDisk(disk);
    }

    draw(gw, pegVect, pauseDuration);

    towerSolve(gw, pegVect, startPeg, endPeg, numDisks, pauseDuration);

    pause(10000);

    return 0;
}