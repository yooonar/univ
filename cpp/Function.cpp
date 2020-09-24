#include <iostream>
using namespace std;

/*
- 함수
  - 필요한 작업을 수행하는 프로그램 문장들을 하나의 단위로 모아놓고 이름을 부여한 것이다.
  - 함수에 정의된 처리가 필요한 부분에서 호출하여 사용한다.
  - 매개변수를 통하여 함수에서 처리할 데이터(인수)를 전달한다.
  - 함수는 정해진 처리를 한 후 결과값을 반환할 수 있다.
  - 함수의 실행을 완료하면 호출한 곳으로 복귀한다.
  - C++ 프로그램은 함수를 기본 단위로 하여 구성된다.
  
- 함수 정의 형식
  ReturnType functionName (fParameterList) // 머리부
  { // 몸체 블록
      Type1 LocalVar1; // 지역변수 선언
      Type2 LocalVar2;
      ....
      statement1; // 처리할 작업을 수행하는 문장
      statement2;
      ....
      return returnExpression; // 결과값을 반환함
  }
  fParameterList: 인수를 받기 위한 형식 매개변수 선언
  ReturnType: 함수의 결과로 반환하는 값의 자료형
  returnExpression: 함수의 결과로 반환하는 값

- return
  - 함수를 마치고 함수를 호출하는 곳으로 복귀하는 명령
  - 함수 안의 어떤 곳이든 복귀를 위해 사용할 수 있다.
  - returnExpression 은 함수 머리부에 선언한 ReturnType 과 일치하는 자료형의 수식 또는 묵시적 형변환이 가능한 자료형의 수식을 사용한다.
  - 반환값이 없는 함수의 ReturnType 은 void 로 선언한다.
  - main 함수에서는 return 명령을 만나지 않은 상태로 함수의 끝에 도달하면 return 0; 을 실행한 것과 같다.

- 함수 호출 형식
  1. 호출만 하는 함수. 반환값 유무에 관계없이 사용 가능하다.
     functionName(aParameterList);
  2. ReturnType 이 void 가 아닌 함수에 사용할 수 있는 함수
     varName = functionName(aParameterList);
  aParameterList: 인수로 전달할 실 매개변수 나열

*/
int main() {


    return 0;
}