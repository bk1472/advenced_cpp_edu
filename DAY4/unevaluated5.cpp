// unevaluated5
#include <iostream>

class Test
{
public:
	Test(int a) {}
	int resize() {return 0;}
};

// �򰡵��� ���� ǥ���Ŀ����� ����Ѵٸ� ���� ������ �ȴ�.
// �������� ��翡 ������� �򰡵��� ���� ǥ���Ŀ��� ����� ��ü�� �ʿ��� ���
// �Ʒ� �Լ� ���.
template<typename T> T declval();

//template<typename T> int  check( decltype( T().resize() )* p );
template<typename T> int  check( decltype( declval<T>().resize() )* p );

template<typename T> char check(...);

int main()
{
	int n = sizeof( check<Test>(0) );

	std::cout << n << std::endl;
}
