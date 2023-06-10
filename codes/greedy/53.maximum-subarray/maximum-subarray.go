package main
func maxSubArray(nums []int) int {
	result:=math.MinInt
	count:=0
	for _,i:=range nums{
		count+=i
		result=max(result,count)
		if count<0{
			count=0
		}

	}
	return result

}

func max(a,b int)int{
	if a>=b{
		return a
	}
	return b
}