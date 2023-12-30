#include "money.h"

#include <iomanip>
// money default constructor
Money::Money() : mCents(0) {}

// money parameterized constructor with dollars and cents
Money::Money(long long inDollars, long long inCents)
{
    mCents = (inDollars * 100 + inCents) * DEC_SHIFT;
}

// money parameterized constructor with dollars
Money::Money(double inDollars)
{
    mCents = static_cast<long long>(inDollars * 100 * DEC_SHIFT);
}

// money parameterized constructor with cents as int (long long)
Money::Money(long long inCents) : mCents(inCents * DEC_SHIFT) {}

// money parameterized constructor with cents as int (int)
Money::Money(int inCents) : mCents(static_cast<long long>(inCents) * DEC_SHIFT) {}

// arithmetic assignment operator +=
Money &Money::operator+=(const Money &right)
{
    mCents += right.mCents;
    return *this;
}

// arithmetic assignment operator -=
Money &Money::operator-=(const Money &right)
{
    mCents -= right.mCents;
    return *this;
}

// arithmetic assignment operator *=
Money &Money::operator*=(double right)
{
    mCents = static_cast<long long>(mCents * right);
    return *this;
}

// arithmetic assignment operator /=
Money &Money::operator/=(double right)
{
    if (right != 0.0)
    {
        mCents = static_cast<long long>(mCents / right);
    }
    // division by zero? keep original value
    return *this;
}

// comparison operator <
bool operator<(const Money &left, const Money &right)
{
    return left.mCents / DEC_SHIFT < right.mCents / DEC_SHIFT;
}

// comparison operator >
bool operator>(const Money &left, const Money &right)
{
    return left.mCents / DEC_SHIFT > right.mCents / DEC_SHIFT;
}

// comparison operator <=
bool operator<=(const Money &left, const Money &right)
{
    return left.mCents / DEC_SHIFT <= right.mCents / DEC_SHIFT;
}

// comparison operator >=
bool operator>=(const Money &left, const Money &right)
{
    return left.mCents / DEC_SHIFT >= right.mCents / DEC_SHIFT;
}

// comparison operator ==
bool operator==(const Money &left, const Money &right)
{
    return left.mCents / DEC_SHIFT == right.mCents / DEC_SHIFT;
}

// comparison operator !=
bool operator!=(const Money &left, const Money &right)
{
    return left.mCents / DEC_SHIFT != right.mCents / DEC_SHIFT;
}

// binary arithmetic operator +
Money operator+(const Money &left, const Money &right)
{
    Money result;
    result.addShiftedMoneyVal(left.mCents + right.mCents);
    return result;
}

// binary arithmetic operator -
Money operator-(const Money &left, const Money &right)
{
    Money result;
    result.addShiftedMoneyVal((left.mCents - right.mCents));
    return result;
}

// binary arithmetic operator *
Money operator*(const Money &left, double right)
{
    Money result;
    result.addShiftedMoneyVal(static_cast<long long>(left.mCents * right));
    return result;
}

// binary arithmetic operator /
Money operator/(const Money &left, double right)
{
    if (right == 0)
    {
        // division by zero? keep original value
        return left;
    }
    Money result;
    result.addShiftedMoneyVal(static_cast<long long>(left.mCents / right));
    return result;
}

// output stream operator <<
std::ostream &operator<<(std::ostream &out, const Money &money)
{
    bool isNegative = (money.mCents < 0);

    long long absCents = std::abs(money.mCents);

    long long dollars = absCents / (100 * DEC_SHIFT);
    long long cents = (absCents / DEC_SHIFT) % 100;

    out << std::fixed << std::setprecision(2);

    if (isNegative)
    {
        out << "$-" << dollars << '.' << std::setw(2) << std::setfill('0') << cents;
    }
    else
    {
        out << "$" << dollars << '.' << std::setw(2) << std::setfill('0') << cents;
    }

    return out;
}

// input stream operator >>
std::istream &operator>>(std::istream &in, Money &money)
{
    double value;
    in >> value;

    long long cents = static_cast<long long>(value * 100 * DEC_SHIFT);

    money.mCents = cents;

    return in;
}

void Money::addShiftedMoneyVal(const long long &shiftedVal)
{
    mCents += shiftedVal;
}
