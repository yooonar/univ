#include <iostream>
#include <cstring> // memcpy 를 사용하기 위해 cstring 을 인클루드
using namespace std;

class VecF {
    int n; // 데이터멤버. 가시성 지시어가 선언되지 않았기 때문에 private 멤버이다. 이 클래스의 멤버 함수 안에서만 자유롭게 사용할 수 있고, 외부에서는 사용할 수 없다.
    float *arr; // 데이터멤버. 가시성 지시어가 선언되지 않았기 때문에 private 멤버이다. 이 클래스의 멤버 함수 안에서만 자유롭게 사용할 수 있고, 외부에서는 사용할 수 없다.

public: // publid 이라는 가시성이 지시됨. 이제부터 나열되는 멤버들은 외부에서도 자유롭게 사용할 수 있다.
    VecF(int d, const float* a = nullptr) : n { d } { // VecF 클래스의 생성자. 클래스 이름과 동일하고 매개변수는 두 개를 받는다.
    // int d <= 정수형 d
    // const float* a = nullptr <= float 형 포인터 a. 이 때 a 에는 nullptr 이라는 디폴트 인수를 지정해주었다. 그래서 a 인수를 생략하게 되면 nullptr 이라는 데이터가 전달될 것이다.
    // n { d } <= d 가 데이터의 개수이므로, n 에 d 의 값을 넣어 초기화를 해준다. (초기화 리스트에 넣어 초기화를 해줌)

        arr = new float[d]; // arr 에 메모리를 할당해주어야 한다. 이것은 초기화 리스트에서 완성할 수 없기 때문에 body 안에서 실행한다.
        // arr 에 new 라는 연산자로 float 형 데이터를 d 개 할당받도록 했다.
        // d 개의 float 형 배열을 arr 이라는 포인터가 가리키개 했다.

        if (a) memcpy(arr, a, sizeof(float) * n); // a 의 값이 nullptr 인 경우 초기화를 해줄 필요가 없다.
        // 그래서 그 때는 초기화하지 않고 nullptr이 아닐 때만 값을 복사하기 위해 if 문으로 작성
        // a라는 것은 포인터의 값, nullptr 이라는 값은 0(false, 거짓)을 의미.
        // memcpy 함수를 이용해 메모리를 복사한다.
        // memcpy(목적지, a가 가리키고 있는 값, 얼마(바이트)만큼 복사해라)
        // a 가 가리키고 있는 곳의 값을 arr이 가리키고 있는 값에 복사해라. 바이트 수는 데이터의 개수를 n 개를 넣어두었으니 n 또는 d 를 넣어도 된다.
        // sizeof(float) <= float이라는 데이터를 저장하 기 위한 메모리의 바이트 수. float 은 4바이트. 즉, 4 * n 한 값이 전체 복사할 바이트 수가 된다. 이만큼을 복사해라.
    }

    // 완전한 복사를 만들기 위한 새로운 복사 생성자를 만듦
    VecF(const VecF& fv ) : n { fv.n } { // 복사 생성자이니까 같은 클래스의 객체를 참조받는 생성자를 만든다.
        arr = new float[n];
        memcpy(arr, fv.arr, sizeof(float) * n);
    }

    // 소멸자
    ~VecF() {
        delete[] arr; // arr 이 가리키고 있는 메모리를 반납. 배열로 할당 받았기 때문에 delete[] 로 반환하였다.
    }

// 일반적인 생성자와 소멸자만 만들었을뿐 복사 생성자는 만들지 않았다. 따라서 이 경우 묵시적인 복사 생성자가 생성되었다.

    // add 멤버 함수
    VecF add(const VecF& fv) const { // const VecF& fv <= VecF 클래스의 매개변수인 fv 를 참조형( & ) 으로 받는다. 그리고 fv의 값을 수정할 필요가 없기 때문에 상수 const 매개변수로 선언하였다.
    // 뒤에 나오는 const <= 이 함수 자체가 객체 자기 자신의 값을 바꾸지 않기 때문에 const 로 선언하였다.

        VecF tmp(n); // 벡터의 덧셈 결과를 저장할 임시 객체
        // 계산된 결과를 새로운 객체를 만들어 반환한다. 그것을 위해 VecF 클래스의 객체 tmp 를 만든다.
        // 데이터 개수 = n개. n 개의 데이터를 저장할 수 있는 tmp 라는 VecF 객체를 하나 만들었다.
        // 여기서 두번째 매개변수 a 가 생략되었기 때문에 nullptr 로 전달된다.
        // 이것은 메모리만 만들고 초기화하지 않은 상태로 객체가 만들어진 것이다.
        // 이 값은 덧셈을 해서 그 값을 넣기만 하면 되는 것이기 때문에 굳이 초기화를 할 필요가 없다.

        for (int i = 0 ; i < n ; i++) { // 정수형 변수 i 를 0부터 n 보다 작을 때까지 1씩 증가시키며 반복. 0부터 n-1 개까지 전체 n개가 된다.
            tmp.arr[i] = arr[i] + fv.arr[i]; // arr[i] <= i 번째 데이터. fv의 arr[i] <= fv에 속해있는 arr 의 i 번째 값. 이 두 값을 더해 임시로 만든 tmp 객체의 arr[i] 로 저장한다.
        }
        return tmp; // 덧셈 결과를 반환. 덧셈한 결과가 함수의 return value 로 호출한 곳으로 되돌아간다.
    }
    // print 함수
    void print() const { // 내용만을 출력하면 되기 때문에 상수 const 멤버 함수로 만들었다.
        cout << "[ ";
        for (int i = 0 ; i < n ; i++ ) {
            cout << arr[i] << " ";
        }
        cout << "]";
    }
};