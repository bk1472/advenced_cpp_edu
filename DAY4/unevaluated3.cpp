// unevaluated3
#include <iostream>

// �ٽ� 1. �򰡵��� ���� ǥ���Ŀ� �ִ� �Լ��� ���� ������ ����.
//      2. sizeof(�Ԥ���ȣ���) ���� ��� �Լ��� ȣ��Ǵ��� ���� ����.
int check(int a);
char check(double d);

int main()
{
	int n = sizeof( check(3.4) );
	int n2 = sizeof( check(3) );

	std::cout << n << std::endl; // 1
	std::cout << n2 << std::endl; // 4
}
