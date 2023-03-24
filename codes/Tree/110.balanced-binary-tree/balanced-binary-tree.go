package main


type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	if root==nil {
		return true
	}
	if countHeight(root)==-1{
		return false
	}
	return true
}

func countHeight(node *TreeNode) int {
	if node == nil {
		return 0
	}
	leftHeight := countHeight(node.Left)
	if leftHeight == -1 {
		return -1
	}
	rightHeight := countHeight(node.Right)
	if rightHeight == -1 {
		return -1
	}

	if abs(leftHeight-rightHeight) > 1 {
		return -1
	}
	return max(leftHeight, rightHeight) + 1
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a

}

func max(a,b int)int{
	if a<b{
		return b
	}
	return a
}