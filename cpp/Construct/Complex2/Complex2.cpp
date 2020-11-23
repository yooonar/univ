#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Complex2.h"

using namespace std;

Complex2 Complex2::operator+(const Complex2 &c) const
{
    return Complex2(rPart + c.rPart, iPart + c.iPart);
}

Complex2 Complex2::operator+(double r) const
{
    return Complex2(rPart + r, iPart);
}

Complex2 Complex2::operator-(const Complex2 &c) const
{
    return Complex2(rPart - c.rPart, iPart - c.iPart);
}

Complex2 Complex2::operator-(double r) const
{
    return Complex2(rPart - r, iPart);
}

Complex2 Complex2::operator*(const Complex2 &c) const
{
    return Complex2(rPart * c.rPart - iPart * c.iPart, rPart * c.iPart + iPart * c.rPart);
}

Complex2 Complex2::operator*(double r) const
{
    return Complex2(rPart * r, iPart * r);
}

Complex2 Complex2::operator/(const Complex2 &c) const
{
    double	d = c.rPart * c.rPart + c.iPart * c.iPart;
    return Complex2((rPart * c.rPart + iPart * c.iPart) / d, (iPart * c.rPart - rPart * c.iPart) / d);
}

Complex2 Complex2::operator/(double r) const
{
    return Complex2(rPart / r, iPart / r);
}

Complex2& Complex2::operator+=(const Complex2 &c)
{
    rPart += c.rPart;    iPart += c.iPart;
    return *this;
}

Complex2& Complex2::operator-=(const Complex2 &c)
{
    rPart -= c.rPart;    iPart -= c.iPart;
    return *this;
}

Complex2& Complex2::operator*=(const Complex2 &c)
{
    *this = *this * c;
    return *this;
}

Complex2& Complex2::operator/=(const Complex2 &c)
{
    *this = *this / c;
    return *this;
}

bool Complex2::operator==(const Complex2 &c) const
{
    return  rPart == c.rPart && iPart == c.iPart;
}

bool Complex2::operator!=(const Complex2 &c) const
{
    return  rPart != c.rPart || iPart != c.iPart;
}

void  Complex2::display() const
{
    cout << "(" << rPart;
    if (iPart > 0)
        cout << "+j" << iPart;
    else if (iPart < 0)
        cout << "-j" << -iPart;
    cout << ")";
}

Complex2  operator+(double r, const Complex2& c)
{
    return Complex2(r + c.rPart, c.iPart);
}

ostream&  operator<<(ostream& os, const Complex2& c)
{
    os << "(" << c.rPart;	// 실수부 출력
    if (c.iPart > 0)		// 허수부 출력
        os << "+j" << c.iPart;
    else if (c.iPart < 0)
        os << "-j" << -c.iPart;
    cout << ")";
    return os;
}
