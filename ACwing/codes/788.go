package main

import "fmt"

var tmp, nums []int

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	tmp = make([]int, n)
	nums = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &nums[i])
	}
	fmt.Printf("%d", mergeSort(nums, 0, n-1))

}

func mergeSort(nums []int, l, r int) (result int) {
	if l >= r {
		return 0
	}
	mid := (l + r) / 2
	i := l
	j := mid + 1
	k := l
	result = mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r)
	for i <= mid && j <= r {
		if nums[i] > nums[j] {
			result += mid - i + 1 // 点睛之笔
			tmp[k] = nums[j]
			j++
		} else {
			tmp[k] = nums[i]
			i++
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
	return result
}
