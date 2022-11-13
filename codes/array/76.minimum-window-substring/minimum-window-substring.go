package mian

import "math"

func minWindow(s string, t string) string {
	dic := make(map[byte]int)
	ans := make(map[byte]int)
	for i := 0; i < len(t); i++ {
		dic[t[i]]++
	}

	size := math.MaxInt
	beg := 0
	cnt := 0
	for i, j := 0, 0; j < len(s); j++ {
		ans[s[j]]++
		if ans[s[j]] <= dic[s[j]] {
			cnt++
		}
		for i <= j && ans[s[i]] > dic[s[i]] {
			ans[s[i]]--
			i++
		}
		if cnt == len(t) && j-i+1 < size {
			size = j - i + 1
			beg = i
		}
	}
	if size == math.MaxInt {
		return s[:0]
	} else {
		return s[beg : beg+size]
	}
}
