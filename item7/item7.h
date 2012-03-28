#include <iostream>
#include <memory>
#include <new>

using namespace std;

class X {
public:
        static new_handler set_new_handler(new_handler p);
        static void* operator new(size_t size);
private:
        static new_handler currentHandler;
};


class Y {
        static void outOfMemory();
};

//정적 클래스 멤버들은 클래스 정의 바깥에 정의되어야 한다
// 정적 객체들의 디폴트 초기화를 이용할수 있기 때문.
new_handler X::currentHandler; // currentHandler를 디폴트로 0 초기화
