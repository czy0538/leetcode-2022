package main
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}


func hasPathSum(root *TreeNode, targetSum int) bool {
    if root==nil{
        return false
    }
    return dfs(root,targetSum)
}
func dfs(root* TreeNode,targetSum int)bool{
    if root==nil{
        return false
    }
    targetSum-=root.Val
    if root.Left==nil && root.Right==nil&&targetSum==0{
        return true
    }
    return dfs(root.Left,targetSum)||dfs(root.Right,targetSum)
}