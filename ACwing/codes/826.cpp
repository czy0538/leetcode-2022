#include <iostream>
using namespace std;
const int N = 100010;
int cur = 1, e[N], ne[N];

void add_k(int k, int x) {
    e[cur] = x;
    ne[cur] = ne[k];
    ne[k] = cur++;
}

void del_k(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_k(0, x);
        } else if (op == 'I') {
            cin >> k >> x;
            add_k(k, x);
        } else {
            cin >> k;
            del_k(k);
        }
    }

    for (int j = ne[0]; j; j = ne[j]) cout << e[j] << ' ';
    cout << endl;
    return 0;
}