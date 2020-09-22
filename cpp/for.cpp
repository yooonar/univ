#include <iostream>
using namespace std;

int main() {
    int arr[5] = {2, 3, 9, 4, 7};
    int sum = 0;
    // 범위 기반 for 루프 (c++ 11 이후)
    // for ( 원소 선언 : 데이터 집합)
    for (int a : arr) {
        sum += a;
    }
    cout << "합계 = " << sum << endl;

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int a : arr2) {
        ++a;
        // 이렇게 그냥 더하기만 하면 arr2 배열의 값은 변하지 않는다.
        // 이 경우 참조형으로 참조 기호(&)를 쓰게 되면 a가 반복되면서 arr2 를 직접 변경한다. for(int& a : arr)
    }
    for(int a : arr2) {
        cout << "arr2 의 값 : " << a << endl;
    }

    for(int& a : arr2) {
        ++a;
    }
    for(int a : arr2) {
        cout << "arr2 의 값(참조기호 넣었을 때) : " << a << endl;
    }
    return 0;

}
