package main

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	tmp := make(map[int]int)
	result := 0
	for _, i := range nums1 {
		for _, j := range nums2 {
			tmp[i+j]++
		}
	}
	for _, i := range nums3 {
		for _, j := range nums4 {
			result += tmp[-(i + j)]
		}
	}
	return result
}
