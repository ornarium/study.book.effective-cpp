#ifndef _ITEM7_GENERIC_H_
#define _ITEM7_GENERIC_H_

#include <iostream>

using namespace std;

/*
  Class 고유의 set_new_handler를 지원하기 위한 mixin 스타일 기초 클래스

  사용예)
  class X: public NewHandlerSupport<X> {
  ... //set_new_handler또는 연산자 new에 대한 선언을 사용할 필요 없음
  }
*/
template<class T>
class NewHandlerSupport {
public:
        static new_handler set_new_handler(new_handler p);
        static void* operator new(size_t size);

private:
        static new_handler currentHandler;
};

#endif /* _ITEM7_GENERIC_H_ */
