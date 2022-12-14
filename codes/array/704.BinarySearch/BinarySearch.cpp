#include <iostream>
#include <vector>
#include <fmt/core.h>
using namespace std;
class Solution {
public:
    // 左右都闭版本
    int search(vector<int>& nums, int target) {
        if (target < nums.front() || target > nums.back()) {
            return -1;
        }
        // 如果没有上面的语句处理第一个元素的情况，请务必这里用int，否则只有一个元素时候会有问题
        decltype(nums.size()) i = nums.size() / 2, l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] > target) {
                r = i - 1;
            } else {
                l = i + 1;
            }
            i = l + (r - l) / 2;
        }
        return -1;
    }
};

int main() {
    fmt::print("hello world\n");
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    Solution s;
    fmt::print("{}\n", s.search(nums, 2));

    return 0;
}