package main
func twoSum(nums []int, target int) []int {
	dict:=make(map[int]int)
	for k,v:=range nums{
		t:=target-v
		n,ok:=dict[t];
		if ok{
			return []int{k,n}
		}else{
			dict[v]=k;
		}
	}
	return []int{}

}