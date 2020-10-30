/*
- 이동 생성자

아래는 복사 생성자 예문에서 본 VecF 클래스이다.
생성자를 두 개 만들어 일반적인 객체를 만드는 생성자1과 객체를 복사해서 만드는 생성자2를 만들었다.
그리고 벡터의 합을 구하는 add() 함수를 만들었다.
add() 함수 안에서는 새로운 객체(tmp) 를 만들어 자기 자신의 값(arr)과 fv 라고 하는 VecF 클래스의 객체를 참조로 받은 값(fv.arr)을 더해 반환한다.
데이터를 복사하는 경우 어쩔 수 없이 100이면 100, 1000이면 1000을 작성해주어야 한다.

- 파일명: VecF.h
class VecF {
    VecF(int d, float* a = nullptr) { } // 생성자1
    VecF(const VecF& fv) : n { fv.n } { // 생성자2
        arr = new float[n];
        memcpy(arr, fv.arr, sizeof(float) * n);
    }
    ~VecF() { }
    VecF add(const VecF& fv) const {
        VecF tmp(n); // 벡터의 덧셈 결과를 저장할 임시 객체
        for(int i = 0 ; i < n ; i++) {
            tmp.arr[i] = arr[i] + fv.arr[i];
        }
        return tmp; // 덧셈 결과를 반환
    }
};

- 파일명: VFMain1.cpp
int main() {
    float a[3] = { 1, 2, 3 };
    float b[3] = { 2, 4, 6 };
    VecF v1(3, a); // 3개의 데이터를 저장하고, 초기값은 a 이다.
    VecF v2(3, b); // 3개의 데이터를 저장하고, 초기값은 b 이다.

    VecF v3(v1.add(v2)); // v1 의 add() 멤버 함수를 통해 v2 의 내용이 v1 에 더해진다.
    // 이 때 더해진 결과가 tmp 라는 곳에 들어가고, 이 값을 return 하게 되면 그 결과값이 v3 으로 온다.
    // v3 생성자의 매개변수로 v1.add(v2) 객체를 넣는다. 이 때 복사 생성자(생성자2)가 동작한다.
    // 이 복사 생성자가 동작하고나면 반환된 객체는 v3 에 복사한다음 제거된다.
    // 데이터를 복사한다는 것은 그 내용을 똑같이 복사하기 위해 v3 에 새 메모리를 할당하고 <= new
    // 그 다음 memcpy 명령어로 복사하는 두 연산이 결합된다.

    // 이렇게 데이터를 복사하는 것은 많은 시간을 소비하게 되지만 어쩔 수 없다.
}

========================================================================================

그렇지만 다시 생각해보면 tmp 에 해당하는 값을 return 했을 때 return 되는 객체를 v3 에 복사하고나면 더이상 필요 없어져 삭제되는 객체가 된다.
제거되는 객체의 내용을 그대로 복사하지 않고 이동하는 것이 훨씬 더 효율적일 수 있다.
복사한다는 것은 데이터를 하나하나 그대로 카피해야하지만, 이동하는 것은 포인터 값만 바꿔주면 되는 것이다.
이 때 r-value 참조를 이용한 이동 생성자로 포인터 값만 변경한다면 메모리를 가리키는 대상이 바뀌는 것일 뿐 복사가 이루어지지 않기 때문에 훨씬 효율적으로 동작할 수 있다.

- l-value(left value), r-value(right value)
  - c++ 11 이 나오면서 r-value 참조 개념이 새롭게 등장했다.
  - a           =    b + 10;
    l-value          r-value
    대입 명령. b + 10의 내용을 a 에 저장해라. 
    l-value = a. 대입 연산자의 왼쪽에 있는 것. 저장할 공간이 필요하므로 어떠한 실체가 있으면 그것을 l-value 라 부른다.
    r-value = b + 10. 대입 연산자의 오른쪽에 있는 것.

  - l-value 참조를 할 때는 &  기호로 선언한다.
  - r-value 참조를 할 때는 && 기호로 선언한다.

  - l-value, r-value 참조의 예
    VecF v1(3), v2(3);
    VecF& vLRef = v1; // l-value 참조로 l-value 를 참조함. v1은 실체가 있다. 3개의 float 값 벡터를 저장할 수 있는 객체다.
    int& a = 10; // 오류! l-value 참조로 r-value 를 참조할 수 없음. 10 이라는 것은 prvalue(pure r-value) 이다.
    const int& b = 20; // 상수 l-value 참조로는 r-value 를 참조할 수 있음. 앞에 상수 const 를 선언해주었기 때문에 가능하다.
    int&& c = 30; // r-value 는 r-value 참조로 참조할 수 있음
    VecF&& vRRef1 = v1.add(v2); // 함수의 반환 객체는 r-value 임
    VecF&& vRRef2 = v2; // 오류! r-value 참조로 l-value 를 참조할 수 없음

- 이동 생성자 : move constructor
  - r-value 참조로 전달된 같은 클래스의 객체의 내용을 이동하여 객체를 만드는 생성자
  - 이동 생성자의 선언 형식
    class ClassName {
        ....
    public:
        // 이동생성자. 클래스 이름과 같은 이름을 사용했고, 매개변수를 받는데 ClassName에 해당되는 동일한 클래스의 객체를 r-value 참조로 받고 있다.
        ClassName(ClassName&& obj) {
            ... // 생성되는 객체에 obj 의 내용을 이동하는 처리
        }
    }
*/
