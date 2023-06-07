package main

import (
	"strconv"
)

func restoreIpAddresses(s string) []string {
	var result []string
	var path []byte

	isValid := func(s string) bool {
		if len(s) < 0 || len(s) > 3 {
			return false
		}
		if len(s) > 1 && s[0] == '0' {
			return false
		}
		if num, err := strconv.Atoi(s); err != nil || num > 255 {
			return false
		}
		return true
	}

	var backtracing func(int, int)

	backtracing = func(beg int, layer int) {
		if layer < 0 {
			return
		}
		if layer == 0 {
			if beg >= len(s) {
				result = append(result, string(path[:len(path)-1]))
				return
			}
		}

		for i := beg; i < beg+3 && i < len(s); i++ {
			if isValid(s[beg : i+1]) {
				path = append(path, s[beg:i+1]...)
				path = append(path, '.')
				backtracing(i+1, layer-1)
				path = path[:len(path)-(i-beg+1)-1]
			} else {
				return
			}
		}

	}
	backtracing(0, 4)
	return result
}
