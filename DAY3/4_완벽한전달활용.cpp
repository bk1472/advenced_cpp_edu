#include "cppmaster.h"
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b) { LOG_FUNCTION_NAME(); }
	~Point()            { LOG_FUNCTION_NAME(); }
	Point(const Point&) { LOG_FUNCTION_NAME(); }
};
int main()
{
	std::vector<Point> v;

	// 아래 코드가 실행되면 소멸자가 몇번 호출 될까요?
	// vector에 요소 넣기.
	// 1. 객체를 만든 후 너히 - 2개의 객체 생성
	//Point pt(1, 2);   // 생성자
	//v.push_back(pt);  // 복사 생성자

	// 2. 임시객체로 넣기
	//v.push_back( Point(1, 2) ); // 임시 생성자 까지 생서자 두번 호출됨

	// 3. 객체를 만든 후 보내지 말고
	//    객체를 만들기 위한 생성자 인자를 전달한다.
	v.emplace_back(1, 2); // 이 함수가 내부적으로 new Point(1,2) 하게 됩니다.
	       // emplace_back 은 자신이 받은 인자를 Point 의 생성자에게 "전달(forwarding)"
		   // 하고 있습니다.

	// STL 컨테이너에 "사용자 타입을 값으로 보관 한다면"
	// push_xxx()로 넣지 말고...emplace_xxx()로 넣어라!!!
	// push_back(객체)   => emplace_back(생성자인자)
	// push_front()      => emplace_front()
	// insert()          => emplace()
	std::cout << "-----" << std::endl;
}
