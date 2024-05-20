/* Chapter 14, "Handling Errors," explains error handling in C++ and explains that there are basically two major
   options: either you work with error codes or your work with exceptions. I recommend using exceptions for error
   handling, but for this exercise, you´ll use error codes. Write a simple Erroe class that just stores a single 
   message, and has a getter to retrieve the message. Next write a getData() function with a single parameter 
   called fail. If fail is false, the function retunrs a vector of some data; otherwise, it returns an instance of
   Error. You are not allowed to use reference-to-non-const output parameters. Test your implementation in your
   main() function. */

#include <iostream>
#include <variant>
#include <vector>
#include <string>

using namespace std;

class Error
{
public:
	Error(string message) : m_message{ move(message) } { }
	const string& getMessage() const { return m_message; }

private:
	string m_message;
};

variant<vector<int>, Error> getData(bool fail)
{
	if (fail) {
		return Error{ "An error occured." };
	}
	else {
		return vector{ 0, 1, 2, 3, 4 };
	}
}

void handleResult(const variant<vector<int>, Error>& result)
{
	if (holds_alternative<Error>(result)) {
		cout << "Error: " << get<Error>(result).getMessage() << endl;
	}
	else {
		auto& data{ get<vector<int>>(result) };
		for (auto& value : data) {
			cout << value << " ";
		}
		cout << endl;
	}
}

int main()
{
	handleResult(getData(false));
	handleResult(getData(true));
}
