#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.size() == 0 || nums.front() > target || nums.back() < target) {
            return result;
        }
        int mid, l = 0, r = nums.size() - 1;
        while (l < r) {
            mid = l + r >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (nums[l] != target) {
            return result;
        }
        result[0] = l;
        r = nums.size() - 1;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        result[1] = l;
        return result;
    }
};
// 2023年07月06日 acwing 版本

// 非常笨的版本，先找到一个然后左右探测。
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> result(2, -1);
//         int l = 0, r = nums.size() - 1, mid = (l + r) / 2;
//         while (l <= r) {
//             if (nums[mid] == target) {
//                 for (int i = mid; i >= 0 && nums[i] == target; i--) {
//                     result[0] = i;
//                 }
//                 for (int i = mid; i < nums.size() && nums[i] == target; i++) {
//                     result[1] = i;
//                 }
//                 break;
//             } else if (nums[mid] > target) {
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//             mid = (l + r) / 2;
//         }

//         return result;
//     }
// };
