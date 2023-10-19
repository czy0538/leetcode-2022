#include <iostream>
#include <algorithm>
using namespace std;

constexpr int M = 32; // 数据位数
constexpr long long N = 1e5; // 数据数量

int son[N * M][2], a[N];

int idx = 1;

void insert(unsigned int x) {
    int p = 0;
    unsigned int t = 1 << (M - 1);
    // 从高位向低位处理
    for (int i = 0; i < M; i++) {
        int cur = (x & t) == 0 ? 0 : 1;
        if (son[p][cur] == 0) {
            son[p][cur] = idx++;
        }
        t >>= 1;
        p = son[p][cur];
    }
}

unsigned int search(unsigned int x) {
    int p = 0;
    unsigned int t = 1 << (M - 1);
    unsigned int res = 0;
    for (int i = 0; i < M; i++) {
        // 如果是0，那么需要1；反之则反
        int cur = (x & t) == 0 ? 1 : 0;
        if (son[p][cur] != 0) {
            res |= t;
            p = son[p][cur];
        } else {
            p = son[p][1 - cur];
        }

        t >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    unsigned int x = 0;
    for (int i = 0; i < n; i++) {
        x = max(x, search(a[i]));
    }

    cout << x;
    return 0;
}