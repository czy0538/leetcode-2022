#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] == val) {
                j++;
            } else {
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3, 2, 2, 3};
    int s = sol.removeElement(v, 3);
    fmt::print("{}\n", s);
    for (int i = 0; i < s; ++i) {
        fmt::print("{} ", v[i]);
    }
}