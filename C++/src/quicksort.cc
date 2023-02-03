#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <random>

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
	size_t n = arr.size();

	start_quick_sort(arr);
	for (int a: arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
	return 0;
}
