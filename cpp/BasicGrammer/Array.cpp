/*
- 배열 Array
  - 동일한 자료형의 값을 여러 개 저장할 수 있는 연속적으로 할당된 공간을 묶어 하나의 이름을 갖는 변수로 만든 것이다.
  - 각각의 원소는 0번부터 시작하여 차례로 부여된 번호(첨자, 인덱스)를 이용하여 액세스 한다.
  - 배열의 차원 : 배열의 첨자 개수


- 1차원 배열의 선언
  Eg. float fArray[4];
      fArray[0]  fArray[1]  fArray[2]  fArray[3]


- 1차원 배열의 사용
  Eg. float fArray[4];
      int i=0;
      fArray[i] = 10.0f;
      cin >> fArray[1] >> fArray[2] >> fArray[3];
      cout << fArray[1] * fArray[2];


- n차원 배열
  - n-1차원 배열이 원소인 배열 
    - 2차원 배열 int Arr2D[4][3]; // 3개짜리 배열이 4개가 있다.
    행 우선 순서(row-major order)
                 →            →        → 행(row)
     ↓      Arr2D[0][0]  Arr2D[0][1]  Arr2D[0][2]
     ↓      Arr2D[1][0]  Arr2D[1][1]  Arr2D[1][2]
     ↓      Arr2D[2][0]  Arr2D[2][1]  Arr2D[2][2]
 열(colume) Arr2D[3][0]  Arr2D[3][1]  Arr2D[3][2]


- 배열의 초기화
  Eg. int a[5] = { 1, 2, 3, 4, 5 }; // ‘=’는 생략할 수 있음 
      int b[5] = { 1, 2, 3 }; // b[3]와 b[4]는 0으로 초기화됨
      int c[] = { 1, 2, 3, 4, 5 }; // 배열의 크기는 5임
      int d[2][4] = {{ 1, 2, 3, 4 }, // 2차원 배열의
                    { 5, 6, 7, 8 }}; // 초기화


*/