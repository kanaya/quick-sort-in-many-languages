def quicksort(seq)
	if seq.size == 0
		return seq
	end
	pivot = seq[0]
	right = Array.new
	left = Array.new
	for i in 1..seq.size-1
		if seq[i] <= pivot
			left.push(seq[i])
		else
			right.push(seq[i])
		end
	end

	left = quicksort(left)
	right = quicksort(right)
	return left + [pivot] + right
end

arr = []
100.times{ arr << rand(100) }
p(quicksort(arr))
