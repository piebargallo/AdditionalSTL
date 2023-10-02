#include <tuple>
#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	std::cout << std::apply(add, std::tuple{ 2, 2 }) << std::endl;

	return 0;
}