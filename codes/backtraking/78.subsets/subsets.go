package main

func subsets(nums []int) [][]int {
	var result [][]int
	var path []int
	var backtracing func(int)

	backtracing = func(beg int) {
		if beg == len(nums) {
			return
		}
		for i := beg; i < len(nums); i++ {
			path = append(path, nums[i])
			result = append(result, append([]int{}, path...))
			backtracing(i + 1)
			path = path[:len(path)-1]
		}
	}

	result = append(result, []int{})
	backtracing(0)
	return result
}
