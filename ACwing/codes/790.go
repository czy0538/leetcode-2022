package main

import "fmt"

func main() {
	var n float64
	fmt.Scanf("%f", &n)

	l := -10000.0
	r := 10000.0
	eps := 1e-8
	for r-l > eps {
		mid := (l + r) / 2
		if mid*mid*mid < n {
			l = mid
		} else {
			r = mid
		}
	}
	fmt.Printf("%.6f", l)
}
