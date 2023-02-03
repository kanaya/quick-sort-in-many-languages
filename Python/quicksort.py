import random

def partition(arr, first, last):
	pivot = arr[first]
	while True:
		while arr[first] < pivot:
			first += 1
		while pivot < arr[last]:
			last -= 1
		if first >= last:
			return last + 1
		arr[first], arr[last] = arr[last], arr[first]
		first += 1
		last -= 1

def quick_sort(arr):
	def quick_sort_impl(arr, first, last):
		while first < last:
			p = partition(arr, first, last)
			if (p - first) < (last - p):
				quick_sort_impl(arr, first, p - 1)
				first = p
			else:
				quick_sort_impl(arr, p, last)
				last = p - 1
	quick_sort_impl(arr, 0, len(arr) - 1)

a = [random.randrange(100) for x in range(0, 100)]
quick_sort(a)
print(a)