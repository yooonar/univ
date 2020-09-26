#include <iostream>
using namespace std;

/*
2. MaxValue.cpp
   10개의 값이 저장된 배열에서 최댓값 구하기
   다음 프로그램의 ㈀~㈃에 넣을 내용을 작성하라.
*/
int main()
{
    cout << "학번 : 202034-365428 " << endl;
    cout << "이름 : 윤아람" << endl << endl;

    int data[10] = { 10, 23, 5, 9, 22, 48, 12, 10, 55, 31 };
    int max{ data[0] }; // data의 첫번째 데이터를 max 로 가정함
    cout << "데이터 : " << data[0]; // 0번 데이터 출력
    for( int i = 1 ; i < 10 ; i++ ) { // 나머지 9개의 데이터 비교
        cout << " " << data[i]; // i 번 데이터 출력
        if(max < data[i]) { // i 번 데이터가 max 보다 크면? 비교
            max = data[i]; // max 를 i 번 데이터로 바꿈
        }
    }
    cout << endl << endl;
    cout << "배열의 최댓값 : " << max << endl;
    return 0;
}
