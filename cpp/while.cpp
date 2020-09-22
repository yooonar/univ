#include <iostream>
using namespace std;

int main() {

    // for 문 버전
    // int val, total = 0;
    // for(int i=0 ; i < 10 ; i++) {
    //     cout << i << " 값을 입력해주세요 : " << endl;
    //     cin >> val;
    //     total += val;
    // }
    // cout << total << endl;

    // while 문 버전
    int val, total = 0;
    int i = 0;
    while (i < 10) {
        cout << i << " 값을 입력해주세요 : " << endl;
        cin >> val;
        total += val;
        i++;
    }
    cout << total << endl;
    return 0;
}
