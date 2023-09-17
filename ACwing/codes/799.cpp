// 与leetcode的第三题一致
#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 10;
int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (b[a[i]] != 0) {
            b[a[j++]]--;
        }
        res = max(i - j + 1, res);
        b[a[i]]++;
    }
    printf("%d\n", res);
    return 0;
}