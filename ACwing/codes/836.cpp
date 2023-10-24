#include <iostream>
#include <string>
using namespace std;

constexpr int N = 1e5;

int p[N];


// 查找并进行路径压缩
int findRoot(int x) {
    if (p[x] != x) {
        p[x] = findRoot(p[x]);
    }
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i; // 开始时每个节点各自在一个集合中，也即他们的根节点就是自己
    }
    while (m--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M") {
            // 并查集的合并操作
            p[findRoot(a)] = findRoot(b);
        } else {
            if (findRoot(a) == findRoot(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}