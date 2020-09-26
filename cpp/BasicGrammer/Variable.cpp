/*
- 변수
  - 프로그램이 실행되는 동안 기억하고 있어야 하는 값들을 저장하는 메모리 영역
  - 변수에는 이름이 지정되어야함
  - _, 'a' - 'z', 'A' - 'Z'
  - 모든 변수는 사용하기 전에 미리 선언해야함


- 변수 선언 위치
  - 함수 내부: 지역 변수
  - 함수 외부: 전역 변수


- 변수 선언 형식
  1. 자료형이름(int, float, double, ...) 변수이름;
     int size;
  2. 자료형이름(int, float, double, ...) 동일자료형의다중변수선언;
     int size, price, stock;


- 변수의 초기화
  - 자판기 처음 켰을 때 항상 0원이어야 함
  1. int total = 0;
  2. int total(0);
     int x(1.5); // 1로 초기화. warning! double -> int 로 자동 형변환 
     float y = x; // 1로 초기화. float -> int 로 자동 형변환
  3. int total = {0}; // 오류: 축소 변환 float y{total};. 엄격한 형변환
     // 여기서 대입문자 = 는 생략 가능하다.
     short x{total}; // 오류: 축소 변환
     short = 16bit(2byte), int = 32bit(4byte)
     short 형식인 x 변수에 int 형식인 total을 넣으면 오류!


- 자료형 추론
  - C++ 11 부터 사용한다.
  - 변수를 초기화할 때 초기화하는 값의 자료형으로 변수의 자료형을 추론함
    Eg. auto i(10); // int i(10) 과 동일함
        10은 int 와 같은 자료형이기 때문에 10 으로 자동 변환 해준다.


- const 한정어
  - 변수의 값을 수정할 수 없게 함
  - 초기화를 통해서만 값을 정할 수 있음
    Eg. const double PI { 3.141592 }; // 원주율 정의

*/