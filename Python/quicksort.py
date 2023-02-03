import random

def quick_sort(arr):
	if (len(arr) <= 1):
		return arr
	else:
		pivot = arr[0]
		arr_rest = arr[1:len(arr)]
		left = list(filter(lambda x: x < pivot, arr_rest))
		right = list(filter(lambda x: x >= pivot, arr_rest))
		return quick_sort(left) + [pivot] + quick_sort(right)

arr = [random.randrange(100) for x in range(0, 100)]
print(quick_sort(arr))
