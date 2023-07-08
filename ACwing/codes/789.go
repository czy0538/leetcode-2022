package main
import "fmt"

func main(){
    var n,q int
    fmt.Scanf("%d %d",&n,&q)
    nums:=make([]int,n)
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&nums[i])
    }


    var target,left int
    for ;q>0;q--{
         l:=0
         r:=n-1
        fmt.Scanf("%d",&target)
        for l<r{
            mid:=(l+r)/2
            if nums[mid]>=target{
                r=mid
            }else{
                l=mid+1
            }
        }
        if nums[l]!=target{
            fmt.Printf("-1 -1\n")
            continue
        }
        left = l
        r=n-1
        for l<r{
            mid:=(l+r+1)/2
            if nums[mid]<=target{
                l=mid
            }else{
                r=mid-1
            }
        }
        fmt.Printf("%d %d\n",left,r)
    }

}