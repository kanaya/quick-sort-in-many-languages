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

	size_t pivotIndex = start + count;
	std::swap(arr[pivotIndex], arr[start]);

	size_t i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			++i;
		}
		while (arr[j] > pivot) {
			--j;
		}
		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}
	return pivotIndex;
}

template <typename T>
void quickSort(std::vector<T> &arr, size_t start, size_t end) {
	if (start >= end) {
		return;
	}

	size_t p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main() {
	auto gen = []() {
		return std::rand() % 100;
	};

	std::vector<int> arr(100);
	std::generate(begin(arr), end(arr), gen);
	size_t n = arr.size();

	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
