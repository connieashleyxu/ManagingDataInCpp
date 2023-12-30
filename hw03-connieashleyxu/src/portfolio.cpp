#include "portfolio.h"
#include <algorithm>

// default constructor
StockPortfolio::StockPortfolio()
{
}

// add stock into map
void StockPortfolio::addStock(Stock inStock)
{
    mStocks[inStock.getSymbol()] = inStock;
}

// map contains stock
bool StockPortfolio::containsStock(std::string inSymbol)
{
    return mStocks.find(inSymbol) != mStocks.end();
}

// access stock by symbol (does not check to see if it exists)
Stock &StockPortfolio::operator[](std::string inSymbol)
{
    return mStocks[inSymbol];
}

// total value of portfolio
Money StockPortfolio::getTotalValue() const
{
    Money totalValue;

    for (const auto &entry : mStocks)
    {
        totalValue += entry.second.getCurrPrice() * entry.second.getNumShares();
    }

    return totalValue;
}

// original value (purchase price) of portfolio
Money StockPortfolio::getOrigValue() const
{
    Money origValue;

    for (const auto &entry : mStocks)
    {
        origValue += entry.second.getPurPrice() * entry.second.getNumShares();
    }

    return origValue;
}

// profit of portfolio
Money StockPortfolio::getProfit() const
{
    Money totalValue = getTotalValue();
    Money origValue = getOrigValue();

    Money profit = totalValue - origValue;

    return profit;
}

// stock list in portfolio (sorted by alphabetical order)
std::vector<std::string> StockPortfolio::getAlphaList()
{
    std::vector<std::string> alphaList;

    for (const auto &entry : mStocks)
    {
        alphaList.push_back(entry.first);
    }

    std::sort(alphaList.begin(), alphaList.end());

    return alphaList;
}

// stock list in portfolio (sorted by decreasing current value)
std::vector<std::string> StockPortfolio::getValueList()
{
    std::vector<std::string> valueList;

    std::vector<std::pair<std::string, Money>> symbolValuePairs;

    for (const auto &entry : mStocks)
    {
        Money totalValue = entry.second.getCurrPrice();
        symbolValuePairs.push_back(std::make_pair(entry.first, totalValue));
    }

    std::sort(symbolValuePairs.begin(), symbolValuePairs.end(),
              [](const std::pair<std::string, Money> &a, const std::pair<std::string, Money> &b)
              {
                  return a.second > b.second;
              });

    valueList.reserve(symbolValuePairs.size());

    for (const auto &pair : symbolValuePairs)
    {
        valueList.push_back(pair.first);
    }

    std::cout << "Contents of valueList:";
    for (const std::string &symbol : valueList)
    {
        std::cout << " " << symbol;
    }
    std::cout << std::endl;

    return valueList;
}

// stock list in portfolio (sorted by decreasing change)
std::vector<std::string> StockPortfolio::getDiffList()
{
    std::vector<std::string> diffList;

    diffList.reserve(mStocks.size());

    for (const auto &entry : mStocks)
    {
        diffList.push_back(entry.first);
    }

    std::sort(diffList.begin(), diffList.end(), [this](const std::string &a, const std::string &b)
              { return mStocks[a].getChange() > mStocks[b].getChange(); });

    return diffList;
}

void StockPortfolio::clear()
{
    mStocks.clear();
}