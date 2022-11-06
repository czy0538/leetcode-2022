package main
func moveZeroes(nums []int)  {
	if len(nums)<=1{
		return
	}
	i:=0
	for j:=0;j<len(nums);{
		if nums[j]==0{
			j++
		}else{
			nums[i]=nums[j]
			i++
			j++
		}
	}
	for ;i<len(nums);i++{
		nums[i]=0
	}
}