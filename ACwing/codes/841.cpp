#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const int P = 131;
using ULL = unsigned long long;
int h[N]; // 存储字符串前缀哈希，h[0]=0
int p[N]; // 存储p^i
char s[N]; // 存储字符串

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];// 计算某个子串的哈希值
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1); // 从下标1开始存，目的是与下面的计算相对应
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P; // 计算P的i次幂
        h[i] = h[i - 1] * P + s[i]; //计算前缀哈希，注意字符串低位反而对应最后算出来哈希的高位。
    }
    int l1, l2, r1, r2;
    while (m--) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
