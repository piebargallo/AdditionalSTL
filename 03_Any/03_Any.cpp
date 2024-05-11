#include <any>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	any empty;
	any anInt{ 4 };
	any aString{ "An std::string."s };

	try {
		int test{ any_cast<int>(anInt) };
		cout << test << endl;
	}
	catch (const bad_any_cast& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	try {
		int test{ any_cast<int>(aString) };
		cout << test << endl;
	}
	catch (const bad_any_cast& ex) {
		cout << "Exception: " << ex.what() << endl;
	}
}
