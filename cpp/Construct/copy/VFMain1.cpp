#include <iostream>
using namespace std;
#include "VecF.h" // VecF 클래스의 선언문이 들어있는 헤더 파일을 인클루드

int main() {
    float a[3] = { 1, 2, 3 };
    VecF v1(3, a); // 1, 2, 3 을 저장하는 벡터. a 배열에 들어있는 값을 이 벡터의 초기값으로 제시함
    // v1 객체는 1, 2, 3 이라는 값이 저장되어 있는 상태로 만들어진다.
    // v1은 VecF 클래스의 값에 n = 3, arr = [1, 2, 3] 으로 저장되어 있는 것 

    VecF v2(v1); // v1 을 복사하여 v2 를 만듦. 복사 생성자가 동작한다.
    /*
    1. 얕은 복사 : shallow copy
        하지만 VecF 클래스에는 별도의 복사 생성자를 만들지 않았기 때문에 클래스가 만들어놓은 묵시적인 복사 생성자가 동작한다.
        v2는 VecF 클래스의 값에 n = 3, arr = [1, 2, 3] 으로 저장되어 있는 것(v1 과 동일함) 포인터도 v1 과 똑같은 메모리를 바라본다.
        이와 같은 복사를 얕은 복사(shallow copy) 라고 한다.

        복사를 한다는 것은 원래 원본이 있고 사본이 있어서 완전 별개가 되어야 하는데 지금은 원본의 메모리 내용이 사본에도 공유되고 있는 것이다.
        그래서 이 두개의 객체는 겉보기에는 별개의 객체같지만 공유하고 있는 메모리의 부분이 있어서 사실은 완벽하게 분리된 별개의 객체가 아닌 상태이다.
        이것을 얕은 복사 shallow copy (피상적인 복사)라고 한다. 피상적으로 복사해놓은, 완전한 복사가 아닌 복사를 흉내낸 정도밖에 안되는 것이다.
    */

   /*
    2. 깊은 복사 : deep copy
        심층복사, 완전복사 라고도 한다.
        명시적 복사 생성자를 만들어준 경우엔 메모리를 새로 할당 받아 데이터를 복사하기 때문에 v2 는 새로운 메모리를 갖게 된다.
   */

    v1.print();
    // output: [ 1 2 3 ]

    cout << endl;

    v2.print();
    // output: [ 1 2 3 ]

    cout << endl;
    return 0;
    // return 0 을 실행하고 나면
    // v1, v2 객체들이 메인 함수가 끝나면서 자동적으로 소멸자가 동작한다.
    /*
    1. 얕은 복사 : shallow copy
        먼저 v1 객체의 소멸자가 동작을 했다고 하면, v1 객체의 소멸자에서 arr 이 가리키는 메모리를 시스템에 반환하는 delete[] arr; 명령어를 실행해 arr 이 가리키는 메모리를 시스템에 반납한다.
        arr 이 가리키는 메모리는 시스템에 반납했기 때문에 더이상 프로그램이 가지고 있는 메모리가 아니다. (함부로 건드릴 수 없는 상태가 됨)
        그러나 v2 객체의 소멸자가 동작하면서 delete[] arr; 을 실행해 arr 을 반납하는 명령어를 다시 실행한다.
        이미 arr 메모리는 프로그램에서 가지고 있는 메모리가 아니기 때문에 delete 명령어를 쓰면 없는 메모리를 액세스한 결과가 되어 에러가 발생하게 된다.
        사용 권한이 없는 메모리를 프로그램에서 임의로 사용하기 때문에 큰 오류가 발생할 수 있다. 비정상적으로 프로그램이 종료될 수 있다.

        이런 오류를 발생시키지 않기 위해서는 얕은 복사가 아닌 두 개의 객체가 완전히 별개로 분리되도록 완전한 복사를 사용해야한다.
    */
   /*
    2. 깊은 복사 : deep copy
        v1 에 대해 먼저 소멸자가 동작을 하며, delete 명령어를 실행해 arr 이 가리키는 메모리를 시스템에 반납한다.
        이후 v2 에 대한 소멸자가 동작하는데 이 때 delete 는 자기 자신의 메모리를 delete 시키기 때문에 문제 없이 반납된다.
   */
}