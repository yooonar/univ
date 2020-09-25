#include <iostream>
using namespace std;

struct TimeRec {
    int hours;
    int minutes;
};

// 시간을 더하는 함수
// 인수: TimeRec &t1 : 누계할 시간
//       const TimeRec &t2 : 더할 시간
// 반환값: 없음
void AddTime(TimeRec &t1, const TimeRec &t2)
{
    t1.minutes += t2.minutes;
    t1.hours += t2.hours + t1.minutes / 60;
    t1.minutes %= 60;
}

// 시간을 더하는 함수
// 인수: TimeRec &t : 누계할 시간
//       int minutes : 더할 분 단위의 시간
// 반환값: 없음
void AddTime(TimeRec &t, int minutes)
{
    t.minutes += minutes;
    t.hours += t.minutes / 60;
    t.minutes %= 60;
}

int main()
{
    TimeRec tRec1 = {2, 30};
    TimeRec tRec2 = {1, 45};

    cout << tRec1.hours << " 시간 " << tRec1.minutes << " 분 + ";
    // 2 시간 30 분 + 
    cout << tRec2.hours << " 시간 " << tRec2.minutes << " 분 = ";
    // 1 시간 45 분 = 
    AddTime(tRec1, tRec2);
    cout << tRec1.hours << " 시간 " << tRec1.minutes << " 분" << endl;
    // 4 시간 15 분
    // output: 2 시간 30 분 + 1 시간 45 분 = 4 시간 15 분

    cout << tRec1.hours << " 시간 " << tRec1.minutes << " 분 + ";
    // 4 시간 15 분 + 
    cout << "135분 = ";
    AddTime(tRec1, 135);
    // 135분 = 
    cout << tRec1.hours << " 시간 " << tRec1.minutes << " 분" << endl;
    // 6 시간 30 분
    // output: 4 시간 15 분 + 135분 = 6 시간 30 분

    return 0;
}
