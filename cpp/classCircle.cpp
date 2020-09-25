#include <iostream>
#include <cmath>
using namespace std;

/*
클래스와 구조체
C언어에서의 구조체는 데이터만 표현하지만,
C++ 언어에서의 클래스는 관련된 데이터와 함수를 하나의 단위로 묶어서 클래스로 표현한다.
*/
const double PI = 3.141593;

// 2차원 좌표 구조체
struct C2dType {
    double x, y;
};

// 원 클래스
class CircleClass {
    // private 가시성
    C2dType center; // 중심 좌표
    double radius; // 반지름

    // public 가시성
    public:
    // 중심 (cx, cy) 반지름 r 로 원을 초기화
    void init(double cx, double cy, double r) {
        center.x = cx;
        center.y = cy;
        radius = r;
    }

    // 원의 면적 계산
    double area() const {
        return radius * radius * PI;
    }

    bool chkOverlap(const CircleClass& c) const {
        double dx = center.x - c.center.x;
        double dy = center.y - c.center.y;
        double dCntr = sqrt(dx * dx + dy * dy);
        return dCntr < radius + c.radius;
    }

    // 원 객체의 정보 디스플레이
    void display() const {
        cout << " 중심 : (" << center.x << ", " << center.y << ")";
        cout << " 반경 : " << radius << endl;
    }
};

int main() {
    CircleClass c1, c2;
    c1.init(0, 0, 10); // 중심(0, 0) 반지름 10 으로 초기화
    c2.init(30, 10, 5); // 중심(30, 10) 반지름 5 로 초기화

    cout << "원1" << endl;
    c1.display();
    cout << "원1의 면적 : " << c1.area() << endl;
    cout << "원2" << endl;
    c2.display();
    cout << "원 2의 면적 : " << c2.area() << endl;

    // 두 원의 중첩 여부 출력
    if(c1.chkOverlap(c2))
        cout << "\n두 원은 중첩됩니다." << endl;
    else
        cout << "\n두 원은 중첩되지 않습니다." << endl;
    return 0;
}