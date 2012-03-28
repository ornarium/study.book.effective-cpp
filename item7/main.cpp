#include <iostream>
#include "item7.h"

//X 객체를 위한 메모리 할당 실패시,
//호출하기 위한 함수 선언
void noMoreMemory() {
        cout << "no more memory" << endl;
}

int main(int argc, char *argv[])
{
        // noMoreMemory를 X의 new 핸들링 함수로 세팅
        X::set_new_handler(noMoreMemory);

        //메모리 할당 실패시, noMoreMemory를 호출
        X* px1 = new X;

        //메모리 할당 실패시, 있다면 전역 new 핸들링 함수를 호출함
        string* ps = new string;

        //X에 고유 new 핸들링 함수 해제
        X::set_new_handler(0);

        //메모리 할당 실패시, 전역 new 핸들링 함수 호출
        X* px2 = new X;
        
        return 0;
}
