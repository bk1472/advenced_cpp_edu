#include <iostream>

class Animal {};
class Dog : public Animal {};


template<typename T> struct default_delete
{
	inline void operator()(T* p) noexcept
	{
		std::cout << "delete" << std::endl;
		delete p;
	}

	template<typename U,
		     std::enable_if_t<std::is_convertible_v<T*, U*>, int> = 0>
	default_delete( const default_delete<U>& ) {}

	default_delete() = default;
};

int main()
{
	default_delete<Animal>  d1;
	default_delete<Dog> d2 = d1; // ok.. Dog 삭제가 필요할 때 Animal 삭제자 전달가능

//	default_delete<int> d3 = d1; // 안되야 한다...(그런데 컴파일 에러가 안달 때 수정, enale_if_t)
}
