#ifndef COUNTERM_H_INCLUDED
#define COUNTERM_H_INCLUDED

/*
계수기를 나타내는 클래스
계수기 객체는 값을 0으로 지울 수 있고, 값을 1씩 증가시킬 수 있으며, 현재의 계수기 값을 알려줄 수 있다.
- 행위(메소드)
  1. void reset(): 계수기의 값을 0으로 지움
  2. void count(): 계수기의 값을 +1 증가시킴
  3. int getValue(): 계수기의 현재 값을 알려줌
- 속성
  1. int value: 계수기의 현재 값을 저장함
*/
class CounterM { // 클래스 CounterM의 선언 시작
    const int maxValue; // 계수기의 최대값
    int value; // private 데이터 멤버

    public: // public 멤버 함수
    CounterM(int mVal) : maxValue { mVal }, value { 0 } { } // 생성자 maxValue 데이터 멤버의 초기값을 mVal 로, value 데이터 멤버의 초기값을 0 으로 초기화하여 나열함
    // maxValue 는 상수 멤버로 선언(const)했기 때문에 초기화 리스트를 이용해서만 초기화가 가능하다.
    // 만약 이와 같이 CounterM(int mVal) : maxValue { mVal }, value { 0 } { maxValue = mVal; } 로 생성자 안에서 대입했다면 에러가 발생한다.(maxValue 가 상수 인자(const) 이기 때문에)
    
    void reset() // 계수기의 값을 0으로 지움
    {
        value = 0;
    }
    void count() // 계수기의 값을 1 증가시킴
    {
        value = value < maxValue ? value + 1 : 0;
    }
    int getValue() const // 계수기의 현재 값을 반환함
    {
        return value;
    }
};
#endif // COUNTERM_H_INCLUDED
