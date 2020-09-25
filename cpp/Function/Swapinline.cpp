#include <iostream>
using namespace std;

// 두 변수의 값을 바꾸는 함수
// 인수 int &x, int &y : 값을 바꿀 변수
// 반환값 : 없음
inline void SwapValues(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a, b;
    cout << "두 수를 입력하시오 : ";
    cin >> a >> b;
    if(a < b) SwapValues(a, b); // 순서를 바꿔 a에 큰 값을 넣음
    // 일반 함수처럼 SwapValues 함수를 호출하고 돌아오는 게 아니라 9 ~ 11 라인에 있는 SwapValues 함수의 내용이 18 라인으로 들어오는 것이다.

    cout << "큰 수 = " << a << " 작은 수 = " << b << endl;
    return 0;
}