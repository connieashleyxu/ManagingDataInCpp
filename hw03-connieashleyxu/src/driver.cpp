#include "driver.h"
#include "strlib.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

// buy stock
bool buyStock(StockPortfolio &inPort, const std::string &inString)
{
    std::string trimmedString = trim(inString);

    if (trimmedString.empty())
    {
        std::cerr << "Error parsing input string for buying stock: Input is empty." << std::endl;
        return false;
    }

    std::vector<std::string> tokens = strSplit(trimmedString, '|');
    std::string symbol = tokens[0];

    if (symbol.length() != 3 && symbol.length() != 4 && symbol.length() != 5)
    {
        std::cerr << "Error parsing input string for buying stock: Incorrect format (buy)." << std::endl;
        return false;
    }

    std::string name = tokens[1];
    double purchasePrice, numShares;

    if (!(std::istringstream(tokens[2]) >> purchasePrice) || !(std::istringstream(tokens[3]) >> numShares))
    {
        std::cerr << "Error parsing input string for buying stock: Incorrect format." << std::endl;
        return false;
    }

    for (char &c : symbol)
    {
        c = std::toupper(c);
    }

    Stock newStock(name, symbol, Money(purchasePrice), numShares);
    inPort.addStock(newStock);

    return true;
}

// update stock
bool updateStock(StockPortfolio &inPort, const std::string &inString)
{
    std::string trimmedString = trim(inString);

    if (trimmedString.empty())
    {
        return true;
    }

    std::vector<std::string> tokens = strSplit(trimmedString, '|');

    if (tokens.size() != 2)
    {
        std::cerr << "Error parsing input string for updating stock: Incorrect format." << std::endl;
        return false;
    }

    std::string symbol = tokens[0];
    double currentPrice;

    if (!(std::istringstream(tokens[1]) >> currentPrice))
    {
        std::cerr << "Error parsing input string for updating stock: Incorrect format." << std::endl;
        return false;
    }

    if (inPort.containsStock(symbol))
    {
        Stock &existingStock = inPort[symbol];
        existingStock.setCurrentPrice(Money(currentPrice));
        return true;
    }
    else
    {
        std::cerr << "Stock with symbol " << symbol << " not found in the portfolio." << std::endl;
        return false;
    }
}

// process file
bool processFile(StockPortfolio &inPort, const std::string &inString)
{
    // inPort.clear();
    std::ifstream inputFile(inString);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open input file." << std::endl;

        inputFile.close();
        return false;
    }

    std::string line;

    while (std::getline(inputFile, line))
    {
        line = trim(line);

        if (line.empty())
            continue;

        if (line[0] == '+')
        {
            if (!updateStock(inPort, line.substr(1)))
            {
                inputFile.close();
                return false;
            }
        }
        else
        {

            if (!buyStock(inPort, line))
            {
                inputFile.close();
                return false;
            }
        }
    }

    inputFile.close();
    return true;
}

std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");

    if (start == std::string::npos || end == std::string::npos)
    {
        return "";
    }

    return s.substr(start, end - start + 1);
}