#include "stock.h"

// stock parameterized constructor
Stock::Stock(std::string inName, std::string inSymbol, const Money &inPurPrice, double inNumShares)
    : mName(inName), mSymbol(inSymbol), mPurchasePrice(inPurPrice), mNumShares(inNumShares)
{
    mCurrentPrice = mPurchasePrice;
}

// stock default constructor
Stock::Stock() : mName(""), mSymbol(""), mPurchasePrice(Money()), mCurrentPrice(Money()), mNumShares(0.0) {}

// getter for current price
Money Stock::getCurrPrice() const
{
    return mCurrentPrice;
}

// getter for purchase price
Money Stock::getPurPrice() const
{
    return mPurchasePrice;
}

// getter for symbol
std::string Stock::getSymbol() const
{
    return mSymbol;
}

// getter for name
std::string Stock::getName() const
{
    return mName;
}

// getter for number of shares
double Stock::getNumShares() const
{
    return mNumShares;
}

// change in stock price
Money Stock::getChange() const
{
    return mCurrentPrice - mPurchasePrice;
}

// current price of the stock
void Stock::setCurrentPrice(const Money &inCurrPrice)
{
    mCurrentPrice = inCurrPrice;
}

// output stream operator
std::ostream &operator<<(std::ostream &out, const Stock &stock)
{
    out << stock.getSymbol() << " : " << stock.getNumShares() << " @ " << stock.getCurrPrice();
    return out;
}