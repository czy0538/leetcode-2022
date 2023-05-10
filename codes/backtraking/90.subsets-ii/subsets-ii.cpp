#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    using vit = vector<int>::const_iterator;
    vector<int> path;
    vector<vector<int>> result;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        result.push_back(vector<int>{});
        backtracing(nums.cbegin(), nums.cend());
        return result;
    }

    void backtracing(vit beg, vit end) {
        if (beg == end) {
            return;
        }
        for (auto it = beg; it < end; it++) {
            if (it != beg && *(it - 1) == *it) {
                continue;
            }
            path.push_back(*it);
            result.push_back(path);
            backtracing(it + 1, end);
            path.pop_back();
        }
    }
};