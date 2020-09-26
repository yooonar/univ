#include <iostream>
using namespace std;

int main() {
    int *intPtr;
    intPtr = new int[4]; // 4개의 int 값을 저장할 메모리 할당

    *intPtr = 10;
    *(intPtr + 1) = 20;
    intPtr[2] = 30;
    intPtr[3] = 40;

    for(int *p = intPtr, i = 0 ; i < 4 ; i++ ) {
        cout << *p++ << " "; // p 가 가리키는 곳의 값을 출력한 후 p 를 다음으로 이동
        // *p++ 의 우선순위는 ++ 가 먼저, 그다음이 *
    }
    cout << endl;
    delete [] intPtr;
    intPtr = nullptr;

    return 0;
}
