from typing import Any
from collections.abc import MutableSequence, Callable
import random

def median3(x, y, z):
	return max(min(x, y), min(max(x, y), z))

def partition(seq: MutableSequence[Any], first: int, last: int):
	pivot = median3(seq[first], seq[first + (last - first) // 2], seq[last])
	while True:
		while seq[first] < pivot:
			first += 1
		while pivot < seq[last]:
			last -= 1
		if first >= last:
			return last + 1
		seq[first], seq[last] = seq[last], seq[first]
		first += 1
		last -= 1

def quick_sort(seq: MutableSequence[Any]):
	def quick_sort_impl(seq: MutableSequence, first: int, last: int):
		while first < last:
			p = partition(seq, first, last)
			if (p - first) < (last - p):
				quick_sort_impl(seq, first, p - 1)
				first = p
			else:
				quick_sort_impl(seq, p, last)
				last = p - 1
	quick_sort_impl(seq, 0, len(seq) - 1)

a = [random.randrange(100) for x in range(0, 100)]
quick_sort(a)
print(a)