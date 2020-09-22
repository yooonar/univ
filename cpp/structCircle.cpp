#include <iostream>
#include <cmath> // sqrt 함수
using namespace std;
// 구조체 끝은 반드시 세미콜론(;)을 붙여줘야한다.

const double PI = 3.141593;

// 2차원 좌표 구조체(자료형) 만들기
// cordinate2d 2차원 좌표를 의미하는 C2dType 구조체
struct C2dType {
    double x, y;
};

// 원 구조체(자료형) 만들기
struct CircleType {
    C2dType center; // C2d 타입의 중심좌표
    double radius; // 반지름(반경)
};

// 원의 면적을 구하는 함수 만들기
double circleArea(CircleType c) {
    return c.radius * c.radius * PI; // 반지름 * 반지름 * 3.14
}

// 두 원(c1, c2)의 중첩 여부를 판별하는 함수 만들기
bool chkOverlap(CircleType c1, CircleType c2) {
    double dx = c1.center.x - c2.center.x;
    double dy = c1.center.y - c2.center.y;

    // 피타고라스 정리에 의해 제곱 구하기
    double dCntr = sqrt(dx * dx + dy * dy); // sqrt 함수: 제곱근(루트)

    // dCntr < c1.radius + c2.radius; // 두 원이 중첩됨
    // dCntr >= c1.radius + c2.radius; // 두 원이 중첩되지 않음
    return dCntr < c1.radius + c2.radius;
}

void dispCircle(CircleType c) {
    cout << " 중심 : (" << c.center.x << ", " << c.center.y << ")";
    cout << " 반경 : " << c.radius << endl;
}

int main() {
    CircleType c1 = {{0, 0}, 10}; // 중심 (0, 0) 반경 10 으로 초기화
    CircleType c2 = {{30, 10}, 5}; // 중심 (30, 10) 반경 5 로 초기화

    cout << "원 1" << endl;
    dispCircle(c1);
    cout << " 원 1의 면적 : " << circleArea(c1) << endl;

    cout << "원 2" << endl;
    dispCircle(c2);
    cout << " 원 2의 면적 : " << circleArea(c2) << endl;

    // 두 원의 중첩 여부 출력
    if(chkOverlap(c1, c2))
        cout << "\n두 원은 중첩됩니다." << endl;
    else 
        cout << "\n두 원은 중첩되지 않습니다." << endl;
    return 0;
}
