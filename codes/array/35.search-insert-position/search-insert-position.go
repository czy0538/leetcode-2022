package main

// 左闭右闭版本
func searchInsert(nums []int, target int) int {
	l := 0
	r := len(nums) - 1
	i := (l + r) / 2

	for l <= r {
		if nums[i] < target {
			l = i + 1
		} else if nums[i] > target {
			r = i - 1
		} else {
			break
		}
		i = (l + r + 1) / 2
	}

	return i
}
