// unevaluated5
#include <iostream>

class Test
{
public:
	Test(int a) {}
	int resize() {return 0;}
};

// 평가되지 않은 표현식에서만 사용한다면 선언만 있으면 된다.
// 생성자의 모양에 상관없이 평가되지 않은 표현식에서 사용할 객체가 필요한 경우
// 아래 함수 사용.
template<typename T> T declval();

//template<typename T> int  check( decltype( T().resize() )* p );
template<typename T> int  check( decltype( declval<T>().resize() )* p );

template<typename T> char check(...);

int main()
{
	int n = sizeof( check<Test>(0) );

	std::cout << n << std::endl;
}
