#include <iostream>

int& foo(int a, int b, int& c)
{
	c = 200;
	return c;
}

// �Ϻ��� ������ ��κ� "�������� ���ø�" ����� ����մϴ�.
template<typename F, typename ... T>
//auto chronometry(F f, T&& ... arg) // ��ȯ Ÿ���� ������ ��� ������ ������ Ÿ������ �߷еȴ�
//auto chronometry(F f, T&& ... arg) -> decltype( f(std::forward<T>(arg)...) ) // ok �ε� �ʹ� �����ϴ�
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;
	chronometry(foo, 10);

	std::cout << n << std::endl;
}
