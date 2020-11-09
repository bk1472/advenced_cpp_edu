#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main                     chronometry                hoo(int&&)
// hoo(10) =============================================> ok
// chronometry(hoo, 10) ====> int&& arg = 10;
//                            f(arg) ============> hoo(int&) 를 찾는다.. error
//                          f(static_cast<int&&>(arg)) => ok

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10 으로 받았는데.. arg는 이름이 있으므로 lvalue 이다.
	//f(arg); // hoo(int&) 을 찾게 된다.

	// 인자를 전달할 때 다시 rvalue로 캐스팅 해서 전달한다.
	f( static_cast<int&&>(arg) );
}

int main()
{
	hoo(10);
	chronometry(hoo, 10);
}
