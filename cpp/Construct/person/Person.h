#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

// 클래스 Person 선언
class Person {
    // 이름을 저장하는 데이터 멤버
    char *name;

    // 주소를 저장하는 데이터 멤버
    char *addr;

    // public 멤버함수
    public:
        // 생성자
        Person(const char *name, const char *addr);
        ~Person();

        //  이름과 주소 출력
        void print() const;

        // 주소 변경
        void chAddr(const char *newAddr);
};
#endif