#include <iostream>
using namespace std;
constexpr int N = 1e5 + 10;
int a[N], b[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    int i = 0, j = 0;
    for (; i < n, j < m; j++) {
        if (a[i] == b[j]) {
            i++;
        }
    }
    if (i >= n) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}