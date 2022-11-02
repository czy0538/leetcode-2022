package main

// 可以看做[0,x]的二分查找，认为这样只能是左闭右闭的版本，否则无法处理为1的情况
// 只保留整数可以看做当前数<=x,+1以后大于x
func mySqrt(x int) int {
	l := 0
	r := x
	mid := x / 2
	for l <= r {
		t := mid * mid
		if t <= x && t+mid<<1+1 > x {
			break
		} else if t < x {
			l = mid + 1
		} else {
			r = mid - 1
		}
		mid = (l + r) / 2
	}
	return mid
}
