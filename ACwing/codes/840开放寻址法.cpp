#include <iostream>
#include <cstring>

const int N = 2e5 + 3;

int h[N];
int nil = 0x3f3f3f3f;

// 如果找到，返回的是元素的位置
// 否则返回元素应该在的位置
int find(int x) {
    int t = (x % N + N) % N;

    for (; h[t] != nil; t++) {
        if (h[t] == x) {
            break;
        }
    }
    return t;
}

int main() {
    int n;
    memset(h, 0x3f, sizeof(h));// 是按照字节来memset
    scanf("%d", &n);
    int x;
    char op[2];
    while (n--) {
        scanf("%s %d", op, &x);
        int k = find(x);
        if (op[0] == 'I') {
            h[k] = x;
        } else {
            if (h[k] == x) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}