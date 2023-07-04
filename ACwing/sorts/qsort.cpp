#include <cstdio>
#include <vector>
using namespace std;

void qsort(vector<int>& q, int l, int r) {
    if (l >= r) {
        return;
    }
    // 确定分界点`x`
    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    // 调整区间
    while (i < j) {
        i++;
        while (q[i] < x) {
            i++;
        }
        j--;
        while (q[j] > x) {
            j--;
        }
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    // 递归
    qsort(q, l, j);
    qsort(q, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, 0, n - 1);
    for (const auto& i : nums) {
        printf("%d ", i);
    }
}