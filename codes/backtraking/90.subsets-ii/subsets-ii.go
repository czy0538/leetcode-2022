package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
	result := [][]int{[]int{}}
	path := []int{}
	var backtracing func(int)
	backtracing = func(beg int) {
		if beg == len(nums) {
			return
		}
		for i := beg; i < len(nums); i++ {
			if i == beg && nums[i-1] == nums[i] {
				continue
			}
			path = append(path, nums[i])
			result = append(result, append([]int{}, path...))
			backtracing(i + 1)
			path = path[:len(path)-1]
		}
	}

	sort.Ints(nums)
	backtracing(0)
	return result

}
