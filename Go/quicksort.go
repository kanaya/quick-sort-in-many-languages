package main

import (
	"fmt"
	"math/rand"
)

func partition(arr []int, begin, end int) ([]int, int) {
	pivot := arr[begin]
	i := begin
	for j := begin + 1; j < end; j++ {
		if arr[j] < pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}
	arr[i], arr[end] = arr[begin], arr[i]
	return arr, i
}

func quickSort(arr []int, begin, end int) []int {
	if begin < end {
		var p int
		arr, p = partition(arr, begin, end)
		arr = quickSort(arr, begin, p - 1)
		arr = quickSort(arr, p + 1, end)
	}
	return arr
}

func randomValue(values []int) []int {
    lenVaules := len(values)
    for i := 0; i < lenVaules; i++ {
        values[i] = rand.Intn(100)
    }
    return values
}

func main() {
	arr := make([]int, 100)
	randomValue(arr)
	fmt.Println(quickSort(arr, 0, len(arr) - 1))
}
