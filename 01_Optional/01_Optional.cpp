#include <optional>
#include <iostream>

using namespace std;

optional<int> getData(bool giveIt)
{
	if (giveIt) {
		return 42;
	}

	return nullopt;  // or simply return {};
}

int main()
{
	optional<int> data1{ getData(true) }; // True
	optional<int> data2{ getData(false) }; // False

	try {
		cout << "data1.value = " << data1.value() << endl;
	}
	catch (const bad_optional_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	try {
		cout << "data2.value = " << data2.value() << endl;
	}
	catch (const bad_optional_access& ex) {
		cout << "Exception: " << ex.what() << endl;
	}
}
