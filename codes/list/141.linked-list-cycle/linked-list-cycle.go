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

// 2023年07月11日，补充笨的办法
// func hasCycle(head *ListNode) bool {
//     flag:=make(map[*ListNode]struct{})
//     for i:=head;i!=nil;i=i.Next{
//         _,ok:=flag[i]
//         if ok{
//             return true
//         }
//         flag[i]=struct{}{}
//     }
//     return false
// }