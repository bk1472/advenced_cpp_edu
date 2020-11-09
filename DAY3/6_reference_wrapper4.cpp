#include <iostream>
#include <functional>

void foo(int& a, int n) { a = 300; }

int main()
{
	std::function<void(int)> f; // C++11 function
	                            // �Լ� ������ ����..

	// bind�� ���ڸ� "������ �ƴ� ��" ���� �����ϰ� �˴ϴ�. ������ �Ʒ� {}�� �ִٰ� ������ ������
//	{
	int n = 0;

	f = std::bind(&foo, n, _1); // 1��° ���ڸ� "n"���� �����������?
	                            // "n�� ��(0)"���� ���� ������� ?   ==> ����..
	f = std::bind(&foo, std::ref(n), _1);
//	}
	f(10); // foo(n, 10) �� �ƴϰ�
	       // foo(0, 10) �� ǥ��..

	std::cout << n << std::endl;
}
