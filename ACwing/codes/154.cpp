#include <iostream>
using namespace std;
const int N = 1e6;
int a[N], q[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    q[0] = 0;
    int h = 0, t = 1;
    for (int i = 0; i < n; i++) {
        if (q[h] <= i - k) {
            h++;
        }
        while (h < t && a[q[t - 1]] >= a[i]) {
            t--;
        }
        q[t++] = i;
        if (i >= k - 1) {
            printf("%d ", a[q[h]]);
        }
    }

    puts("");
    q[0] = 0;
    h = 0, t = 1;
    for (int i = 0; i < n; i++) {
        if (q[h] <= i - k) {
            h++;
        }
        while (h < t && a[q[t - 1]] <= a[i]) {
            t--;
        }
        q[t++] = i;
        if (i >= k - 1) {
            printf("%d ", a[q[h]]);
        }
    }

    return 0;
}