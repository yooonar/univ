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
/*
컴파일러는 위에서 아래로 순차적인 진행을 하기 때문에 함수 FahrToC 정의 부분이 FahrToC 함수를 호출하는 메인함수보다 밑에 있으면 컴파일 할 때 오류가 난다.
정의부분보다 호출부분이 위에 있으면 오류남!

만약에 밑에 위치시키고 싶은데! 오류를 안나게 하고 싶은 경우!
함수의 원형 float FahrToC(float fahr); 을 위에 저장시켜준다.

float FahrToC(float fahr); // 함수의 원형
int main()
{
    float fTemp, cTemp; // float 형태의 변수 정의

    cout << "화씨온도 : ";
    cin >> fTemp; // 화씨온도 입력받아 화씨온도 변수에 넣기

    // fTemp : 실 매개변수
    cTemp = FahrToC(fTemp); // 화씨온도 -> 섭씨온도로 변환하는 함수를 호출하여 섭씨온도 변수인 cTemp 에 넣기
    cout << "---> 섭씨온도 : " << cTemp << endl; // 섭씨온도 출력
    return 0; // 메인함수에서는 return 0; 을 생략 가능하다.
}
float FahrToC(float fahr) {
    return (fahr - 32) * 5 / 9;
}

*/