#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { LOG_FUNCTION_NAME(); }
	~Point()			{ LOG_FUNCTION_NAME(); }
	Point(const Point&) { LOG_FUNCTION_NAME(); }
};

int goo() { return 10; }
void foo( std::shared_ptr<Point> sp, int b) {}

int main()
{
	// 아래 코드는 안전한 코드일까요 ?
	// foo 인자로 들어가는 각각의 수행의 순서가 정해져있지 않다
	// 컴파일러마다 다를 수 있다
	foo( std::shared_ptr<Point>( new Point(1, 2) ), goo() );
	//           <1>                <2>               <3>
	//  순서: <2>-><1>-><3> 이면 안전한데
	//        <2>-><3>-><1> 이면 <3>이 exception 인경우 메모리 누수


	// 객체의 생성과.. 객체를 관리하는 스마트 포인터의 생성은
	// "히나의 동작"으로 하는 것이 안전하다

	std::shared_ptr<Point> sp1( new Point(1, 2)); //  이렇게 하지말고

	std::shared_ptr<Point> sp2 = std:make_shared<Point>(1,2); // 이렇게 하라는 것
								// 1. Point* p = new Point(1,2) 로 만들고
								// 2. return std::shared_ptr<Point>(p) 처럼 반환

	foo( std::make_shared<Point>(1, 2), goo() );
}
