package main
import "fmt"
func main(){
    n:=0
    fmt.Scanf("%d",&n)
    nums:=make([]int,n)
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&nums[i])
    }
    qsort(nums,0,n-1)
    for _,i:= range nums{
        fmt.Printf("%d ",i)
    }
}

func qsort(nums []int,l,r int){
    if l>=r{
        return
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
    qsort(nums,l,j)
    qsort(nums,j+1,r)

}