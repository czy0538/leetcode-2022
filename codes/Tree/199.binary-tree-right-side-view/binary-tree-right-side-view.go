package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	var q []*TreeNode
	var result []int
	if root == nil {
		return result
	}
	q = append(q, root)
	for len(q) != 0 {
		n := len(q)
		for i := 0; i < n; i += 1 {
			cur := q[i]
			if i == n-1 {
				result = append(result, q[i].Val)
			}
			if cur.Left != nil {
				q = append(q, cur.Left)
			}
			if cur.Right != nil {
				q = append(q, cur.Right)
			}
		}
		q = q[n:]
	}
	return result
}
