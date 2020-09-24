#include <iostream>
using namespace std;

struct SalesRec {
    char pID[10]; // 10 byte
    int dYear, dMonth, dDate; // 4 + 4 + 4 = 12 byte
    char deliverAddr[40]; // 40 byte
    // 총 62 byte 지만 값이 64byte 가 다 채워지지 않은 경우 62 byte + 빈 2 byte 로 64 byte 로 전달될 수 있다.
    // 효율성을 위해 2 byte 가 비워진 코드로 들어가게 된다.
};

void PrSalesRec(const SalesRec &srec); // 호출할 때마다 64byte 를 복사함

int main() {
    SalesRec s = {"C25TV001", 2019, 11, 15, "서울시 종로구 대학로86"};
    PrSalesRec(s);
    return 0;
}

void PrSalesRec(const SalesRec &srec) { // srec 은 상수 인수
    cout << "품목 코드 : " << srec.pID << endl;
    cout << "배달 일자 : " << srec.dYear << "년 ";
    cout << srec.dMonth << "월 ";
    cout << srec.dDate << "일" << endl;
    cout << "배달 주소 : " << srec.deliverAddr << endl;
}