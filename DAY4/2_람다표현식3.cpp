#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class ClosureType
{
public:
	// operator() �Լ��� static �Լ��� �ɼ� ���� ��Ģ�� �ִ�
	inline int operator()(int a, int b) const
	{
		return a + b;
	}
	// static ����Լ����� "��� ����Լ�"��� ������ ������� �ʽ��ϴ�.
	static inline auto helper(int a, int b)
	{
		return a + b;
	}

	// ��ü�� �Լ� �����ͷ� ��ȯ�� �� �ֵ��� ��ȯ ������ �Լ� ����
	typedef int(*F)(int, int);

	operator F() { return &ClosureType::helper; } // �׷���, operator() �Լ��� ����Լ� �̹Ƿ�
	                                              // this�� �߰��Ǵ� �Լ�
};
/*
class ClosureType
{
	int vq, v2;
public:
	ClosureType(int v1, int v2) : v1(v1), v2(v2) {}

	inline int operator()(int a, int b) const
	{
		return a + b + v1 + v2;
	}
	static inline auto helper(int a, int b)
	{
		return a + b + v1 + v2; // error. static ����Լ��� ��� ����Ÿ ������ �ȵȴ�
	}

	typedef int(*F)(int, int);

	operator F() { return &ClosureType::helper; } // �׷���, operator() �Լ��� ����Լ� �̹Ƿ�
	                                              // this�� �߰��Ǵ� �Լ�
};
*/

int main()
{
	auto f1 = [](int a, int b) { return a + b; };

	//����ǥ������ �Լ� �����Ϳ� ���� �� �ֽ��ϴ�.
	int(*f)(int, int) = [](int a, int b) { return a + b; };
					// ClosureType().operator �Լ�������Ÿ��()


	/*
	// �������� ĸ�� ���� : �Լ������� ������ ����
	int v1 = 10, v2 = 20;
	int(*f)(int, int) = [v1, v2](int a, int b) { return a + b; };
	*/

	// ���: ���������� "ĸ������ ���� ����ǥ���ĸ�" �Լ� �����ͷ� ��ȯ ���� �մϴ�.
	//          ĸ���� ����ǥ������ �Լ������ͷ� ��ȯ�� �� �����ϴ�.

}
