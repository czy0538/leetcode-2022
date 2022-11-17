package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// // 迭代+闭包版本
// func removeElements(head *ListNode, val int) *ListNode {
// 	var remove func(ptr *ListNode)
// 	remove=func(ptr *ListNode){
// 		if ptr.Next==nil{
// 			return
// 		}
// 		if ptr.Next.Val==val{
// 			// 不用释放内存，gc
// 			ptr.Next=ptr.Next.Next
// 			remove(ptr)
// 		}else{
// 			remove(ptr.Next)
// 		}
// 	}
// 	p:=new(ListNode)
// 	p.Next=head
// 	remove(p)
// 	return p.Next
// }

// 正常的版本
func removeElements(head *ListNode, val int) *ListNode {
	p:=new(ListNode)
	p.Next=head
	head=p
	for head.Next!=nil{
		if head.Next.Val==val{
			head.Next=head.Next.Next
			// 不用删除，gc
		}else{
			head=head.Next
		}
	}
	return p.Next
}