// ATTRIBUTES1
#include <iostream>

// ������ ������ "foo" �� ���ο� ������ ���Դ�.
// [[���]] : attricbutes, �����Ϸ����� ����

// g++ : void foo() __attribute__(( ��� ))
// vc  : __delspec(���) void foo()
[[deprecated("please use foo_v2")]]void foo() {}

void foo_v2() {}

int main()
{
	foo();
}
