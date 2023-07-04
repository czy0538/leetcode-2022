package main
import "fmt"

func qsort(q []int,l,r int){
    if(l>=r){
        return
    }
    x:=q[(l+r)>>1]
    i:=l-1
    j:=r+1
    for i<j{
        i++
        for q[i]<x{
            i++
        }
        j--
        for q[j]>x{
            j--
        }
        if i<j{
            q[i],q[j]=q[j],q[i]
        }
    }
    qsort(q,l,j)
    qsort(q,j+1,r)

}

func main(){
    n:=0
    fmt.Scanf("%d",&n)
    q:=make([]int,n)
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&q[i])
    }
    qsort(q,0,n-1)
    for _,i:=range q{
        fmt.Printf("%d ",i)
    }
}