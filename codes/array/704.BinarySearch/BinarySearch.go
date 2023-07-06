package main

import "fmt"

// 左闭右开版本
func search(nums []int, target int) int {
	
	l := 0
	r := len(nums)
	i := (l + r) / 2
	if target < nums[0] || target > nums[len(nums)-1] {
		return -1
	}
	for l < r {
		if nums[i] == target {
			return i
		} else if nums[i] < target {
			l = i + 1
		} else {
			r = i
		}
		i = (l + r) / 2
	}
	return -1
}

func main(){
	nums:=[]int{-1,0,3,5,9,12}
	fmt.Println(search(nums,9))
}