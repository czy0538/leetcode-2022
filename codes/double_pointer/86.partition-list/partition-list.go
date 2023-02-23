package main



type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	l := &ListNode{}
	be := &ListNode{}
	i := l
	j := be
	for head != nil {
		if head.Val < x {
			i.Next = head
			i = i.Next
		} else {
			j.Next = head
			j = j.Next
		}
		head = head.Next
	}
	j.Next = nil
	i.Next = be.Next
	return l.Next

}
