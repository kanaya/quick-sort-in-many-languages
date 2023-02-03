def quicksort(arr)
	if arr.size == 0
		return arr
	end
	pivot = arr[0]
	right = Array.new
	left = Array.new
	for i in 1..arr.size-1
		if arr[i] <= pivot
			left.push(arr[i])
		else
			right.push(arr[i])
		end
	end

	left = quicksort(left)
	right = quicksort(right)
	return left + [pivot] + right
end

arr = []
100.times{ arr << rand(100) }
p(quicksort(arr))
