#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	//Point()				: x(0), y(0) { LOG_FUNCTION_NAME(); }
	Point(int a, int b) : x(a), y(b) { LOG_FUNCTION_NAME(); }
	~Point()						 { LOG_FUNCTION_NAME(); }
};

int main()
{
	// Point 객체를 힙에 한개만 만들어 보세요.
	Point* p1 = new Point(1, 2);

	// Point 객체를 힙에 10개를 만들어 보세요
	//Point* p2 = new Point[10]; // 10개의 객체가 디폴트 생성자를 호출해서 생성되어야 합니다.
	                           // 디폴트 생성자가 없으므로 error

	/*
	Point* p2 = new Point[10]{{0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0},
		                      {0,0}}; // 중괄호 초기값이 C++11 부터 제공됨
	// C++11부터초기화를 할 수 있는 방법은 문법상 있지만
	// 코드량이 많아지는 무식한 방법
	*/

	// 1. 메모리만 10개 할당
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 2. 10개의 메모리공간에 객체를 생성
	for (int i = 0; i < 10; i++)
		new(&p2[i]) Point(0,0); // std::construct_at(&p2[i], 0, 0);

	// 3. 소멸자 호출
	for (int i = 0; i < 10; i++)
		p2[i].~Point(); // std::destroy_at(&p2[i]);

	// 4. 메모리해지
	operator delete(p2);

	// 메모리 할당과 생성자호출을 분리했다면
	// 메모리 해지와 소멸자호출도 분리하는 것이 원칙
	// 즉 delete[] p2 하지 말것
}
