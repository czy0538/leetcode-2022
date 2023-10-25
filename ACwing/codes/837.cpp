#include <iostream>
#include <string>
using namespace std;
constexpr int N = 1e5;
int p[N], s[N];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        string op;
        int a, b;
        cin >> op;
        if(op=="C"){
            cin >> a >> b;
            // 如果a,b祖先相同，说明他们本就联通不需要合并
            if(find(a)==find(b)){
                continue;
            }
            // 将a合并到b下，首先把a的祖先的size移交过去，然后再更改根节点。
            s[find(b)] += s[find(a)];
            p[find(a)] = find(b);

        }else if(op=="Q1"){
            cin >> a >> b;
            if(find(a)==find(b)){
                cout << "Yes" << endl;
            }else{
                cout << "No"<<  endl;
            }
        }else{
            cin >> a;
            cout << s[find(a)]<<endl;
        }
    }
    return 0;
}