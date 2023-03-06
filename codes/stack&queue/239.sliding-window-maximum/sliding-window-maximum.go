package main

type Queue struct {
	d []int
}

func (q *Queue) PushBack(val int) {
	for len(q.d) != 0 && q.d[len(q.d)-1] < val {
		q.d = q.d[:len(q.d)-1]
	}
	q.d = append(q.d, val)
}

func (q *Queue) PopFront(val int) {
	if len(q.d) != 0 && q.d[0] == val {
		q.d = q.d[1:len(q.d)]
	}
}

func (q *Queue) Front() int {
	return q.d[0]
}
func maxSlidingWindow(nums []int, k int) []int {
	var q Queue
	var ans []int
	for i := 0; i < k; i++ {
		q.PushBack(nums[i])
	}
	ans = append(ans, q.Front())

	for i := k; i < len(nums); i++ {
		q.PopFront(nums[i-k])
		q.PushBack(nums[i])
		ans = append(ans, q.Front())
	}

	return ans

}
