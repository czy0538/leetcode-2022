package main

import "sort"

// 小根堆法

// import "container/heap"

// type Pair struct {
// 	First  int
// 	Second int
// }

// type PairHeap []Pair

// func (p PairHeap) Len() int {
// 	return len(p)
// }
// func (p PairHeap) Less(i, j int) bool {
// 	return p[i].Second < p[j].Second
// }

// func (p PairHeap) Swap(i, j int) {
// 	p[i], p[j] = p[j], p[i]
// }

// func (p *PairHeap) Pop() (x any) {
// 	x = (*p)[len(*p)-1]
// 	*p = (*p)[:len(*p)-1]
// 	return x
// }

// func (p *PairHeap) Push(x any) {
// 	*p=append(*p, x.(Pair))
// }

// func topKFrequent(nums []int, k int) []int {
// 	count:=make(map[int]int)
// 	for _,v:=range nums{
// 		count[v]++
// 	}

// 	h := &PairHeap{}
// 	heap.Init(h)
// 	for f,s:= range count{
// 		heap.Push(h,Pair{f,s})
// 		if h.Len()>k{
// 			heap.Pop(h)
// 		}
// 	}

// 	var ans []int
// 	for h.Len()>0{
// 		ans = append(ans, heap.Pop(h).(Pair).First)
// 	}
// 	return ans

// }

// sort 排序法

func topKFrequent(nums []int, k int) []int {
	count :=make(map[int]int)
	var index []int
	for _,v:=range nums{
		count[v]++
	}

	for v:=range count{
		index = append(index, v)
	}
	sort.Slice(index,func(i,j int)bool{
		return count[index[i]]>count[index[j]]
	})
	return index[:k]

}
