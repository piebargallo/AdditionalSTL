#include <iostream>
#include <string>
#include <tuple>
#include <format>

int main()
{
	std::tuple t1{ 16, "Test", true };  // Using CTAD
	// Or:
	//tuple<int, string, bool> t1{ 16, "Test", true };

	{
		int i{ 0 };
		std::string str;
		bool b{ false };
		std::cout << std::format("Before: i = {}, str = \"{}\", b = {}", i, str, b) << std::endl;
		tie(i, str, b) = t1;
		std::cout << std::format("After: i = {}, str = \"{}\", b = {}", i, str, b) << std::endl;
	}

	{
		int i{ 0 };
		bool b{ false };
		std::cout << std::format("Before: i = {}, b = {}", i, b) << std::endl;
		std::tie(i, std::ignore, b) = t1;
		std::cout << std::format("After: i = {}, b = {}", i, b) << std::endl;
	}

	return 0;
}