#include <iostream>
using namespace std;

int main() {

    int i = 0;
    // 무조건 반복할 문장을 한 번 실행하고 조건 검색
    do {
        cout << i << "\n";
        i++;
    } while (i < 5);
    return 0;
}