#include <iostream>
using namespace std;

/*
    포인터
    ptrVar = &var; // & : 주소 계산 연산자
    *ptrVar = value; // *ptrVar : 포인터 ptrVar 가 가리키는 곳
*/
int main() {
    int a = 10; // a : 정수형 변수
    int *ptr; // ptr : 정수가 저장되어있는 위치를 가리키는 주소를 저장하는 변수

    ptr = &a; // ptr 에 a 의 주소를 넣는다. ptr 이 a 를 가리키고 있다

    cout << "ptr 이 가리키는 값 : " << *ptr << endl; // ptr = a 의 주소, * 이 붙었으니까 그 주소의 값을 가져온다.
    *ptr = 20; // ptr 이 가리키고 있는 주소의 값을 20으로 바꿔라 = a 의 값을 20으로 바꿔라
    // 포인터를 이용해 a의 값을 간접적으로 변경할 수 있다.
    cout << "변수 a의 값 : " << a << endl;

    return 0;
}
