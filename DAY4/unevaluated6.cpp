// unevaluated6
#include <iostream>

class Test
{
public:
	Test(int a) {}
	int resize() {return 0;}
};

template<typename T> T declval();

template<typename T> int  check( decltype( declval<T>().resize() )* p );

template<typename T> char check(...);

template<typename T> struct has_resize_function
{
	static constexpr bool value = (sizeof(check<T>(0)) == sizeof(int));
};

int main()
{
	bool b = has_resize_function<Test>::value;

	std::cout << b << std::endl;
}
// �� ����� �̸��� "member detect" ��� C++ Idioms �Դϴ�.
