// // 一维
// #include <iostream>
// using namespace std;
// constexpr int N = 1e5 + 10;
// int a[N], b[N];
// void insert(int l, int r, int c) {
//     b[l] += c;
//     b[r + 1] -= c;
// }
// int main() {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i++) {
//         scanf("%d", &a[i]);
//         insert(i, i, a[i]); // 统一处理
//     }
//     int l, r, c;
//     for (int i = 1; i <= m; i++) {
//         scanf("%d%d%d", &l, &r, &c);
//         insert(l, r, c);
//     }
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum += b[i];
//         printf("%d ", sum);
//     }
// }

// 二维
#include <iostream>
using namespace std;
constexpr int N = 1e3 + 10;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);
        }
    }
    int x1, y1, x2, y2, c;
    while (q--) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }
        puts("");
    }
}