// std::move()
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> // g++ 은 이 헤더 추가하세요

using namespace std;

// g++ 1_move4.cpp -fno-elide-constructors

// 핵심
// C++98 : 한개의 복사 생성자 - "깊은복사" 나 "참조계수"기술로 구현
// C++11 : 임시객체를 위한 복사 생성자를 한개 더 만들자는 것..
//         A. 기존의 복사 생성자
//         B. 임시객체를 위한 복사 생성자 - "자원의 이동(move)로 구현"
//         => "move 생성자"
class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// 일반적인 형태의 복사 생성자
	Cat (const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
		std::cout << "Copy" << std::endl;
	}
	// 임시객체 일때 사용할 복사 생성자
	// rvalue 우선순위 때문에 아래의 코드가 call 됨
	Cat (Cat&& c) : age(c.age), name(c.name)
	{
		// 반드시 원래 객체가 가진 포인터는
		// 0으로 reset 되어야 합니다.
		// C++에서는 nullptr 메모리 delete 하는 건 문제없다
		c.name = nullptr;
		std::cout << "Move" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 5);
	return c; // 여기서 임시객체를 만들때 move 호출
}

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;

	Cat c3 = foo();
//  Cat c3 = 임시객체; // 얕은 복사를 해서 성능을 높이자
                       // 임시객체용 복사생성자를 하나더 만든다

	return 0;
}
