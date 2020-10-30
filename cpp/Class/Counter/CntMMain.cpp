#include <iostream>
#include "CounterM.h" // 헤더 파일 include
using namespace std;

int main()
{
    CounterM cnt(9); // Counter 객체의 정의

    cout << "계수기의 현재 값 : " << cnt.getValue() << endl;

    for( int i = 0 ; i < 12 ; i++ ) {
        cnt.count(); // 계수기를 1  증가시킴
        cout << "계수기의 현재 값 : " << cnt.getValue() << endl;
    }

    // CounterM cntMArr1[3]; // 에러. 매개변수를 전달해주어야 하기 때문에 객체 배열을 만들 수 없다.
    CounterM cntMArr2[3] = { CounterM(9), CounterM(99), CounterM(999) }; // 정상. CounterM(9) ( <= 최대값이 9인 CounterM 클래스의 객체) 가 cntMArr2[0] ( <= cntMArr 배열의 0번 객체) 의 초기값으로 들어간다.
    // CounterM *pt = new CounterM[10]; // 에러

    return 0;
}