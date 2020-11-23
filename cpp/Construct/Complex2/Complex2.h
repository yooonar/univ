#ifndef  COMPLEX2_H_INCLUDED
#define  COMPLEX2_H_INCLUDED
#include <ostream>
using namespace std;

class  Complex2 {
    double  rPart, iPart;           // 실수부 및 허수부
public:
    // 생성자
    Complex2(double r = 0, double i = 0) : rPart(r), iPart(i) {}
    Complex2  conj()  const {
        return Complex2(rPart, -iPart);
    }
    Complex2  operator+(const Complex2 &c) const;
    Complex2  operator+(double r) const;
    Complex2  operator-(const Complex2 &c) const;
    Complex2  operator-(double r) const;
    Complex2  operator*(const Complex2 &c) const;
    Complex2  operator*(double r) const;
    Complex2  operator/(const Complex2 &c) const;
    Complex2  operator/(double r) const;
    Complex2& operator+=(const Complex2 &c);
    Complex2& operator-=(const Complex2 &c);
    Complex2& operator*=(const Complex2 &c);
    Complex2& operator/=(const Complex2 &c);
    bool      operator==(const Complex2 &c) const;
    bool      operator!=(const Complex2 &c) const;
    double    real() const { return rPart; }
    double    imag() const { return iPart; }
    void  display() const;      // 복소수 값을 출력
    friend  Complex2  operator+(double r, const Complex2& c);
    friend  ostream& operator<<(ostream& os, const Complex2& c);
};
#endif
