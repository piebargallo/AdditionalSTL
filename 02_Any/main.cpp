#include <any>
#include <string>
#include <iostream>
#include <vector>

int main()
{
	std::any empty;
	std::any anInt{ 3 };
	std::any aString{ "An std::string." };

	std::cout << "empty.has_value = " << empty.has_value() << std::endl;
	std::cout << "anInt.has_value = " << anInt.has_value() << std::endl;

	std::cout << "anInt wrapped type = " << anInt.type().name() << std::endl;
	std::cout << "aString wrapped type = " << aString.type().name() << std::endl;

	int theInt{ any_cast<int>(anInt) };
	std::cout << theInt << std::endl;
	try {
		int test{ any_cast<int>(aString) };
		std::cout << test << std::endl;
	}
	catch (const std::bad_any_cast& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}


	std::any something{ 3 };              // Now it contains an integer.
	something = "An std::string";   // Now the same instance contains a string.


	std::vector<std::any> v;
	v.push_back(42);
	v.push_back("An std::string");

	std::cout << any_cast<std::string>(v[1]) << std::endl;

	return 0;
}
