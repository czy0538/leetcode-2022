package main

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	dict := make(map[int]int)
	count := 0
	for _, a := range nums1 {
		for _, b := range nums2 {
			dict[a+b]++
		}
	}

	for _, c := range nums3 {
		for _, d := range nums4 {
			k, v := dict[-(c + d)]
			if v {
				count += k
			}
		}
	}

	return count
}
