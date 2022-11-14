package main

func generateMatrix(n int) [][]int {
	// go的多维slice的初始化只能这样，内层的需要遍历初始化
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, n)
	}

	startX := 0
	startY := 0
	loop := n / 2 // int的除法仍为int
	count := 1
	offset := 1

	for ; loop > 0; loop-- {
		i := startX
		j := startY
		for ; i < n-offset; i++ {
			ans[j][i] = count
			count++
		}

		for ; j < n-offset; j++ {
			ans[j][i] = count
			count++
		}

		for ; i > startX; i-- {
			ans[j][i] = count
			count++
		}

		for ; j > startY; j-- {
			ans[j][i] = count
			count++
		}

		startX++
		startY++
		offset++

	}
	if n%2 == 1 {
		ans[startY][startX] = count
	}

	return ans
}
