#include <iostream>
#include <fstream>
#include <sstream>
#include "money.h"
#include "stock.h"
#include "portfolio.h"
#include "driver.h"
#include "strlib.h"

int main()
{
    /*
    TEST DRIVER.CPP
    */
    StockPortfolio portfolio;

    // Add initial stocks to the portfolio
    // Stock initialStock1("Berkshire Hathaway Inc. Cl A", "BRK.A", Money(1307.00), 11);
    // Stock initialStock2("Apple Inc.", "APPL", Money(0.11), 10000.0);
    // Stock initialStock3("Mondelez International Inc. Cl A", "MDLZ", Money(31.07), 30);

    // portfolio.addStock(initialStock1);
    // portfolio.addStock(initialStock2);
    // portfolio.addStock(initialStock3);

    std::ifstream inputFile("input/test01.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();

    // std::string line;
    // std::cerr << "file contents: " << buffer.str() << std::endl;
    processFile(portfolio, buffer.str());

    // std::string line;
    // while (std::getline(inputFile, line))
    // {
    //     bool success = false;

    //     if (line[0] == '+')
    //     {
    //         success = updateStock(portfolio, line.substr(1));
    //     }
    //     else
    //     {
    //         success = buyStock(portfolio, line);
    //     }

    //     if (success)
    //     {
    //         std::cout << "Command: " << line << " - Success" << std::endl;
    //     }
    //     else
    //     {
    //         std::cerr << "Command: " << line << " - Failed" << std::endl;
    //     }
    // }

    inputFile.close();

    return 0;

    // /*
    // TEST PORTFOLIO.CPP
    // */
    // StockPortfolio myPortfolio;

    // Stock stock1("Company A", "A123", Money(100, 50), 10.0);
    // Stock stock2("Company B", "B456", Money(75, 25), 5.0);
    // Stock stock3("Company C", "C789", Money(50, 75), 8.0);

    // myPortfolio.addStock(stock1);
    // myPortfolio.addStock(stock2);
    // myPortfolio.addStock(stock3);

    // std::cout << "Original Value of Portfolio: " << myPortfolio.getOrigValue() << std::endl;
    // std::cout << "Total Value of Portfolio: " << myPortfolio.getTotalValue() << std::endl;
    // std::cout << "Profit of Portfolio: " << myPortfolio.getProfit() << std::endl;

    // std::vector<std::string> alphaList = myPortfolio.getAlphaList();
    // std::vector<std::string> valueList = myPortfolio.getValueList();
    // std::vector<std::string> diffList = myPortfolio.getDiffList();

    // std::cout << "Alphabetical List of Stocks:" << std::endl;
    // for (const std::string &symbol : alphaList)
    // {
    //     std::cout << symbol << std::endl;
    // }

    // std::cout << "List of Stocks by Current Value:" << std::endl;
    // for (const std::string &symbol : valueList)
    // {
    //     std::cout << symbol << std::endl;
    // }

    // std::cout << "List of Stocks by Change in Value:" << std::endl;
    // for (const std::string &symbol : diffList)
    // {
    //     std::cout << symbol << std::endl;
    // }

    // return 0;

    // /*
    // TEST STOCK.CPP
    // */
    // Stock stock1("Apple Inc.", "AAPL", Money(0.11), 10000.0);
    // Stock stock2("Berkshire Hathaway Inc. Cl A", "BRK.A", Money(1307.00), 11);

    // std::cout << "Stock 1: " << stock1 << std::endl;
    // std::cout << "Stock 2: " << stock2 << std::endl;

    // stock1.setCurrentPrice(Money(1550.75));
    // stock2.setCurrentPrice(Money(2050.25));

    // std::cout << "Updated Stock 1: " << stock1 << std::endl;
    // std::cout << "Updated Stock 2: " << stock2 << std::endl;

    // Money change1 = stock1.getChange();
    // Money change2 = stock2.getChange();

    // std::cout << "Change in Stock 1 value: " << change1 << std::endl;
    // std::cout << "Change in Stock 2 value: " << change2 << std::endl;

    // return 0;

    // /*
    // TEST MONEY.CPP
    // */
    // Money money1;
    // Money money2(4155277);
    // Money money3(1234.56);
    // Money money4(789);

    // std::cout << "money1: " << money1 << std::endl;
    // std::cout << "money2: " << money2 << std::endl;
    // std::cout << "money3: " << money3 << std::endl;
    // std::cout << "money4: " << money4 << std::endl;

    // money1 += money2;
    // money3 -= money4;
    // // money2 *= 0.9;
    // money2 = money2 * 0.9;
    // money4 /= 3.0;

    // std::cout << "Updated money1: " << money1 << std::endl;
    // std::cout << "Updated money3: " << money3 << std::endl;
    // std::cout << "Updated money2: " << money2 << std::endl;
    // std::cout << "Updated money4: " << money4 << std::endl;

    // if (money1 < money3)
    // {
    //     std::cout << "money1 is less than money3" << std::endl;
    // }
    // else
    // {
    //     std::cout << "money1 is not less than money3" << std::endl;
    // }

    // Money total = money1 + money2;

    // std::cout << "Total: " << total << std::endl;

    // return 0;
}