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
    return 0;
}