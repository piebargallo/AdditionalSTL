#include <variant>
#include <string>
#include <iostream>

class MyVisitor
{
public:
	void operator()(int i) { std::cout << "int " << i << std::endl; }
	void operator()(const std::string& s) { std::cout << "string " << s << std::endl; }
	void operator()(float f) { std::cout << "float " << f << std::endl; }
};

int main()
{
	std::variant<int, std::string, float> v;
	v = 12;
	v = 12.5f;
	v = "An std::string";

	std::cout << "Type index: " << v.index() << std::endl;
	std::cout << "Contains an int: " << holds_alternative<int>(v) << std::endl;

	std::cout << get<std::string>(v) << std::endl;
	try {
		std::cout << get<0>(v) << std::endl;
	}
	catch (const std::bad_variant_access& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	std::string* theString{ get_if<std::string>(&v) };
	int* theInt{ get_if<int>(&v) };
	std::cout << "Retrieved string: " << (theString ? *theString : "null") << std::endl;
	std::cout << "Retrieved int: " << (theInt ? *theInt : 0) << std::endl;

	visit(MyVisitor{}, v);

	return 0;
}
