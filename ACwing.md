# 第一章 基础算法

## 排序算法

稳定：归并排序

不稳定：快速排序 

### 快速排序O(nlogn)

- 确定分界点`x`（选择中间值比较好）
- **调整区间**，将数组划分成两个区间，使得第一个区间中的数都小于等于`x`，第二个区间中的数都大于等于`x`（分界点的数并不一定==x)
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



## 前缀和

### 一维前缀和

对于 $a_1$ ... $a_n$，注意下标从1开始，可以方便的处理边界。

前缀和$s_i=a_1+...+a_i$

**如何求$s_i$**

```c++
s[0]=0;
for i=1;i<=n;i++{
  s[i]=s[i-1]+a[i];
}
```

**前缀和作用**

能快速的求出原数组中某段数[l,r]的和。时间复杂度O(1)

S[r]-S[l-1]



### 二维前缀和

快速求出子矩阵的和

![image-20230907215426175](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202309072154378.png)

S[i,j]=a[i,j]+s[i-1,j]+s[i,j-1]-s[i-1,j-1]

二维的在用go写的时候就要注意scanf的垃圾性能问题，可以用如下方法替代

bufio.NewScanner的底层buf数组有个最大缓存限制的，是64K，也就是说按照标准的Scan，一行最多64K的数据大小，题目里如果超过这个范围，比如一行20万数据，每个数据范围还是int32内的，那这就至少800K的大小了，还没算上中间的空格，所以默认的buf空间肯定是不够的，这时候需要调用Buffer方法，手动给Scanner分配一个满足题目空间的buf数组，其余照常。使用方法如下：

```go
sc := bufio.NewScanner(os.Stdin) // 实例化 NewScanner
bs := make([]byte, 2000*1024) // 缓存
sc.Buffer(bs, len(bs))
sc.Scan() // Scan 方法 该方法好比 iterator 中的 Next 方法，默认ScanLines 返回一行文本，不包括行尾的换行符
fmt.Println(sc.Text()) // 该方法应该在 Scan 调用后调用.Text 返回的是 string
line := strings.Split(scanner.Text(), " ")

for j := 1; j <= len(line); j++ { //把该行的数据再转为数字
            a[i][j], _ = strconv.Atoi(line[j-1])
}
```



## 差分

差分是前缀和的逆运算。

b数组是a数组的差分，a数组是b数组的前缀和。

<img src="https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202309081014770.png" alt="image-20230908101441689" style="zoom:50%;" />

作用在于：例如我们想要a[l,r]中间所有的数都+c，可以降低时间复杂度。

我们只需要 b[l]+c，然后b[r+1]-c，这样借助b求出的a在该范围内就都+c

<img src="https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202309081044633.png" alt="image-20230908104447584" style="zoom:67%;" />

## 位运算

- n的二进制表示第k位是几

```
n>>k&1 
```

- lowbit(x) 返回x的最后一位（最右边）的1

  ```
  x=0b1010
  lowbix(x)=0b10
  
  lowbit(x)=x&-x=x&(~x+1)
  ```

  可以用来统计x中有多少个1，每次把最后一个1减掉、

## 离散化

值域很大，但是其中值的个数比较少

<img src="https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202309191503893.png" alt="image-20230919150359785" style="zoom:50%;" />

<img src="https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202309191506909.png" alt="image-20230919150608865" style="zoom:50%;" />

排完序以后的下标就相当于是映射到的值，然后通过二分查找找到该值.

alls中加入了所有需要查询的下标。直接看802题更容易理解。

## 区间合并

<img src="https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202309201019735.png" alt="image-20230920101912676" style="zoom:33%;" />

## 题目

​	快速排序

- AcWing 785. 快速排序（2023年07月07日）

- AcWing 786. 第k个数（快速选择算法）（2023年07月07日,:pushpin:）

  快速排序的思想决定了，排序以后，左边的数都<=x,右边的数都>=x

  所以我们每次都只需要去右边界<=(k-1)的区间里去找

  当左边界和右边界相等的时候，说明我们找到了。

  注意：快速排序的边界上的数不一定就是x，可能被交换走了，只有当 l==r 时，该位置才能是该元素的位置

  归并排序

- AcWing 787. 归并排序(2023年07月07日)

- AcWing 788. 逆序对的数量（2023年07月07日,:pushpin:）

  ![image-20230707215516956](https://picgo-1305367394.cos.ap-beijing.myqcloud.com/picgo/202307072155066.png)

  就是在每次合并的时候，统计逆序对的数量，充分利用两个数组都是有序的情况。如果q[i]>q[j]，则[i,mid]中间所有的元素都会>q[j],而且前面的序号显然是比后面小的。

  

  二分

- AcWing 789. 数的范围（2023年07月08日）

- AcWing 790. 数的三次方根（2023年07月08日）
  高精度

- AcWing 791. 高精度加法

- AcWing 792. 高精度减法

- AcWing 793. 高精度乘法

- AcWing 794. 高精度除法
  前缀和与差分

- AcWing 795. 前缀和

- AcWing 796. 子矩阵的和

- AcWing 797. 差分

- AcWing 798. 差分矩阵
  双指针算法

- AcWing 799. 最长连续不重复子序列

- AcWing 800. 数组元素的目标和

- AcWing 2816. 判断子序列
  位运算

- AcWing 801. 二进制中1的个数
  离散化

- AcWing 802. 区间和
  区间合并

- AcWing 803. 区间合并



































