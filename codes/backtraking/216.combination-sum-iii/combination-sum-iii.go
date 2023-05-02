package main
func combinationSum3(k int, n int) [][]int {
    var result [][]int
    var path []int
    var dfs func(int,int,int)
    dfs=func(k,n,beg int){
        if k==0||beg>9{
            return
        }
        for i:=beg;i<=9;i++{
            val:=n-i
            if val<0||k!=1&&val==0{
                return
            }
            path=append(path,i)
            if k==1&&val==0{
                result=append(result,append([]int{},path...))
                path=path[:len(path)-1]
                return
            }
            dfs(k-1,val,i+1)
            path=path[:len(path)-1]
        }
    }
    dfs(k,n,1)
    return result

}