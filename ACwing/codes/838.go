package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 1e5 + 10

var h [N]int
var idx int

func down(x int) {
	t := x
	if x*2 <= idx && h[t] > h[x*2] {
		t = x * 2
	}

	if x*2+1 <= idx && h[t] > h[x*2+1] {
		t = x*2 + 1
	}
	if x != t {
		h[x], h[t] = h[t], h[x]
		down(t)
	}
}

func main() {

	sc := bufio.NewScanner(os.Stdin)
	bs := make([]byte, 2000*1024)
	sc.Buffer(bs, len(bs))
	sc.Scan()
	line := strings.Split(sc.Text(), " ")
	n, _ := strconv.Atoi(line[0])
	m, _ := strconv.Atoi(line[1])
	sc.Scan()
	line = strings.Split(sc.Text(), " ")
	for i := 1; i <= n; i++ {
		h[i], _ = strconv.Atoi(line[i-1])
	}
	idx = n

	for i := n / 2; i >= 1; i-- {
		down(i)
	}

	for i := 0; i < m; i++ {
		fmt.Printf("%d ", h[1])
		h[1] = h[idx]
		idx--
		down(1)
	}

}
