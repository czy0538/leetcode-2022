package main

func searchRange(nums []int, target int) []int {
	result := []int{-1, -1}
	l := 0
	r := len(nums)
	mid := (l + r) / 2

	for l < r {
		if nums[mid] == target {
			for i := mid; i >= 0 && nums[i] == target; i-- {
				result[0] = i
			}
			for i := mid; i < len(nums) && nums[i] == target; i++ {
				result[1] = i
			}
			break
		} else if nums[mid] < target {
			l = mid + 1
		} else {
			r = mid
		}
		mid = (l + r) / 2
	}
	return result
}
