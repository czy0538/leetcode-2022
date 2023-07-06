# 第一章 基础算法

## 排序算法

稳定：归并排序

不稳定：快速排序 

### 快速排序O(nlogn)

- 确定分界点`x`（选择中间值比较好）
- **调整区间**，将数组划分成两个区间，使得第一个区间中的数都小于等于`x`，第二个区间中的数都大于等于`x`
- 递归的处理左右两段

![image-20230704184821025](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202307041848110.png)

**如何调整区间？**

- 暴力做法：开`a`、`b`两个数组，将<=`x`的放入`a`中，大于`x `的放入 `b `中，然后合并` ab`。需要额外开辟空间。

  ![image-20230704185049861](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202307041850886.png)

- **优美做法**：设置`i` `j`两个指针，初始时分别指向左右两个边界。如果`i`的值小于 `x`，则 `i++`，如果某个值`>=x`，则移动` j`，如果某个值大于 `x`，则` j--`，直到某个数小于` x`，此时交换`i`和`j`指向的数。直到两者相遇。



快排如何变成稳定的：pair<nums[i],i>

```c++
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
```



### 归并排序O(nlogn)

- 确定分界点：以数组的中间部分，将数组划分成左右两部分
- 递归排序左右
- **归并**：将左右两个有序序列合并成一个有序的数组

**如何合并两个序列？**

双指针算法。需要额外的空间。

![image-20230705214644739](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202307052146761.png)

![image-20230705214631371](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202307052146482.png)

```c++
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

```



## 二分查找

有单调性一定可以二分，没有单调性也有可能二分。两者并没有直接的关系。

**二分的本质是**：区间可以被一分为二，一边满足该性质，另一个不满足该性质，则二分可以找到该性质的边界。



### 整数二分

关注的点在于是找 l=mid 还是 r=mid，

如果是 l=mid，相当于找性质的右边界

如果是 r=mid，相当于找性质的左边界。 

二分法之前看过很多的资料，代码随想录里面按照是不是要取到右边界，进行了划分，那个适用面积不如acwing 的这个，因此统一到这里来。

acwing 的模版相当于**左右边界都是有效的**。

![image-20230706195909951](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202307061959978.png)

```c++
//查找左边界 SearchLeft 简写SL
int SL(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid; 
        else l = mid + 1; 
    }   
    return l;
}
//查找右边界 SearchRight 简写SR 
int SR(int l, int r) 
{
    while (l < r)
    {                   
        int mid = l + r + 1 >> 1; //需要+1 防止死循环
        if (check(mid)) l = mid;
        else r = mid - 1; 
    }
    return l; 
}
```

最后return 的时候 l和r都是可以 因为最后一定r==l(二分终止条件)

我们可以按照如下的思路思考该问题：

- 思考需要获得 check 条件的左边界还是右边界
- 如果是想要左边界，则为 true 时，需要修改 r=mid，因为要往左走。否则 l=mid+1，因为当前的 mid 不符合左边界要求。
- 如果是想要右边界，则为 true 时，需要修改 l=mid，因为想要往右走。否则 r=mid-1。因为当前 mid 不符合右边界要求。同时为了避免死循环，mid 应该是+1 的。



一个最简单的例子是：一个严格单调递增的数组中，找值为 target 的元素。

按照这个思路，我们可以分为

- 找`nums[mid]<=target`的右边界
- 找`nums[mid]>=target`的左边界

注意，该模板最后一定会返回一个结果l，我们还需要判断这个 l 是不是满足我们要求的。

https://leetcode.cn/problems/binary-search/description/

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/



### 浮点数二分

简单很多，不用考虑乱七八糟的边界。注意当小于某个范围 eps 后，就认为符合要求了。

```c++
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```



注意题目要求保留 x 位小数，则`eps=1e-(x+2)`













































