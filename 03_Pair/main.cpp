#include <iostream>
#include <string>
#include <utility>
#include <format>

int main()
{
	std::pair<int, std::string> p1{ 16, "Hello World" };
	std::pair p2{ true, 0.123f };
	std::cout << std::format("p1 = ({}, {})", p1.first, p1.second) << std::endl;
	std::cout << std::format("p2 = ({}, {})", p2.first, p2.second) << std::endl;

	return 0;
}