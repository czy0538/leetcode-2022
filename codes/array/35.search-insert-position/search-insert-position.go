package main

// 2023年07月08日
// 找的是左边界，自然是要插入的地方
// 注意这样无法处理的是如果需要在尾后插入，
// 因为 l 不可能是一个越界的。因此此时就要在开头处理下比最后一个元素还大的情况
func searchInsert(nums []int, target int) int {
    if target <nums[0]{
        return 0
    }
    if target>nums[len(nums)-1]{
        return len(nums)
    }
    l:=0
    r:=len(nums)-1
    for l<r{
        mid:=(l+r)/2
        if nums[mid]>=target{
            r=mid
        }else{
            l=mid+1
        }
    }
    return l


}

// // 左闭右闭版本
// func searchInsert(nums []int, target int) int {
// 	l := 0
// 	r := len(nums) - 1
// 	i := (l + r) / 2

// 	for l <= r {
// 		if nums[i] < target {
// 			l = i + 1
// 		} else if nums[i] > target {
// 			r = i - 1
// 		} else {
// 			break
// 		}
// 		i = (l + r + 1) / 2
// 	}

// 	return i
// }
