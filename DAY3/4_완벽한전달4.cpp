#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// "T&&" 를 사용하면 아래 2개의 함수를 자동 생성할 수 있다.
// 그런데,, 문제는 2개의 함수의 구현이 같아야 한다
/*
template<typename F> void chronometry(F f, int& arg)
{
	//f(arg);
	f( static_cast<int&>(arg) ); // 필요없는 캐스팅이지만..
	                             // 있어도 문제 되지 않습니다.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f( static_cast<int&&>(arg) );
}
*/

// 아래 함수가 결국 위 2개의 함수를 자동 생성합니다.
template<typename F, typename T> void chronometry(F f, T&& arg)
{
	// 아래캐스팅은
	// "lvalue(가 인자로 오면)를 lvalue 로 캐스팅 하고"
	// "rvalu(e가 인자로 오면)를 rvalue 로 캐스팅 한다"

	// f( static_cast<T&&>(arg) ); // 틀린것은 아니지만 아래처럼 제공함수 사용하자
	f(std::forward<T>(arg)); // std::forward 함수가 위처럼 캐스팅하는 역할을 합니다.
	                         // 다른 곳에 인자를 전달할 때 사용한다는 의미로
							 // "forward" 라는 단어 사용
}

// 결론!!! 완벽한 전달을 하려면
// 1. 인자를 T&& 로 받으세요
// 2. 인자를 다른곳에 보낼 때는 std::forward<T>(arg)로 묶어서 보내세요
int main()
{
	int n = 10;
	chronometry(foo, 10); // T : int,  T&& : int&&   캐스팅 : static_cast<int&&>(arg)
	chronometry(goo,  n); // T : int&, T&& : int& && 캐스팅 : static_cast<int&>(arg)
}
