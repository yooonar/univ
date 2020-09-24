#include <iostream>
#include <cmath>
using namespace std;
double Round(double x, int d = 0);

int main() {
    double a;
    cout << "값 : ";
    cin >> a;

    cout << "반올림 --> " << Round(a) << endl;
    cout << "           " << Round(a, 1) << endl;
    cout << "           " << Round(a, 2) << endl;
    cout << "           " << Round(a, 3) << endl;
    return 0;
}

// 반올림 함수
// 인수 double x : 반올림 할 값
// int d : 반올림하여 남길 소수 부분의 자릿수
// return 반올림한 값(double)
double Round(double x, int d) {
    double a = x >= 0 ? 0.5 : -0.5; // 반올림 정의
    double pow10 = pow(10, d); // pow 제곱. 10의 d 제곱 12.3456 의 소수점을 123456 으로 변환
    return trunc(x * pow10 + a) / pow10; // pow10 을 x 로 곱한 다음 + a 로 0.5 또는 -0.5 로 반올림 처리를 한 후 다시 pow10 로 나누어 원래의 소수점으로 되돌려놓는다.
}