from typing import Any
from collections.abc import MutableSequence, Callable

def median3(x, y, z):
	return max(min(x, y), min(max(x, y), z))

def partition(seq: MutableSequence[Any], keyFn: Callable[[Any], Any], first: int, last: int):
	pivot = median3(keyFn(seq[first]), keyFn(seq[first + (last - first) // 2]), keyFn(seq[last]))
	while True:
		while keyFn(seq[first]) < pivot:
			first += 1
		while pivot < keyFn(seq[last]):
			last -= 1
		if first >= last:
			return last + 1
		seq[first], seq[last] = seq[last], seq[first]
		first += 1
		last -= 1

def quick_sort(seq: MutableSequence[Any], keyFn: Callable[[Any], Any]):
	def quick_sort_impl(seq: MutableSequence, keyFn: Callable[[Any], int], first: int, last: int):
		while first < last:
			p = partition(seq, keyFn, first, last)
			if (p - first) < (last - p):
				quick_sort_impl(seq, keyFn, first, p - 1)
				first = p
			else:
				quick_sort_impl(seq, keyFn, p, last)
				last = p - 1
	quick_sort_impl(seq, keyFn, 0, len(seq) - 1)

def id(x):
	return x

a = [3, 4, 5, 8, 1, 2, 10]
quick_sort(a, id)
print(a)