#ifndef M_VEC_F_INCLUDED
#define M_VEC_F_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

class MVecF {
    int n;
    float *arr;
public:
    // ...

    // 복사 생성자
    MVecF(const MVecF& fv) : n { fv.n } {
        arr = new float[n];
        // arr { fv.arr } : 복사 생성자에서는 new 를 통해 arr 을 생성한다. 메모리를 새로 만들어 fv 의 arr 이 가리키는 것과 다름
        memcpy(arr, fv.arr, sizeof(float) * n);
    }

    // 이동 생성자
    MVecF(MVecF&& fv) : n { fv.n }, arr { fv.arr } {
    // MVecF&& fv : MVecF 클래스의 r-value 참조로 fv 를 받고 있다.
    // arr { fv.arr } : 이동 생성자에서는 새로 할당받는 게 아니라 fv 에 있는 arr을 그대로 복사한다. 메모리를 새로 만들지 않고 fv 의 arr 이 가리키고 있는 것을 똑같이 가리킴
    // 값을 제공하는 이 객체를 이동시키고 나서 객체가 없어질 때를 고려해 nullptr, 0 처리를 꼭 해주어야 한다.

        fv.arr = nullptr;
        // fv 의 arr을 이동했다는 것은 fv 의 arr 내용을 빼앗겼다는 것이다. 그렇기때문에 그 메모리를 가리키고 있던 포인터에 nullptr 을 넣어준다.

        fv.n = 0;
        // 메모리를 지웠으므로 데이터의 크기 또한 0으로 세팅해준다.

        // fv 는 아무것도 가지고 있지 않은 상태로 만들어졌기 때문에 곧 없어지게 될 것이다. 없어질 땐 소멸자가 동작한다.
    }

    // 소멸자
    ~MVecF() {
        delete[] arr;
        // arr 에 nullptr 을 넣어주었기 때문에 delete 할 때 arr 에 nullptr 이 들어있다.
        // delete 연산자는 포인터 값이 nullptr 이 때는 아무런 처리를 하지 않고 그냥 return 한다(그냥 빠져나온다).
    }
};
#endif // M_VEC_F_INCLUDED