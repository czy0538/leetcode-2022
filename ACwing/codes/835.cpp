#include <iostream>
#include <string>
using namespace std;

constexpr int N = 1e5;
int son[N][26]; // 存储子节点指向哪里
int idx = 1; // 指向下一个被使用的缓冲区,注意要从1开始，0下标是根节点所在
int cnt[N]; // 存储以某个节点为结束的单词的出现的次数

void insert(const string& s) {
    int p = 0;
    for (const auto& c : s) {
        int a = c - 'a';
        if (son[p][a] == 0) { // 没有节点就创建节点
            son[p][a] = idx++;
        }
        p = son[p][a]; // 有节点就走向那个节点
    }
    cnt[p]++; // 标记节点结尾的单词的出现个数，也即某个串出现的个数。
}

int query(const string& s) {
    int p = 0;
    for (const auto& c : s) {
        int a = c - 'a';
        if (son[p][a] == 0) {
            return 0;
        }
        p = son[p][a];
    }
    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op, s;
        cin >> op >> s;
        if (op == "I") {
            insert(s);
        } else {
            cout << query(s) << endl;
        }
    }
    return 0;
}
