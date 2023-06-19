#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // 按照 k_i 升序，h_i 降序排序
        /*
        这样去写排序乍一看可以，但是确实是过不了的，因为其隐含了==。
        有多个条件判断，还是按照顺序，按照优先级去处理等于的情况。
        if (a[1] > b[1]) {
                return false;
            }
            return a[0] > b[0];
        */
        sort(people.begin(), people.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        list<vector<int>> q;
        q.push_back(people.front());
        for (auto i = 1; i < people.size(); i++) {
            auto it = q.begin();
            auto count = people[i][1];
            while (it != q.end() && count > 0) {
                if ((*it)[0] >= people[i][0]) {
                    count--;
                }
                it++;
            }
            q.insert(it, people[i]);
        }
        vector<vector<int>> result(q.begin(), q.end());
        return result;
    }
};