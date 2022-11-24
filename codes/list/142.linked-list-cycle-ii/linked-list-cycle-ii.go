package main

type ListNode struct {
    Val int
    Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	fast:=head
	slow:=head
	for fast!=nil&&fast.Next!=nil{
		fast=fast.Next.Next
		slow=slow.Next
		if slow==fast{
			goto CYCLED
		}
	}
	return nil

	CYCLED:
	slow=head
	for slow!=fast{
		slow=slow.Next
		fast=fast.Next
	}
	return slow
}