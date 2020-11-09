#include <memory>

struct People
{
	~People() { std::cout << "~People" << std::endl; }

	// shared pointer를 사용하면 상호 참조가 되어서 메모리 누수가 발생 할 수 있다.
	//std::shared_ptr<People> bestFriend;
	People* bestFirend; // raw pointer
};

int main()
{
	std::shared_ptr<People> sp1(new People);
	{
		std::shared_ptr<People> sp2(new People);


		//shared ptr 사용시 메모리 눅수 상호 참조
		//sp1->bestFriend = sp2;
		//sp2->bestFriend = sp1;

		//이제 bestFriend은 진짜 포인터 입니다.
		sp1->bestFriend = sp2.get();
		sp2->bestFriend = sp1.get();
	} // sp2는 파괴...

	if (sp1->bestFirend != 0)
	{
		// bestFriend 가 가리키는 곳이 유효할 거라고 생각할 수 있지만...
		// 객체는 파괴 되었다.
		// dangling pointer
	}
}
