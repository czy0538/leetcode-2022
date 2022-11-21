package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	ptr := new(ListNode)
	ptr.Next = head
	l := ptr
	r := ptr
	for ; n > 0; n-- {
		r = r.Next

	}
	for ; r.Next != nil; r = r.Next {
		l = l.Next
	}
	l.Next = l.Next.Next
	return ptr.Next
}
