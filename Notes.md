# 排序

排序的算法有很多，后面再整理。

大部分的题目中其实我们都只需要掉标准库就可以了。

c++的标准库封装的非常的好，但是 go 的就很麻烦了。这里也一并总结。

## c++

在 c++引入 lambda 表达式以后，sort 的自定义变得非常的简单

```c++
#include<algorithm>
sort(activities.begin(), activities.end(), [](auto &a,auto &b)->bool{return (a.endTime < b.endTime);});
```

需要注意对于 cmp 的写法：The return value of the function call operation applied to an object of a type satisfying *Compare*, when [contextually converted](https://en.cppreference.com/w/cpp/language/implicit_conversion) to bool, yields true if the first argument of the call appears before the second in the **[strict weak ordering relation](https://en.wikipedia.org/wiki/Strict_weak_ordering)** induced by this type, and false otherwise.

sort接受三个变量，开始迭代器，尾后迭代器（也可以是指针，c++20 开始提供了 [constrained](https://en.cppreference.com/w/cpp/language/constraints) 的版本，但是一般来说可能没有这么高级别的编译器）和一个 Less 函数。注意这里的 Less函数是严格小于！一定是严格小于，不能是小于等于！如果我们想要降序的，大于对于我们来说就是小于。

这里的 sort 是不稳定排序的，如果想要处理稳定的，有两种办法，一种是把原来的数组扩充成一个 pair，把元素位置也加入进来。

另一种是可以通过`stable_sort`，用法和 sort 相同。

此外还有其他一些函数，这里不重复了。

## go

相比于 c++，go 中进行排序就要麻烦多了！~这里我们只考虑标准库，不去管其他的库。

go sort 中共有如下的函数，我们先不看type

### 内置的排序

标准库仅仅内置了`float64`、`int`、`string`类型 Slice 的升序排序。

```go
func Float64s(x []float64)
func Ints(x []int)
func Strings(x []string)

func Float64sAreSorted(x []float64) bool
func IntsAreSorted(x []int) bool
func StringsAreSorted(x []string) bool
```

此外，针对其他类型的 Slice，我们只需要提供 Less 函数即可。

```go
//added in go1.8
func Slice(x any, less func(i, j int) bool)
func SliceStable(x any, less func(i, j int) bool)
func SliceIsSorted(x any, less func(i, j int) bool) bool

func main() {
	people := []struct {
		Name string
		Age  int
	}{
		{"Gopher", 7},
		{"Alice", 55},
		{"Vera", 24},
		{"Bob", 75},
	}
	sort.Slice(people, func(i, j int) bool { return people[i].Name < people[j].Name })
	fmt.Println("By name:", people)

	sort.Slice(people, func(i, j int) bool { return people[i].Age < people[j].Age })
	fmt.Println("By age:", people)
}

```

在 go 1.18 之前，我们需要实现如下接口，例子参考[sort package - sort - Go Packages](https://pkg.go.dev/sort#Interface)

```go
type Interface interface {
	// Len is the number of elements in the collection.
	Len() int

	// Less reports whether the element with index i
	// must sort before the element with index j.
	//
	// If both Less(i, j) and Less(j, i) are false,
	// then the elements at index i and j are considered equal.
	// Sort may place equal elements in any order in the final result,
	// while Stable preserves the original input order of equal elements.
	//
	// Less must describe a transitive ordering:
	//  - if both Less(i, j) and Less(j, k) are true, then Less(i, k) must be true as well.
	//  - if both Less(i, j) and Less(j, k) are false, then Less(i, k) must be false as well.
	//
	// Note that floating-point comparison (the < operator on float32 or float64 values)
	// is not a transitive ordering when not-a-number (NaN) values are involved.
	// See Float64Slice.Less for a correct implementation for floating-point values.
	Less(i, j int) bool

	// Swap swaps the elements with indexes i and j.
	Swap(i, j int)
}
```



### 二分查找 Find 和 Search

```go
func Find(n int, cmp func(int) int) (i int, found bool)//added in go1.19
```

Find使用二分查找来找到并返回在[0，n)范围内满足**cmp(i) <= 0的最小索引i**。

如果不存在这样的索引i，则Find返回i = n。如果i < n且cmp(i) == 0，则找到的结果为true。

Find仅对范围[0，n)中的i调用cmp(i)。

为了允许二分查找，Find要求范围的前缀具有cmp(i)> 0，中间部分具有cmp(i)== 0，并且范围的后缀具有cmp(i)< 0。（每个子范围可能为空）。建立这种条件的常见方法是将cmp（i）解释为所需目标值t与底层索引数据结构x中条目i之间进行比较，在t < x[i]时返回<0，在t == x[i]时返回0，在t > x[i]时返回> 0。

总结下：

- 如果 返回的 `i==n`，说明没找到。
- `i!=n`则说明找到了一个元素，这个元素**cmp(i) <= 0的最小索引i**。这个可能是比较方便我们来找到某个元素的插入位置用的。
- 如果i < n且cmp(i) == 0，则找到的结果为true。如果我们要找一个确定的元素的话可以这样判断。

比如说我们要找到数组中某个元素的位置，如果没有这个元素的话就找他的插入位置。借助 found 还能进一步判断是不是该元素。

```go
func main() {
	nums := []int{3, 2, 1, 4, 5}
	sort.Ints(nums)
	fmt.Println(searchInsert(nums, 0)) //0
	fmt.Println(searchInsert(nums, 2)) //1
	fmt.Println(searchInsert(nums, 5)) //4
	fmt.Println(searchInsert(nums, 7)) //5

}

func searchInsert(nums []int, target int) int {
	i, _ := sort.Find(len(nums), func(i int) int {
		return target - nums[i]
	})
	return i

}
```



```go
func Search(n int, f func(int) bool) int

x := 23
i := sort.Search(len(data), func(i int) bool { return data[i] >= x })
if i < len(data) && data[i] == x {
	// x is present at data[i]
} else {
	// x is not present in data,
	// but i is the index where it would be inserted.
}
```

Search使用二分查找来找到并返回满足条件 f(i) 为真的最小索引 i，假设在范围 [0, n) 上，f(i) == true 意味着 f(i+1) == true。也就是说，搜索要求在输入范围 [0, n) 的某个（可能为空）前缀上 f 是 false，并且在剩余部分上是 true；搜索返回第一个为真的索引。如果没有这样的索引，则返回 n。（注意，“未找到”时的返回值不像 strings.Index 那样是 -1）。搜索仅对范围 [0, n) 中的 i 调用 f(i)。

Search 的常见用途是在排序、可索引的数据结构（如数组或切片）中查找值 x 的索引 i。在这种情况下，参数 f 通常是一个闭包，捕获要搜索的值以及数据结构如何被索引和排序。

例如，在升序排列的切片 data 中调用 Search(len(data), func(i int) bool { return data[i] >= 23 }) 将返回最小索引 i，使得 data[i] >= 23。如果调用者想要确定切片中是否存在 23，则必须单独测试 data[i] == 23。

对于降序排列的数据进行搜索将使用 <= 运算符而不是 >= 运算符。

