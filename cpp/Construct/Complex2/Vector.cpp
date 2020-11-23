#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Complex2.cpp"
using namespace std;

bool compare(Complex2 com1, Complex2 com2){
    return ((com1.real() * com1.real()) + (com1.imag() * com1.imag())) > ((com2.real() * com2.real()) + (com2.imag() * com2.imag()));
}

void print(Complex2 com) {
    cout << "rPart : " << com.real() << ", iPart : " << com.imag() << ", Calculation : " << (com.real() * com.real()) + (com.imag() * com.imag()) << endl;
}

int main(){
    srand((unsigned)time(NULL));

    vector<Complex2> iv1(5);
    cout << "벡터1에 저장된 값 : " << endl;
    for(Complex2 &com:iv1){
        int i, j;
        i = rand() % 100;
        j = rand() % 100;
        com = Complex2(i, j);
        print(com);
    }
    
    sort(iv1.begin(), iv1.end(), compare);
    cout << endl << "정렬된 벡터 1 : "<< endl;
    for (Complex2 com: iv1){
        print(com);
    }
    cout << endl;

    vector<Complex2> iv2(5);
    cout << endl << "벡터 2에 저장된 값 : " << endl;
    for(Complex2 &com: iv2){
        int i, j;
        i = rand() % 100;
        j = rand() % 100;
        com = Complex2(i, j);
        print(com);
    }
    
    sort(iv2.begin(), iv2.end(), compare);
    cout << endl << "정렬된 벡터 2 : " << endl;
    for (Complex2 com: iv2){
        print(com);
    }
    cout << endl;

    vector<Complex2> iv3(iv1.size() + iv2.size());
    merge(iv1.begin(), iv1.end(), iv2.begin(), iv2.end(), iv3.begin(), compare);
    cout << endl << "벡터 1과 벡터 2를 합병한 결과 : " << endl;
    for (Complex2 com: iv3){
        print(com);
    }
    cout << endl << endl;
}
