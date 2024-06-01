/* Write an algorithm called generate:fibonacci(), wich fills a given range with a Fibonnaci series of numbers.
   The fibonacci series starts with 0 and 1, and any sub subsequent value is the sun of the previous values, so:
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, and so on. Your implementation is not allewed to contain any manually
   writen loops or be implement using a recursive algorithm. instead, you should use the Standard Library´s generate()
   algorithm to do most of the work. */

#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

template <typename OutputIterator>
void generate_fibonacci(OutputIterator first, OutputIterator last)
{
	typename OutputIterator::value_type a{ 0 };
	typename OutputIterator::value_type b{ 1 };

	auto iter{ first };

	if (iter != last) { *iter = a; ++iter; }
	else { return; }

	if (iter != last) { *iter = b; ++iter; }
	else { return; }

	generate(iter, last,
		[&a, &b] {
			auto next{ a + b };
			a = b;
			b = next;
			return next;
		});
}

int main()
{
	vector<int> fibonacci(24);
	generate_fibonacci(begin(fibonacci), end(fibonacci));
	for (auto& value : fibonacci) { cout << value << " "; }
	cout << endl;
}