#include <iostream>
using namespace std;

/*
4. DAlloc.cpp
   동적 메모리 할당 예제
   (가) 다음 프로그램의 ㈀, ㈁, ㈂에 넣을 문장을 작성하라.
   (나) 이 프로그램의 출력 결과를 구하라.
*/
int main()
{
    cout << "학번 : 202034-365428 " << endl;
    cout << "이름 : 윤아람" << endl << endl;

    int *intPtr;
    intPtr = new int[4]; // 4개의 int 값을 저장할 메모리 할당
    *intPtr = 10;
    *(intPtr + 1) = 20;
    intPtr[2] = 30;
    intPtr[3] = 40;

    for( int *p = intPtr, i = 0 ; i < 4 ; i++ ) {
        cout << *p++ << " "; // p가 가리키는 곳의 값을 출력한 후 p를 다음으로 이동
    }
    cout << endl;
    delete [] intPtr; // ㈀ 에서 할당한 메모리 반환
    intPtr = nullptr;

    return 0;
}