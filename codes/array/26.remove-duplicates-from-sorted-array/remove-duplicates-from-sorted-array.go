package main
func removeDuplicates(nums []int) int {
	i:=0
	for j:=0;j<len(nums);i++{
		nums[i]=nums[j]
        for j<len(nums)&&nums[i]==nums[j]{
            j++
        }

	}
	return i
}