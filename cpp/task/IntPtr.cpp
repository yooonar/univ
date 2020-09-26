#include <iostream>
using namespace std;

/*
3. IntPtr.cpp
   포인터 예제
   (가) 다음 프로그램의 ㈀~㈃에 넣을 내용을 작성하라.
   (나) 이 프로그램의 출력 결과를 구하라.
*/
int main()
{
    cout << "학번 : 202034-365428 " << endl;
    cout << "이름 : 윤아람" << endl << endl;

    int a = 10, b = 100;
    int *ptr = &a; // 포인터 ptr 을 선언한 후 a 의 주소를 넣는다
    cout << "ptr 이 가리키는 곳의 값 : " << *ptr << endl;
    *ptr = 20; // ptr이 가리키는 곳에 20을 저장
    cout << "변수 a의 값 : " << a << endl;
    ptr = &b; // ptr 이 b 를 가리키게 함
    cout << "변수 b의 값 : " << *ptr << endl;
    return 0;
}