// unevaluated2
#include <iostream>

class Test {};


int main()
{
	bool b = has_resize_function<Test>::value;
}
