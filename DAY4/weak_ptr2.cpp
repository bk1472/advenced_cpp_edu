#include <memory>

struct People
{
	~People() { std::cout << "~People" << std::endl; }

	// shared pointer�� ����ϸ� ��ȣ ������ �Ǿ �޸� ������ �߻� �� �� �ִ�.
	//std::shared_ptr<People> bestFriend;
	People* bestFirend; // raw pointer
};

int main()
{
	std::shared_ptr<People> sp1(new People);
	{
		std::shared_ptr<People> sp2(new People);


		//shared ptr ���� �޸� ���� ��ȣ ����
		//sp1->bestFriend = sp2;
		//sp2->bestFriend = sp1;

		//���� bestFriend�� ��¥ ������ �Դϴ�.
		sp1->bestFriend = sp2.get();
		sp2->bestFriend = sp1.get();
	} // sp2�� �ı�...

	if (sp1->bestFirend != 0)
	{
		// bestFriend �� ����Ű�� ���� ��ȿ�� �Ŷ�� ������ �� ������...
		// ��ü�� �ı� �Ǿ���.
		// dangling pointer
	}
}
