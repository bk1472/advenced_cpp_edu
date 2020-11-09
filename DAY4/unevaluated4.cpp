// unevaluated4
#include <iostream>

class Test
{
public:
	int resize() {return 0;}
};

// 핵심 :  SFINAE 기술로.. "조건을 만족하지 않으면 실패" 하는 함수 템플릿 설계
//      resize() 함수가 있는지 조사가 필요

// 아래 템플릿은 T 안에 resize()가 있으면 성공, 없으면 (치환)실패 입니다.
template<typename T>
int  check( decltype( T().resize() )* p );

// 위의 템플릿이 실패하면 무조건 아래의 check 가 선택됨 (모든 case 에서 ...은 마지막에 선택됨)
template<typename T> char check(...);

int main()
{
	int n = sizeof( check<Test>(0) );

	std::cout << n << std::endl; // resize() 가 있으면 4 없으면 1
}
