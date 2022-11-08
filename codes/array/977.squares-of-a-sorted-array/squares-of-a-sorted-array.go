package main

import "sort"

// 最基础的方法
// func sortedSquares(nums []int) []int {
// 	for j,i:=range nums{
// 		nums[j]=i*i;

// 	}
// 	sort.Ints(nums)
// 	return nums
// }

// 直接上最好的双指针法
func sortedSquares(nums []int) []int {
	i := 0
	j := len(nums) - 1
	ans := make([]int, len(nums))
	k := len(ans) - 1
	a := nums[i] * nums[i]
	b := nums[j] * nums[j]
	for k >= 0 {
		if a > b {
			ans[k] = a
			k--
			if k >= 0 {
				i++
				a = nums[i] * nums[i]
			}
		} else {
			ans[k] = b
			k--
			if k >= 0 {
				j--
				b = nums[j] * nums[j]
			}
		}
	}
	return ans
}
