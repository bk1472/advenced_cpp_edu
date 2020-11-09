// unevaluated4
#include <iostream>

class Test
{
public:
	int resize() {return 0;}
};

// �ٽ� :  SFINAE �����.. "������ �������� ������ ����" �ϴ� �Լ� ���ø� ����
//      resize() �Լ��� �ִ��� ���簡 �ʿ�

// �Ʒ� ���ø��� T �ȿ� resize()�� ������ ����, ������ (ġȯ)���� �Դϴ�.
template<typename T>
int  check( decltype( T().resize() )* p );

// ���� ���ø��� �����ϸ� ������ �Ʒ��� check �� ���õ� (��� case ���� ...�� �������� ���õ�)
template<typename T> char check(...);

int main()
{
	int n = sizeof( check<Test>(0) );

	std::cout << n << std::endl; // resize() �� ������ 4 ������ 1
}
