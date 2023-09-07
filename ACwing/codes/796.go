// package main
// import "fmt"
// const N=1e3+10
// 该方法默认算法上是没问题的，但是会超时，因为go的垃圾scanf看起来跟c++一样，但是实际上性能差了很多
// func main(){
//     var n,m,q int
//     var x1,x2,y1,y2 int
//     var s,a [N][N]int
//     fmt.Scanf("%d%d%d",&n,&m,&q)
//     for i:=1;i<=n;i++{
//         for j:=1;j<=m;j++{
//             fmt.Scanf("%d",&a[i][j])
//             s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]
//         }
//     }
//     for ;q>0;q--{
//         fmt.Scanf("%d%d%d%d",&x1,&y1,&x2,&y2)
//         fmt.Println(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1])
//     }

// }

// 因此，我们可以使用bufio来加速输入

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	const N = 1010
	var n, m, q int
	var a = [N][N]int{}
	var s = [N][N]int{}

	fmt.Scanf("%d%d%d", &n, &m, &q)

	scanner := bufio.NewScanner(os.Stdin) // 实例化 Scanner

	for i := 1; i <= n; i++ {
		scanner.Scan() // Scan 方法 该方法好比 iterator 中的 Next 方法
		line := strings.Split(scanner.Text(), " ")
		for j := 1; j <= m; j++ {
			a[i][j], _ = strconv.Atoi(line[j-1])
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j] // 求前缀和
		}
	}

	var x1, y1, x2, y2 int
	var ll [4]int

	for q > 0 {
		q--
		scanner.Scan()
		temp := strings.Split(scanner.Text(), " ")
		for i, s := range temp {
			ll[i], _ = strconv.Atoi(s)
		}
		x1, y1, x2, y2 = ll[0], ll[1], ll[2], ll[3]

		fmt.Printf("%d\n", s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]) // 算子矩阵的和
	}
}
