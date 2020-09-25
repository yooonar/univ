#include <iostream>

using namespace std;
// using std::cout;
// using std::cin;

namespace myNsp1 { int n = 10; }
namespace myNsp2 { int n = 20; }
int n = 30;

int main() {
    int n = 40;
    cout << myNsp1::n << endl;
    cout << myNsp2::n << endl;
    cout << ::n << endl;
    cout << n << endl;
    return 0;
}