#include <iostream>
using namespace std;

/*
- 참조(reference)
  어떠한 대상을 가리키는 값(포인터와 유사함)
  참조 변수는 참조 대상의 별명처럼 사용할 수 있다.
  참조는 반드시 초기화를 통해서만 대상이 지정되어야 한다. (Eg. TypeName &refVar = varName;)
  C++ 11 이전버전은 l-value 참조를 사용했으며, C++ 11 부터 l-value 참조와 r-value 참조로 나뉜다.

- l-Value 참조와 r-Value 참조
  Eg. x = y;
    l-value 참조: 왼쪽에 있는 x를 뜻한다. y를 저장해야하기 때문에 메모리가 필요하다. 실체가 있는 대상(l-Value) 에 대한 참조
    r-value 참조: 오른쪽에 있는 y를 뜻한다. y는 값을 제공만 하기 때문에 메모리가 필요없다.

- l-value 참조
  - l-value 변수의 선언 형식
    참조할 변수 이름 앞에 & 을 붙여 l-value 참조 변수를 만들어준다. (초기화)
    Eg. TypeName &refVar = varName;
        -> TypeName: 참조 대상의 자료형
        -> refVar: 참조 변수의 이름
        -> varName: 참조 대상

- r-value 참조
  사용한 후에는 그 값을 더 이상 가지고 있을 필요가 없는 대상을 참조하는 것이다. 임시 변수와 같다고 생각하면 된다.
  - r-value 참조의 용도: 객체의 값을 다른 객체로 이동시킬 때 사용한다.

- 참조 변수가 포인터와 다른 점
  1. 참조 변수: 참조 변수를 이용하여 값을 읽거나 저장할 때 일반 변수를 사용하는 형식과 동일하다.
     포인터: 일반 변수처럼 사용 불가능하다. 반드시 *포인터이름 으로 사용해야한다.

  2. 참조 변수: 초기화를 통해 반드시 어떤 대상을 참조해야 한다.(포인터보다 안전)
                아무것도 참조하지 않는 상황은 발생하지 않는다.
     포인터: 초기화를 일부러 하지 않으면 초기화 되지 않은 상태로 변수가 만들어진다. (아무것도 가리키지 않은 상황도 발생 가능함)

  3. 참조 변수: 초기화를 통해 지정된 참조 대상을 바꿀 수 없어 참조의 유효기간동안 하나의 대상만 참조할 수 있다.
     포인터: 참조 대상을 언제든지 바꿀 수 있다.
             물론 참조 대상을 바꿀 수 없게 만드는 상수 포인터를 만들 수도 있지만 일반적인 포인터는 그 대상을 마음대로 변경할 수 있다.
*/
int main() {
    // l-value 참조 변수의 사용 예
    int a = 10, b = 20; // a, b : 일반 정수형 변수 선언
    int &aRef = a; // aRef 정수형 참조 변수: a를 참조하여 초기화
    cout << "aRef : " << aRef << endl; // a == aRef. a 를 출력하는 것과 같다.
    // output: aRef : 10

    aRef = 100; // aRef 는 a 를 참조하고 있기 때문에 a = 100 과 같다.
    cout << "aRef : " << aRef << endl; // 100 출력
    // output: aRef : 100

    aRef = b; // a = b 와 같다.
    cout << "aRef : " << aRef << endl; // 20 출력
    // output: aRef : 20

    // 위 구문을 포인터를 사용해서 만든다면?
    int c = 10, d = 20;
    int *cPtr = &c;
    cout << "cPtr : " << *cPtr << endl;
    // output: cPtr : 10

    *cPtr = 100;
    cout << "cPtr : " << *cPtr << endl;
    // output: cPtr : 100

    *cPtr = d;
    cout << "cPtr : " << *cPtr << endl;
    // output: cPtr : 20


    // const 참조 : 참조를 이용하여 참조 대상의 값을 바꿀 수 없음. 읽을 때만 사용 가능함
    int x = { 10 };
    const int &xRef = x; // const 상수 참조
    cout << "xRef : " << xRef << endl; // x 의 값을 읽어 출력함
    // xRef += 10; // const 참조로 값을 수정할 수 없음
    // Error!!!! error: cannot assign to variable 'xRef' with const-qualified type 'const int &'
    // cout << "xRef : " << xRef << endl;
    return 0;
}