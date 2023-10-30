#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N = 1e5 + 10;

int h[N], s;

void down(int u) {
    int t = u;
    // 左儿子存在且比当前小
    if (u * 2 <= s && h[u * 2] < h[t]) {
        t = u * 2;
    }
    // 右儿子存在且比当前小
    if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t]) {
        t = u * 2 + 1;
    }
    if (u != t) {
        // 交换，递归
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u){
    while(u/2>0&&h[u/2]>h[u]){
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main() {
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    s = n;

    for (int i = n / 2; i >= 1; i--) {
        down(i);
    }

    while (m--) {
        cout << h[1] << " ";
        h[1] = h[s];
        s--;
        down(1);
    }

    return 0;
}