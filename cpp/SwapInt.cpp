#include <iostream>
using namespace std;

void SwapValues(int &x, int &y); // 함수의 원형
int main() {
    int a, b;

    cout << "두 수를 입력하시오. : ";
    cin >> a >> b;

    if(a < b) SwapValues(a, b); // 순서를 바꿔 a에 큰 값을 넣음
    cout << "큰 수 = " << a << ", 작은 수 = " << b << endl;
    return 0;
}

// 두 변수의 값을 바꾸는 함수.
// 인수 int &x, int &y : 값을 바꿀 변수
// 반환 : 없음
void SwapValues(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}9