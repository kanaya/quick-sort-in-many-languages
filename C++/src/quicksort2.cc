#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <random>

template <typename Iterator, typename T = typename Iterator::value_type>
auto partition(Iterator begin, Iterator end) {
	T pivot = *begin;
	auto it = std::find_if(begin, end, [pivot](T x) { return x <= pivot; });
	std::swap(*it, *begin);  // really swaps?
	auto i = begin, j = end;
	while (i < it && j > it) {
		while (*i <= pivot) {
			++i;
		}
		while (*j > pivot) {
			--j;
		}
		if (i < it && j > it) {
			std::swap(*i, *j);  // really swaps?
			++i;
			++j;
		}
	}
	return it;
}

template <typename Iterator>
void quick_sort(Iterator begin, Iterator end) {
	if (begin >= end) {
		return;
	}
	else {
		auto p = partition(begin, end);
		quick_sort(begin, p - 1);
		quick_sort(p + 1, end);
	}
}

int main() {
	std::random_device rnd;
	auto gen = [&rnd]() {
		return rnd() % 100;
	};

	std::vector<int> arr(100);
	std::generate(begin(arr), end(arr), gen);
	std::size_t n = arr.size();

	quick_sort(arr.begin(), arr.end());
	for (int a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
	return 0;
}
