#include <iostream>
using namespace std;
constexpr int N = 1e5 + 10;

int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int fake = 0;
    while (k--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n) {
            fake++;
            continue;
        }
        int px = find(x), py = find(y);
        if (op == 1) {
            if (px == py) {
                if ((d[x] - d[y]) % 3) {
                    fake++;
                }
            } else {
                // y并入x
                p[py] = px;
                // d[py]+d[y]-d[x]==0;
                d[py] = d[x] - d[y];
            }
        } else {
            if (px == py) {
                if ((d[x] - d[y] - 1) % 3) {
                    fake++;
                }
            } else {
                // y并入x
                p[py] = px;
                // d[py]+d[y]-d[x]-1==0;
                d[py] = d[x] - d[y] + 1;
            }
        }
    }
    cout << fake;
    return 0;
}