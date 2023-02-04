import random

def quick_sort(arr):
	if (len(arr) <= 1):
		return arr
	else:
		x = arr[0]
		xs = arr[1:len(arr)]
		left = list(filter(lambda y: y < x, xs))
		right = list(filter(lambda y: y >= x, xs))
		return quick_sort(left) + [x] + quick_sort(right)

arr = [random.randrange(100) for x in range(0, 100)]
print(quick_sort(arr))
