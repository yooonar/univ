#include <iostream>
using namespace std;

int main() {
    // l-value 참조 변수의 사용 예
    int a = 10, b = 20; // a, b : 일반 정수형 변수 선언
    int &aRef = a; // aRef 정수형 참조 변수: a를 참조하여 초기화
    cout << "aRef : " << aRef << endl; // a == aRef. a 를 출력하는 것과 같다.
    // output: aRef : 10

    aRef = 100; // aRef 는 a 를 참조하고 있기 때문에 a = 100 과 같다.
    cout << "aRef : " << aRef << endl; // 100 출력
    // output: aRef : 100

    aRef = b; // a = b 와 같다.
    cout << "aRef : " << aRef << endl; // 20 출력
    // output: aRef : 20

    // 위 구문을 포인터를 사용해서 만든다면?
    int c = 10, d = 20;
    int *cPtr = &c;
    cout << "cPtr : " << *cPtr << endl;
    // output: cPtr : 10

    *cPtr = 100;
    cout << "cPtr : " << *cPtr << endl;
    // output: cPtr : 100

    *cPtr = d;
    cout << "cPtr : " << *cPtr << endl;
    // output: cPtr : 20


    // const 참조 : 참조를 이용하여 참조 대상의 값을 바꿀 수 없음. 읽을 때만 사용 가능함
    int x = { 10 };
    const int &xRef = x; // const 상수 참조
    cout << "xRef : " << xRef << endl; // x 의 값을 읽어 출력함
    // xRef += 10; // const 참조로 값을 수정할 수 없음
    // Error!!!! error: cannot assign to variable 'xRef' with const-qualified type 'const int &'
    // cout << "xRef : " << xRef << endl;
    return 0;
}