#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <random>

template <typename Iterator, typename T = typename Iterator::value_type>
auto partition(Iterator begin, Iterator end) {
	T pivot = *begin;
	std::size_t count = 0;
	for (auto p = begin + 1; p != end; ++p) {
		if (*p <= pivot) {
			++count;
		}
	}
	auto it = begin + count;
	std::swap(*it, *begin);
	auto i = begin;
	auto j = end - 1;
	while (std::distance(it, i) < 0 && std::distance(it, j) > 0) {
		while (*i <= pivot) {
			++i;
		}
		while (*j > pivot) {
			--j;
		}
		if (std::distance(it, i) < 0 && std::distance(it, j) > 0) {
			std::swap(*i, *j);
			++i;
			--j;
		}
	}
	return it;
}

template <typename Iterator>
void quick_sort(Iterator begin, Iterator end) {
	if (begin != end) {
		auto p = partition(begin, end);
		quick_sort(begin, p);
		quick_sort(p + 1, end);
	}
}

int main() {
	std::random_device rnd;
	auto gen = [&rnd]() {
		return rnd() % 100;
	};

	std::vector<int> arr(10);
	std::generate(begin(arr), end(arr), gen);
	for (int a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	quick_sort(arr.begin(), arr.end());
	for (int a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
	return 0;
}
