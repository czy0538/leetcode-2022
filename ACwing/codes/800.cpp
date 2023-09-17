// 本题有三种解法，双指针，二分，哈希表

// 最开始想到的是一种改进的暴力法
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 10;
int a[N], b[N];
int main() {
    int m, n, x;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    b[0] = INT_MIN;
    b[m + 1] = INT_MAX;
    int j = 0;
    for (int i = 0; i < n; i++) {
        int need = x - a[i];
        while (b[j] < need && j <= m) {
            j++;
        }
        while (b[j] > need && j >= 1) {
            j--;
        }
        if (b[j] == need) {
            printf("%d %d", i, j - 1);
            return 0;
        }
    }
    return 0;
}