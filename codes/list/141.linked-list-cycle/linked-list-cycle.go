package main

type ListNode struct {
    Val int
    Next *ListNode
}

func hasCycle(head *ListNode) bool {
	for slow,fast:=head,head;fast!=nil&&fast.Next!=nil;{
		fast=fast.Next.Next
		slow=slow.Next
		if fast==slow{
			return true
		}
	}
	return false
}