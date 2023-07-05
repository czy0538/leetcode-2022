package main
import "fmt"

var tmp []int

func mergeSort(nums []int,l,r int){
    if l>=r{
        return
    }
    mid:=(l+r)>>1
    mergeSort(nums,l,mid)
    mergeSort(nums,mid+1,r)

    i:=l
    j:=mid+1
    k:=l

    for i<=mid&&j<=r{
        if nums[i]<=nums[j]{
            tmp[k]=nums[i]
            i++
        }else{
            tmp[k]=nums[j]
            j++
        }
        k++
    }
    for i<=mid{
        tmp[k]=nums[i]
        k++
        i++
    }
    for j<=r{
        tmp[k]=nums[j]
        k++
        j++
    }

    for i:=l;i<=r;i++{
        nums[i]=tmp[i]
    }
}

func main(){
    n:=0
    fmt.Scanf("%d",&n)
    nums:=make([]int,n)
    tmp=make([]int,n)
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&nums[i])
    }
    mergeSort(nums,0,n-1)
    for _,i:=range nums{
        fmt.Printf("%d ",i)
    }
}

// 借助 go slice 浅拷贝特性，也可以这样写
func mergeSort2(nums []int){
    if len(nums)<=1{
        return
    }
    mid:=(len(nums)-1)>>1 // 这里也是要-1
	// 一定注意这里，切片时候取得是左闭右开
    mergeSort(nums[:mid+1])
    mergeSort(nums[mid+1:])

    i:=0
    j:=mid+1
    k:=0

    for i<=mid&&j<len(nums){
        if nums[i]<=nums[j]{
            tmp[k]=nums[i]
            i++
        }else{
            tmp[k]=nums[j]
            j++
        }
        k++
    }
    for i<=mid{
        tmp[k]=nums[i]
        k++
        i++
    }
    for j<len(nums){
        tmp[k]=nums[j]
        k++
        j++
    }

    for i:=0;i<len(nums);i++{
        nums[i]=tmp[i]
    }
}