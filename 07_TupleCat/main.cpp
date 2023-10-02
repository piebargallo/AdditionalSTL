#include <iostream>
#include <string>
#include <tuple>

int main()
{
	std::tuple t1{ 16, "Test", true };  // Using CTAD
	std::tuple t2{ 3.14, "string 2" };
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };
	//tuple<double, string> t2{ 3.14, "string 2" };

	auto t3{ tuple_cat(t1, t2) };

	std::cout << get<0>(t3) << std::endl;
	std::cout << get<1>(t3) << std::endl;
	std::cout << get<2>(t3) << std::endl;
	std::cout << get<3>(t3) << std::endl;
	std::cout << get<4>(t3) << std::endl;

	return 0;
}
