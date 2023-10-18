package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 1e6

var a, q [N]int

func main() {
	var n, k int

	fmt.Scanf("%d%d", &n, &k)
	// 大量数据注意读取问题
	sc := bufio.NewScanner(os.Stdin)
	bs := make([]byte, N*64/8)
	sc.Buffer(bs, len(bs))
	sc.Scan()
	line := strings.Split(sc.Text(), " ")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(line[i])
	}
	

	var hh, ed int
	for i := 0; i < n; i++ {
		if q[hh] <= i-k {
			hh++
		}
		for ed > hh && a[q[ed-1]] > a[i] {
			ed--
		}
		q[ed] = i
		ed++
		if i+1 >= k {
			fmt.Printf("%d ", a[q[hh]])
		}
	}
	fmt.Println("")
	hh, ed = 0, 0
	for i := 0; i < n; i++ {
		if q[hh] <= i-k {
			hh++
		}
		for ed > hh && a[q[ed-1]] < a[i] {
			ed--
		}
		q[ed] = i
		ed++
		if i+1 >= k {
			fmt.Printf("%d ", a[q[hh]])
		}
	}

}
