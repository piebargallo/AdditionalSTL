#include <variant>
#include <string>
#include <iostream>

using namespace std;

class MyVisitor
{
public:
	void operator()(int i) { cout << "int " << i << endl; }
	void operator()(const string& s) { cout << "string " << s << endl; }
	void operator()(float f) { cout << "float " << f << endl; }
};

int main()
{
	variant<int, string, float> v;
	v = 12;
	v = 12.5f;
	v = "An std::string"s;

	try {
		cout << get<string>(v) << endl;
	}
	catch (const bad_variant_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	try {
		cout << get<0>(v) << endl;
	}
	catch (const bad_variant_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}
}
