#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using point = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<point> seg(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    sort(seg.begin(), seg.end());
    vector<point> res;

    int l = -2e9, r = -2e9;

    for (const auto &item : seg) {
        if (r < item.first) {
            if (l != -2e9) {
                res.push_back({l, r});
            }
            l = item.first;
            r = item.second;
        } else {
            r = max(r, item.second);
        }
    }

    // 处理最后一个区间
    if (l != -2e9) {
        res.push_back({l, r});
    }
    cout << res.size() << endl;
    return 0;
}