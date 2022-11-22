package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	curA := headA
	curB := headB
	var lenA, lenB int
	for ; curA != nil; curA = curA.Next {
		lenA++
	}
	for ; curB != nil; curB = curB.Next {
		lenB++
	}
	curA = headA
	curB = headB
	if lenA < lenB {
		curA, curB = curB, curA
		lenA, lenB = lenB, lenA
	}
	gap := lenA - lenB
	for ; gap > 0; gap-- {
		curA = curA.Next
	}
	for curA!=nil{
		if curA==curB{
			return curA
		}
		curA=curA.Next
		curB = curB.Next
	}
	return nil

}
