package main

type set map[int]bool

func intersection(nums1 []int, nums2 []int) []int {
	tmp := make(set)
	ans := make(set)
	var ret []int
	for _, i := range nums1 {
		tmp[i] = true
	}
	for _, i := range nums2 {
		if tmp[i] {
			ans[i] = true
		}
	}

	for k := range ans {
		ret = append(ret, k)
	}
	return ret

}
