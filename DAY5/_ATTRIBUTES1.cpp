// ATTRIBUTES1
#include <iostream>

// 세월이 지나서 "foo" 의 새로운 버전이 나왔다.
// [[명령]] : attricbutes, 컴파일러에게 지시

// g++ : void foo() __attribute__(( 명령 ))
// vc  : __delspec(명령) void foo()
[[deprecated("please use foo_v2")]]void foo() {}

void foo_v2() {}

int main()
{
	foo();
}
