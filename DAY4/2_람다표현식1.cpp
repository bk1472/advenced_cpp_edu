#include <algorithm>
#include <functional>
#include <vector>
using namespace std;



// ���� ǥ������ ����
// ����ǥ������ ���� �����Ϸ��� ���� Ŭ����
class ClosureType
{
public:
	inline int operator()(int a, int b) const
	{
		return a + b;
	}
};


int main()
{
//	auto f1 = [](int a, int b) { return a + b; }

	// ����ǥ���� :  �����Ϸ��� ������ Ŭ������ �ӽð�ü
	auto f1 = ClosureType();



	// �Լ� ó�� ��� ����
	int n = f1(1, 2); // f1.operator()(1, 2); �� ���


	// ���� �� ������ ������.
	auto        a1 = [](int a, int b) { return a + b; }; // ok    .. ����
	auto&       a2 = [](int a, int b) { return a + b; }; // error .. lvalue <- rvalue
	const auto& a3 = [](int a, int b) { return a + b; }; // ok    .. �Ѵ� ���� �� ����
	auto&&      a4 = [](int a, int b) { return a + b; }; // ok    ..  forwarding reference

	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });
}






