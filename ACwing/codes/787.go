package main

import "fmt"

var tmp []int

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	nums := make([]int, n)
	tmp = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &nums[i])
	}
	mergeSort(nums, 0, n-1)
	for _, i := range nums {
		fmt.Printf("%d ", i)
	}
}

func mergeSort(nums []int, l, r int) {
	if l >= r {
		return
	}
	mid := (l + r) / 2
	i := l
	j := mid + 1
	k := l

	mergeSort(nums, l, mid)
	mergeSort(nums, mid+1, r)

	for i <= mid && j <= r {
		if nums[i] < nums[j] {
			tmp[k] = nums[i]
			i++
		} else {
			tmp[k] = nums[j]
			j++
		}
		k++
	}
	for i <= mid {
		tmp[k] = nums[i]
		i++
		k++
	}
	for j <= r {
		tmp[k] = nums[j]
		j++
		k++
	}
	for i := l; i <= r; i++ {
		nums[i] = tmp[i]
	}
}
