package main

import "sort"

func threeSum(nums []int) [][]int {
	var ans [][]int
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			break
		}

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		left := i + 1
		right := len(nums) - 1

		for left < right {
			t := nums[left] + nums[right] + nums[i]
			if t == 0 {
				ans = append(ans, []int{nums[left], nums[right], nums[i]})
				for left<right&&nums[left]==nums[left+1]{
					left++
				}
				for left<right&&nums[right]==nums[right-1]{
					right--
				}
				left++
				right--
			}else if t<0{
				left++
			}else{
				right--
			}
		}

	}
	return ans

}
