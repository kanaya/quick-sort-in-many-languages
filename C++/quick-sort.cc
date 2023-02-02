#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <vector>

template <typename T>
size_t partition(std::vector<T> &arr, size_t start, size_t end) {
	T pivot = arr[start];
	size_t count = 0;

	for (size_t i = start + 1; i <= end; ++i) {
		if (arr[i] <= pivot)
			++count;
	}

	size_t pivot_index = start + count;
	std::swap(arr[pivot_index], arr[start]);

	size_t i = start, j = end;

	while (i < pivot_index && j > pivot_index) {
		while (arr[i] <= pivot) {
			++i;
		}
		while (arr[j] > pivot) {
			--j;
		}
		if (i < pivot_index && j > pivot_index) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}
	return pivot_index;
}

template <typename T>
void quick_sort(std::vector<T> &arr, size_t start, size_t end) {
	if (start >= end) {
		return;
	}

	size_t p = partition(arr, start, end);
	quick_sort(arr, start, p - 1);
	quick_sort(arr, p + 1, end);
}

int main() {
	auto gen = []() {
		return std::rand() % 100;
	};

	std::vector<int> arr(100);
	std::generate(begin(arr), end(arr), gen);
	size_t n = arr.size();

	quick_sort(arr, 0, n - 1);
	// std::for_each(arr.begin(), arr.end(), [](int x) { std::cout << x << " "; });
	for (int a: arr) {
		std::cout << a << " ";
	}
	return 0;
}
