#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int l = 0, r = nums.size() - 1, mid = (l + r) / 2;
        while (l <= r) {
            if (nums[mid] == target) {
                for (int i = mid; i >= 0 && nums[i] == target; i--) {
                    result[0] = i;
                }
                for (int i = mid; i < nums.size() && nums[i] == target; i++) {
                    result[1] = i;
                }
                break;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }

        return result;
    }
};

int main() {
    Solution a;
    vector<int> nums;

    auto v = a.searchRange(nums, 0);
}