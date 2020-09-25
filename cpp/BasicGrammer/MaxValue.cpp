#include <iostream>
using namespace std;

// 여러개의 데이터 중 최대값 구하기
int main() {
    int max;
    int data[10] = {10, 23, 5, 9, 22, 48, 12, 10, 55, 31};

    max = data[0]; // 기본값. data의 9번 값을 max 로 가정함
    cout << "데이터 : " << data[0]; // 0번 데이터 출력
    for ( int i = 1 ; i < 10 ; i++ ) { // 나머지 9개 데이터 비교
        cout << " " << data[i]; // i번 데이터 출력
        if(max < data[i]) max = data[i]; // i번 데이터 비교
    }
    cout << "\n\n배열의 최대값 : " << max << endl;
    return 0;
}
