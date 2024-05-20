/* Most command-line applications accept command-line parameters. In most, if not all, of the sample codein this book
   the main function is simply main(). However, main() can also accept parameters: main (int argc, char** argv) where
   argc is the number of command-line parameters, and argv is an array of strings, one string for each paremeter.
   Assume for this exercise that a command-line parameter is of the form name=value. Write a function that can parse
   a single parameter and that returns a pair containing the name of the parameter and a variant containing the 
   value as a Boolean if the value can be parsen as a Boolean (true or false), an integer if the value can be parsen
   as an integer, or a string otherwise. To split the name=value string, you can use a regular expression (see 
   Chapter 21, "String Locatization and Regular Expressions"). To parse integers, you can use one of the functions
   explained in Chapter 2, "Working with Strings and String Views." In your main() function, loop over all command-
   line parameters, parse them, and output the parsed results to the standard output using holds_altermative(). */

#include <iostream>
#include <string>
#include <variant>
#include <regex>
#include <utility>
#include <exception>
#include <stdexcept>
#include <format>

using namespace std;

using Parameter = pair<string, variant<bool, int, string>>;

Parameter parseParameter(const char* parameter)
{
	regex r{ "(.*)=(.*)" };
	if (cmatch m; regex_match(parameter, m, r)) {
		const auto& name{ m[1].str() };
		const auto& value{ m[2].str() };

		// Try to parse as Boolean.
		if (value == "true") { return { name, true }; }
		else if (value == "false") { return { name, false }; }

		// Try to parse as integer.
		try {
			int parsedInteger{ stoi(value) };
			return { name, parsedInteger };
		}
		catch (const exception&) {
			// Could not parse as integer.
		}

		// Just interpret as string.
		return { name, value };
	}
	throw invalid_argument{ "Cannot parse parameter." };
}

int main(int argc, char** argv)
{
	for (int i{ 0 }; i < argc; ++i) {
		try {
			auto parameter{ parseParameter(argv[i]) };
			if (holds_alternative<bool>(parameter.second)) {
				cout << format("Boolean: {} -> {}\n",
					parameter.first,
					get<bool>(parameter.second));
			}
			else if (holds_alternative<int>(parameter.second)) {
				cout << format("Integer: {} -> {}\n",
					parameter.first,
					get<int>(parameter.second));
			}
			else if (holds_alternative<string>(parameter.second)) {
				cout << format("String: {} -> {}\n",
					parameter.first,
					get<string>(parameter.second));
			}
		}
		catch (const invalid_argument&) {
			// Could not parse parameter, ignore it.
		}
	}
}
