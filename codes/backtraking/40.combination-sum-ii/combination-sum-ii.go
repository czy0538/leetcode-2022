package main

import "sort"

func combinationSum2(candidates []int, target int) [][]int {
	var result [][]int
	var path []int
	var backtracing func(int, int)
	backtracing = func(beg, target int) {
		if beg >= len(candidates) {
			return
		}
		for i := beg; i < len(candidates); i++ {
			if i != beg && candidates[i] == candidates[i-1] {
				continue
			}
			target -= candidates[i]
			if target < 0 {
				return
			}
			path = append(path, candidates[i])
			if target == 0 {
				result = append(result, append([]int{}, path...))
				path = path[:len(path)-1]
				return
			}

			backtracing(i+1, target)
			path = path[:len(path)-1]
			target += candidates[i]
		}
	}

	sort.Ints(candidates)
	backtracing(0,target)
	return result

}
