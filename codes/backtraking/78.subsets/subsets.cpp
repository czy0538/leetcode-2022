#include <vector>
using namespace std;
class Solution {
    using vit = vector<int>::const_iterator;
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        result.push_back(vector<int>{});
        backtracing(nums.cbegin(), nums.cend());
        return result;
    }

    void backtracing(vit beg, vit end) {
        if (beg == end) {
            return;
        }
        for (auto it = beg; it != end; ++it) {
            path.push_back(*it);
            result.push_back(path);
            backtracing(it + 1, end);
            path.pop_back();
        }
    }
};