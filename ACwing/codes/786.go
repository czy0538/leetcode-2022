package main
import "fmt"
var n,k int
func main(){
    fmt.Scanf("%d %d",&n,&k)
    nums:=make([]int,n)
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&nums[i])
    }
    ans:=qsort(nums,0,n-1)
    fmt.Printf("%d",ans)
}

func qsort(nums []int,l,r int)int{
    if l>=r{
        return nums[r]
    }

    x:=nums[(l+r)>>1]
    i:=l-1
    j:=r+1
    for i<j{
        i++
        for nums[i]<x{
            i++
        }
        j--
        for(nums[j]>x){
            j--
        }
        if(i<j){
            nums[i],nums[j]=nums[j],nums[i]
        }
    }
    if j>=k-1{
        return qsort(nums,l,j)
    }
    return qsort(nums,j+1,r)


}