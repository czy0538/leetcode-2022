#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int N = 1e5 * 3;

int a[N], s[N];
using point = pair<int, int>; // 存储加入的值和查询的值
vector<int> alls; // 存放所有用到的下标
vector<point> add, query; // 存放所有的查询请求和加入请求

int find(int x) {
    int l = 0, r = alls.size() - 1, mid = (l + r) / 2;
    while (l < r) {
        if (alls[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
        mid = (l + r) / 2; //
    }
    return r + 1; // 从下标为1开始映射，目的是方便后续对前缀和的处理
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        alls.push_back(x);
        add.push_back({x, c});
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }

    // 下标数据去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 构建数组
    for (const auto& item : add) {
        a[find(item.first)] += item.second;
    }

    // 构建前缀和
    for (int i = 1; i <= alls.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }

    // 查询
    for (const auto& item : query) {
        auto l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}