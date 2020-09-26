/*
- 포인터란?
  - 다른 변수, 구조체, 객체 등 값이 저장된 곳을 가리키는 변수

- 포인터 선언 형식
  - TypeName *ptrVar;
    - TypeName : 가리킬 값의 자료형
    - ptrVar : 포인터 변수의 이름
  Eg. int *iPtr;


- 포인터의 사용
  - 포인터가 유효한 대상을 가리키게 한 후 사용해야 함
    ptrVar = &var; // ptrVar이 var을 가리키게 함 
    *ptrVar = value; // ptrVar을 이용하여 var을 액세스
  - & : 주소 계산 연산자
  - *ptrVar : 포인터 ptrVar가 가리키는 곳
    Eg. int a; 
    int *iPtr = &a; // int *iPtr = &a; 는 int *iPtr; iPtr = &a; 와 같다.
    *iPtr = 10;
*/