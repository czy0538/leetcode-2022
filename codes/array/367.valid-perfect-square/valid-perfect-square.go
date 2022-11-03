package main

func isPerfectSquare(num int) bool {
	l:=0
	r:=num
	mid:=(l+r)>>1
	for l<=r{
		t:=mid*mid
		if t<num{
			l=mid+1
		}else if t>num{
			r=mid-1
		}else{
			return true
		}
		mid=(l+r)>>1
	}
	return false
}
