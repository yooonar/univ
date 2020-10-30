#ifndef CCOUNTERM_H_INCLUDED
#define CCOUNTERM_H_INCLUDED

class CCounterM {
    const int maxValue;
    int value;
public:

    // 복사 생성자도 명시적으로 선언하지 않는다면 컴파일러가 자동적으로 복사 생성자를 하나 만들어놓는다.
    // 객체의 멤버들을 그대로 복사하는 묵시적인 복사 생성자가 있는 것이다.
    // CCounterM 클래스는 생성자만 선언해놓고 복사 생성자라는 것은 선언하지 않았다.
    CCounterM(int mVal) : maxValue { mVal }, value { 0 } { }

    void reset() // 계수기의 값을 0으로 지움
    {
        value = 0;
    }
    void count() // 계수기의 값을 1 증가시킴
    {
        value = value < maxValue ? value + 1 : 0;
    }
    int getValue() const // 계수기의 현재 값을 반환함
    {
        return value;
    }
    // ...
};
#endif // CCOUNTERM_H_INCLUDED