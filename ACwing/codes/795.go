package main
import (
    "fmt"
)

func main(){
    var n,m,l,r int
    fmt.Scanf("%d %d",&n,&m)
    nums:=make([]int,n+1)
    s:=make([]int,n+1)
	// 一定注意下标从1开始的
    for i:=1;i<=n;i++{
        fmt.Scanf("%d",&nums[i])
        s[i]=s[i-1]+nums[i]
    }
    for ;m>0;m--{
        fmt.Scanf("%d %d",&l,&r)
        fmt.Println(s[r]-s[l-1])
    }
}