#include <iostream>

// trivial : �ϴ� ���� "�ڸ�(�θ� �˷��� ����Ʈ ��Ĵ�� ����)" �ϴٴ� �ǹ�.
// trivial ������      : �ƹ� �ϵ� ���� ���� ������
// trivial ���� ������ : ��� ����� ���� �����ϴ� ���� ������.

class A
{
};

// B�� �����ڴ� trivial �ұ�� ?
class B // : public A
{
//	A a;
public:
	// virtual void foo() {}
};

// 1. �����Լ��� ����
// 2. ��� Ŭ������ ���ų� ��� Ŭ������ �����ڰ� trivial �ϰ�
// 3. ��ü�� ����� ���ų� ��ü�� ����� �����ڰ� trivial �ϰ�
// 4. ����ڰ� ���� �����ڰ� ������ 
// "�����ڴ� trivial" �մϴ�.



int main()
{
	B* p = (B*)malloc(sizeof(B)); // ������ ȣ�� �ȵ�.

	// �̹� �Ҵ�� �޸𸮿� �����ڸ� ȣ���ϴ� ����
	new(p) B; // placement new��� �մϴ�.

	p->foo();
}