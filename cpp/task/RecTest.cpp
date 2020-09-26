#include <iostream>
using namespace std;

/*
5. RecTest.cpp
   참조 활용 예제
   (가) ㈀에 넣을 문장을 작성하라.
   (나) 이 프로그램의 출력 결과를 구하라.
*/
int main()
{
    cout << "학번 : 202034-365428 " << endl;
    cout << "이름 : 윤아람" << endl << endl;

    int a = 10, b = 20;
    int &aRef = a; // a 를 참조하는 참조변수 aRef 를 선언

    cout << "a 의 값 : " << a << endl;
    cout << "aRef 가 참조하는 값 : " << aRef << endl << endl;

    aRef = 100;
    cout << "a 의 값 : " << a << endl;

    aRef = b;
    cout << "a 의 값 : " << a << endl;
    return 0;
}