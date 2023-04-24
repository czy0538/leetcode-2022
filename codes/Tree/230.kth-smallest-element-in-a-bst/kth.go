package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func kthSmallest(root *TreeNode, k int) int {
	var dfs func(*TreeNode)
	ans:=0
	dfs=func(root *TreeNode){
		if root==nil{
			return
		}
		dfs(root.Left)
		k-=1
		if k==0{
			ans=root.Val
			return
		}
		dfs(root.Right)
	}
	dfs(root)
	return ans

}
