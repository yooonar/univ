#include <iostream>
using namespace std;

/*
동적 메모리 할당
프로그램 동작 중 기억 공간의 필요성 및 소요량을 결정하여 필요한 공간을 할당하는 것.
동적 메모리는 이름이 없어서 포인터 변수가 그 메모리를 가리키게 만들어준다.

기억공간의 생성 시점: new 연산자의 실행 시점
기억공간의 소멸 시점: delete 연산자의 실행 시점

메모리 할당 연산자
1. ptrVar = new TypeName; // new 자료형이름
2. ptrVar = new TypeName[n]; // n : 정수형 수식

메모리 반납 연산자
1. delete ptrVar;
2. delete [] ptrVar; // 배열의 사이즈는 입력하지 않는다.
*/
int main() {

    // 단일 데이터 공간의 할당 및 반환
    int *intPtr;
    intPtr = new int;
    *intPtr = 10; // intPtr 에 10을 넣는다.
    // ...
    delete intPtr; // 시스템에 동적 메모리를 반납한다.
    intPtr = nullptr; // intPtr 초기화. intPtr 은 아무것도 가리키고 있지 않다.
    /*
    nullptr : 동적 메모리 삭제 후 포인터 초기화하는 작업
    delete intPtr 를 통해 동적 메모리를 반납했지만 intPtr은 여전히 반납된 포인터를 바라보고 있다. 
    이 경우는 상당히 위험하기 때문에 nullptr 로 초기화 해준다.
    C와 기존 C++ 에서는 NULL 이라는 상수를 사용했지만, C++ 11 부터는 nullptr 이라는 직접적인 키워드를 추가했다.
    NULL 이라는 것은 0으로 되어있는데 이 값은 정수값과 포인터값이 구분이 잘 안된다.
    그렇기 때문에 C++ 11 부터 nullptr 이라는 포인터의 의미를 갖는 키워드를 추가로 정의한 것이다.
    */

    // 배열 사용 방법
    int *intPtrArray;
    intPtrArray = new int[4];
    *intPtrArray = 10; // intPtrArray[0] 번째 배열에 10을 넣는다.
    *(intPtrArray + 1) = 20; // intPtrArray[1] 번째 배열에 20을 넣는다.
    intPtrArray[2] = 30; // intPtrArray[2] 번째 배열에 30을 넣는다
    // ...
    delete [] intPtrArray; // 동적 메모리를 반납한다.
    intPtrArray = nullptr; // intPtrArray 초기화. intPtrArray 는 아무것도 가리키고 있지 않다.
    return 0;
}
