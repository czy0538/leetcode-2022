package main

type Node struct {
	val  int
	next *Node
}

type MyLinkedList struct {
	head *Node
	size int
}

func Constructor() MyLinkedList {
	return MyLinkedList{new(Node), 0}
}

func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.size {
		return -1
	}
	ptr := this.head.next
	for i := index; i > 0; i-- {
		ptr = ptr.next
	}
	return ptr.val
}

func (this *MyLinkedList) AddAtHead(val int) {
	ptr := new(Node)
	ptr.val = val
	ptr.next = this.head.next
	this.head.next = ptr
	this.size++
}

func (this *MyLinkedList) AddAtTail(val int) {
	ptr := this.head
	for ptr.next != nil {
		ptr = ptr.next
	}
	ptr.next = new(Node)
	ptr.next.val = val
	this.size++

}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index <= 0 {
		this.AddAtHead(val)
	} else if index == this.size {
		this.AddAtTail(val)
	} else if index > this.size {
		return
	} else {
		ptr := this.head
		for i := index; i > 0; i-- {
			ptr = ptr.next
		}
		np := new(Node)
		np.next = ptr.next
		np.val = val
		ptr.next = np
		this.size++
	}

}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= this.size {
		return
	}
	ptr := this.head
	for i := index; i > 0; i-- {
		ptr = ptr.next
	}
	ptr.next = ptr.next.next
	this.size--

}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
