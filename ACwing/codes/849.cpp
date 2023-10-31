#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 1e5 + 10;

int h[N], idx;
int ph[N], i; // 第i个插入的元素在堆中的位置
int hp[N]; // 堆中元素j是第i个插入的

void heapSwap(int t, int u) {
    swap(ph[hp[t]], ph[hp[u]]);
    swap(hp[t], hp[u]);
    swap(h[t], h[u]);
}

void up(int u) {
    while (u / 2 > 0 && h[u] < h[u / 2]) {
        heapSwap(u, u / 2);
        u /= 2;
    }
}

void down(int u) {
    int t = u;
    if (u * 2 <= idx && h[u * 2] < h[t]) {
        t = u * 2;
    }

    if (u * 2 + 1 <= idx && h[u * 2 + 1] < h[t]) {
        t = u * 2 + 1;
    }

    if (t != u) {
        heapSwap(t, u);
        down(t);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char op[3];
    int k, x;
    while (n--) {
        scanf("%s", op);
        if (op[0] == 'I') {
            scanf("%d", &x);
            h[++idx] = x;
            ph[++i] = idx;
            hp[idx] = i;
            up(idx);
        } else if (op[0] == 'P' && op[1] == 'M') {
            printf("%d\n", h[1]);
        } else if (op[0] == 'D' && op[1] == 'M') {
            heapSwap(1, idx);
            --idx;
            down(1);
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            int p = ph[k];
            heapSwap(p, idx);
            --idx;
            up(p);
            down(p);
            ;
        } else if (op[0] == 'C') {
            scanf("%d%d", &k, &x);
            h[ph[k]] = x;
            up(ph[k]);
            down(ph[k]);
        }
    }
    return 0;
}