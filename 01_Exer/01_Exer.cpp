/* Write an algorithm called transform_if(), similar to the Standard Library`s transform(), discussed in Chapter 20.
   The difference is that transform_if() should accept an extra predicate and that only transforms elements for wich
   the predicate returns true. Other elements are left untouched. to test your algorithm, create a vector of integers
   and multiply all odd values in the vector by 2. */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<typename InputIterator, typename OutputIterator,
	typename Predicate, typename UnaryOperation>
OutputIterator transform_if(InputIterator first, InputIterator last,
	OutputIterator output, Predicate pred, UnaryOperation op)
{
	auto iter{ first };
	while (iter != last) {
		if (pred(*iter)) {
			*output = op(*iter);
		}
		else {
			*output = *iter;
		}
		++output;
		++iter;
	}
	return output;
}

int main()
{
	vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (auto& value : values) { cout << value << " "; }
	cout << endl;

	transform_if(begin(values), end(values), begin(values),
		[](const auto& value) { return value % 2 != 0; },
		[](const auto& value) { return value * 2; });

	for (auto& value : values) { cout << value << " "; }
	cout << endl;
}