package main

// 这个题目就是求解最多拥有两种数字，然后求解两种数字混合组成的子序列长度，找到最大的那个
// 每次移动如果移动后元素不在数组中，则加入，如果数组满了，则两个数都要舍弃

// 滑动窗口，但是没有用map
// func totalFruit(fruits []int) int {
// 	var backet []int
// 	var size int
// 	i:=0
// 	j:=0
// 	for ;j<len(fruits);j++{
// 		switch len(backet){
// 		case 0:
// 			backet = append(backet, fruits[j])
// 		case 1:
// 			if backet[0]!=fruits[j]{
// 				backet = append(backet, fruits[j])
// 			}
// 		case 2:
// 			// 这里与用哈希表相比不好的一点在于直接清理了整个bucket，因为我们没有利用每个篮子有几个水果的信息
// 			// 对于 1 2 3 2 这种情况，会浪费一些时间，因为这里我们只需要清理到第一个能使篮子里剩下一个的即可
// 			if backet[0]!=fruits[j]&&backet[1]!=fruits[j]{
// 				backet=backet[:0]
// 				if j-i >size{
// 					size = j-i
// 				}

// 				// 右移计算下一个子序列，直接跳转到左边第一个元素不同的即可
// 				for t:=fruits[i];i<len(fruits);i++{
// 					if t!=fruits[i]{
// 						backet = append(backet, fruits[i])
// 						break
// 					}
// 				}
// 				j=i;
// 			}
// 		}
// 	}
// 	if j-i>size{
// 		size=j-i
// 	}
// 	return size
// }

// map版本
func totalFruit(fruits []int) int {
	//var bucket map[int]int // 这样创建的map是nil的，不能直接插入元素

	bucket:=make(map[int]int)
	size := 0
	i := 0
	j := 0
	for ; j < len(fruits); j++ {
		bucket[fruits[j]]++
		for ;len(bucket) > 2;i++ {
			if size<j-i{
				size=j-i
			}
			bucket[fruits[i]]--
			if bucket[fruits[i]] == 0 {
				delete(bucket, fruits[i])
			}
		}
	}
	if j-i>size{
		size=j-i
	}
	return size
}
