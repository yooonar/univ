/*
복사 생성자 - Copy constructor
- 같은 클래스의 객체를 복사하여 객체를 만드는 생성자
- 복사 생성자의 경우도 복사 생성자를 선언하지 않으면 묵시적으로 컴파일러가 알아서 만들어준다.
- 묵시적 복사 생성자: 객체의 데이터 멤버들을 그대로 복사해서 객체를 만들도록 묵시적으로 정의된 복사 생성자

- 묵시적인 형식의 복사 생성자가 아닌 특별한 유형의 복사 생성자가 필요한다면 스스로 복사 생성자를 정의(명시적)해주어야 한다.
  형식은 아래와 같다.

  - 명시적으로 복사 생성자를 정의하는 형식
  class ClassName {
      ...
  public:
      // ClassName(const ClassName& obj) <= 자기 자신에 해당되는 클래스 ClassName 의 객체를 받을 수 있는 매개변수(obj) 가 만들어지는데 이 매개변수를 받는 형식은 참조형으로 받아야 한다.
      // 만약 참조형이 아닌 값 호출로 받게 된다면 매개변수의 인수를 복사해야 하는데.. 복사를 한다는 이야기는 복사 생성자가 필요하다는 것이다.
      // 그런데 우리는 지금 바로 그 복사 생성자를 만드는 것이기 때문에 복사가 되도록 매개변수를 받을 수 없다.
      // 그렇기때문에 반드시 클래스에 해당되는 참조형으로 받는다.
      // 이 복사 생성자 안에서는 복사 대상인 원본 객체가 값이 변경되면 안되기 때문에 상수 매개변수로 받도록 앞에 const 를 선언해준다.
      // 이렇게 해두면 이 안에서 매개변수로 전달된 객체를 이용해 객체를 만들 값을 복사해서 생성할 수 있는 복사 생성자를 만들 수가 있다.
      ClassName(const ClassName& obj) { // 매개변수 obj
          ... // 생성되는 객체에 obj 를 복사하는 처리 
      }
  }

묵시적으로 선언된 생성자는 일반적인 데이터 멤버만 가지고 있을 때는 별 문제가 되지 않는데,
포인터를 이용해서 동적 메모리 할당으로 데이터를 가지고 있는 경우 묵시적으로 선언된 생성자만 가지고 사용했을 때는 문제가 발생할 수 있다.

- VecF 클래스 : 얕은 복사의 문제점
  벡터: 어떤 값들을 일차원적으로 쭉 나열해놓은 것.

- 벡터 객체를 만들 수 있는 VecF 클래스를 정의하고자 한다. 
  > VecF 클래스는 이 벡터를 저장하는 클래스이다. (float 형의 값을 저장할 수 있는 벡터 객체)
    이 때 이 벡터 객체는 벡터를 구성하는 데이터의 개수가 두개일 수도 있고, 세개일 수도 있고, 열개일 수도 있는 필요에 따라 데이터의 개수를 정할 수 있는 클래스이다.
    이 경우 동적 메모리 할당을 통해 메모리를 할당 받아야 한다는 것을 알 수 있다.

- VecF 객체는 저장할 수 있는 float 값의 수를 인수로 지정하여 생성되며, 저장할 값의 배열이 제공될 경우 그 값으로 초기화한다.
  > "몇 개짜리 벡터를 만들어라" 하고 "그 다음에 또 하나의 매개변수로 그 벡터의 초기화를 할 때 사용될 수 있는 값을 배열로 전달하면, 그 값을 복사해서 초기화 하겠다." 라는 것이다.

- 인수로 전달된 VecF 객체와 덧셈한 결과를 반환할 수 있으며, 객체에 저장된 벡터를 출력할 수 있다.
  > 덧셈을 할 수 있는 함수를 만들고, 데이터를 출력할 수 있게 하겠다는 것이다.

* 배열은 사실 포인터와 같은 개념이기 때문에 포인터로 받아도 된다.

메소드                      비고
VecF(int d, float* a)       생성자. d = 개수(몇 개의 데이터를 저장하게 할 것인가?), a = 배열(a 에 들어있는 내용을 d에 복사해서 객체를 만들 수 있게 하겠다.)
~VecF()                     소멸자. 생성자에서 데이터를 복사해서 가지고 있는 메모리를 동적으로 만들어주는데, 이것을 제거해주는 일을 하는 것이 소멸자이다.
VecF add(const VecF& fv)    fv 와 덧셈을 한 결과를 반환함. 이 객체에 VecF 클래스의 객체를 전달받아 더해주는 것이다. 더하면 벡터의 합이 된다.
void print()                벡터를 출력함.

속성                        비고
int n                       벡터의 크기를 저장함. 데이터의 개수를 알고 있어야 함. 데이터 개수인 n 이라고 하는 정수형 값을 데이터 멤버로 가지고 있으려고 한다.
float *arr                  벡터의 저장 공간 포인터. n개의 값을 가지고 있어야 하는데 n 이라는 것이 객체마다 다를 수 있기 때문에 배열로 선언할 수 없다.
                            그래서 float 형 포인터로 선언하여 동적으로 메모리를 필요한만큼 할당받아서 n 개의 데이터를 저장할 수 있도록 하려고 한다.
                            벡터 저장 공간에 해당되는 포인터이며 데이터는 float 형이기 때문에 "float 형 포인터로 만들겠다" 라고 선언할 수 있다.


*/

