package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 这个题整体思路和上个一样，但是要注意两点：
// 1. go 的全局变量这里要用闭包的形式
// 2. go 的 slice 是引用类型，如果简单的 append 进去，后续回溯时候会修改掉当前的结果，需要进行复制
// 可以用 copy 函数显式处理，也可以进行 append 一个新的slice 中，本质上是需要复制一份的
func pathSum(root *TreeNode, targetSum int) [][]int {
    var result [][]int
    var path []int
    var dfs func(root* TreeNode,targetSum int)
    dfs=func(root* TreeNode,targetSum int){
        if root==nil{
            return
        }
        targetSum-=root.Val
        path=append(path,root.Val)
        if root.Left==nil && root.Right==nil&&targetSum==0{
            // curPath:=make([]int,len(path))
            // copy(curPath,path)
            // result=append(result,curPath)
            result=append(result,append([]int{},path...))
        }else{
            dfs(root.Left,targetSum)
            dfs(root.Right,targetSum)
        }
        path=path[:len(path)-1]
    }

    if root==nil{
        return result
    }
    dfs(root,targetSum)
    return result
}

