#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 3;

int h[N], e[N], ne[N];
int idx;

void insert(int x) {
    int t = (x % N + N) % N;
    ne[idx] = h[t];
    e[idx] = x;
    h[t] = idx;
    idx++;
}

bool find(int x) {
    int t = (x % N + N) % N;
    bool flag = false;
    for (int i = h[t]; i != -1; i = ne[i]) {
        if (x == e[i]) {
            flag = true;
            break;
        }
    }
    return flag;
}

int main() {
    memset(h, -1, sizeof(h));
    int n;
    scanf("%d", &n);
    char op[2];
    int x;
    while (n--) {
        scanf("%s %d", op, &x);
        if (op[0] == 'I') {
            insert(x);
        } else {
            if (find(x)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
