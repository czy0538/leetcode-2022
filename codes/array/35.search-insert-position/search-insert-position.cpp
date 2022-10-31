#include <iostream>
#include <vector>
#include <fmt/core.h>
using namespace std;
class Solution {
public:
    // 左闭右开版本
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), i = (l + r) / 2;
        while (l < r) {
            if (nums[i] < target) {
                l = i + 1;
            } else if (nums[i] > target) {
                r = i;
            } else {
                break;
            }
            // 一定要放在这里，不然返回的时候不是i应该的值
            i = (l + r) / 2;
        }
        return i;
    }
};
