package main

import "math"

func minSubArrayLen(target int, nums []int) int {
	i := 0
	j := 0
	sum := 0
	size := math.MaxInt
	for j < len(nums) {
		sum += nums[j]
		for i<=j&&sum >= target{
			if sum-nums[i]>=target{
				sum-=nums[i]
				i++
			}else{
				break
			}
		}
		if sum>=target&&j-i+1<size{
			size=j-i+1
		}
		j++
	}
	if size==math.MaxInt{
		return 0
	}else{
		return size
	}

}
