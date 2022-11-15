package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func spiralOrder(matrix [][]int) []int {
	sizeY := len(matrix)
	sizeX := len(matrix[0])
	ans := make([]int, 0, sizeX*sizeY)
	offsetX := 1
	offsetY := 1
	startX := 0
	startY := 0
	loop := min(sizeX, sizeY) / 2

	for ; loop > 0; loop-- {
		x := startX
		y := startY
		for ; x < sizeX-offsetX; x++ {
			ans = append(ans, matrix[y][x])
		}
		for ; y < sizeY-offsetY; y++ {
			ans = append(ans, matrix[y][x])
		}
		for ; x > startX; x-- {
			ans = append(ans, matrix[y][x])
		}
		for ; y > startY; y-- {
			ans = append(ans, matrix[y][x])
		}
		startX++
		startY++
		offsetX++
		offsetY++
	}


	if startX==sizeX-offsetX&&startY==sizeY-offsetY{
		ans = append(ans, matrix[startY][startX])
	}else if startX==sizeX-offsetX {
		for startY<=sizeY-offsetY{
			ans = append(ans, matrix[startY][startX])
			startY++
		}
	}else if startY==sizeY-offsetY {
		for startX<=sizeX-offsetX{
			ans = append(ans, matrix[startY][startX])
			startX++
		}
	}

	return ans
}
