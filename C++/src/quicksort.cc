#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <random>

template <typename T>
std::size_t partition(std::vector<T> &arr, std::size_t begin, std::size_t end) {
	T pivot = arr[begin];
	std::size_t count = 0;

	for (std::size_t i = begin + 1; i <= end; ++i) {
		if (arr[i] <= pivot)
			++count;
	}

	std::size_t it = begin + count;
	std::swap(arr[it], arr[begin]);

	std::size_t i = begin, j = end;

	while (i < it && j > it) {
		while (arr[i] <= pivot) {
			++i;
		}
		while (arr[j] > pivot) {
			--j;
		}
		if (i < it && j > it) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}
	return it;
}

template <typename T>
void quick_sort(std::vector<T> &arr, std::size_t begin, std::size_t end) {
	if (begin < end) {
		std::size_t p = partition(arr, begin, end);
		quick_sort(arr, begin, p - 1);
		quick_sort(arr, p + 1, end);
	}
}

template <typename T>
void start_quick_sort(std::vector<T> &arr) {
	quick_sort(arr, 0, arr.size() - 1);
}

int main() {
	std::random_device rnd;
	auto gen = [&rnd]() {
		return rnd() % 100;
	};

	std::vector<int> arr(100);
	std::generate(begin(arr), end(arr), gen);
	std::size_t n = arr.size();

	start_quick_sort(arr);
	for (int a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
	return 0;
}
