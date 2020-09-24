#include <iostream>
using namespace std;

/*
화씨 온도를 섭씨온도로 변환하는 함수 만들기
매개변수 float fahr: 화씨온도
반환값 float 섭씨온도
fahr : 형식매개변수
*/
float FahrToC(float fahr) {
    return (fahr - 32) * 5 / 9;
}

int main() {
    float fTemp, cTemp; // float 형태의 변수 정의

    cout << "화씨온도 : ";
    cin >> fTemp; // 화씨온도 입력받아 화씨온도 변수에 넣기

    // fTemp : 실 매개변수
    cTemp = FahrToC(fTemp); // 화씨온도 -> 섭씨온도로 변환하는 함수를 호출하여 섭씨온도 변수인 cTemp 에 넣기
    cout << "---> 섭씨온도 : " << cTemp << endl; // 섭씨온도 출력
    return 0; // 메인함수에서는 return 0; 을 생략 가능하다.
}