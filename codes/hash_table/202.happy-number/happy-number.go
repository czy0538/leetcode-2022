package main

func isHappy(n int) bool {
	history := make(map[int]bool)
	tmp := 0
	getTmp := func() {
		for n != 0 {
			t := n % 10
			tmp += t * t
			n /= 10
		}
	}
	for {
		getTmp()
		if tmp == 1 {
			return true
		} else {
			if history[tmp] {
				return false
			} else {
				history[tmp] = true
				n = tmp
				tmp = 0
			}
		}
	}
}
