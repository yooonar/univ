#include <iostream>
#include "CCounterM.h" // 헤더 파일 인클루드
using namespace std;

int main() {
    // ...
    // 헤더에서 클래스 CCounterM의 복사 생성자를 만들지 않아도 컴파일러가 알아서 복사 생성자를 만들어 놓는다.

    CCounterM cnt4 { 99 }; // 최대값을 99 로 지정했음. 0부터 99까지 카운트 할 수 있는 객체이다.
    // 이 객체를 만드는 것은 우리가 명시적으로 선언해놓은 첫 번째 생성자(CCounterM(int maxVal) : maxValue { mVal }, value { 0 } {}) 를 가지고 만든 것이다.

    CCounterM cnt5 { cnt4 }; //  CCounterM 클래스의 객체를 가지고 CCounterM 클래스의 객체를 다시 만드는 생성자는 정의한 적이 없다.
    // 그렇지만 CCunterM 클래스에 이러한 일을 하는 복사 생성자가 컴파일러에 의해 묵시적으로 만들어진 것이다.
    // 헤더파일 CCounterM.h 에는 다음과 같은 생성자가 있는 것이다. 
    // CCounterM(const CCounterM& c) : maxValue { c.maxValue }, value { c.value } { }
    // CCounterM 클래스의 생성자인데 CCounterM 클래스 객체의 참조를 전달받는 형식으로 되어있다.
    // 그리고 이 안에서 매개변수 c의 값을 바꾸지 않도록 상수 const 로 만들어놓았다.
    // 이렇게 받아놓은 이 객체 c(const CCounterM& c), 이것이 CCounterM 클래스의 객체에 대한 참조다. 이것을 이용해 데이터 멤버를 초기화 하는 것이다.
    // 초기화 리스트에서 maxValue 는 c의 maxValue, value 는 c의 value 로 초기화 하도록 생성자를 정의했다.(그대로 복사했다.)

    CCounterM cnt6 = cnt4; // 객체를 만들면서 이렇게 이퀄( = ) 이라는 기호를 가지고 객체를 만드는 것은, 이 cnt4 라는 것을 cnt6 에 대입하라는 것이 아니라 초기화 하라는 이야기다.
    // 초기화 할때는 이런 복사 생성자가 사용된다.
    // 이 문장도 두번쨰 문장인 CCounterM cnt5 { cnt4 }; 와 동일하게 복사 생성자를 동작하게 만드는 문장이다.

    // ...
    return 0;
}