package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	maxSum := math.MinInt
	var maxTreeVal func(root *TreeNode) int
	maxTreeVal = func(root *TreeNode) int {
		if root==nil{
			return math.MinInt
		}
		left:=MaxInt(maxTreeVal(root.Left),0)
		right:=MaxInt(maxTreeVal(root.Right),0)
		maxSum=MaxInt(maxSum,left+right+root.Val)
		return MaxInt(left,right)+root.Val
	}
	maxTreeVal(root)
	return maxSum
}

func MaxInt(li ...int) int {
	maxVal := math.MinInt
	for _,i := range li {
		if i > maxVal {
			maxVal = i
		}
	}
	return maxVal
}
