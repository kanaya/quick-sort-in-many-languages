package main

import (
	"fmt"
	"math/rand"
)

func partition(arr []int, low, high int) ([]int, int) {
	pivot := arr[high]
	i := low
	for j := low; j < high; j++ {
		if arr[j] < pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}
	arr[i], arr[high] = arr[high], arr[i]
	return arr, i
}

func quickSort(arr []int, low, high int) []int {
	if low < high {
		var p int
		arr, p = partition(arr, low, high)
		arr = quickSort(arr, low, p-1)
		arr = quickSort(arr, p+1, high)
	}
	return arr
}

func quickSortStart(arr []int) []int {
	return quickSort(arr, 0, len(arr)-1)
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
	fmt.Println(quickSortStart(arr))
}
