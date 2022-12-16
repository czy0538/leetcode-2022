#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        decltype(nums.cbegin()) i, left, right;
        for (i = nums.cbegin(); i != nums.cend(); i++) {
            // if the first (also the minimum) number bigger than 0, there is no chance to get answer.
            if (*i > 0) {
                break;
            }

            if (i > nums.cbegin() && *i == *(i - 1)) {
                continue;
            }

            left = i + 1;
            right = nums.cend() - 1;
            while (left < right) {
                auto t = *i + *left + *right;
                if (t == 0) {
                    ans.push_back(vector<int>{*i, *left, *right});
                    // remove duplicate elements
                    do{
                        left++;
                    } while (left < right && *left == *(left - 1));

                    do{
                        right--;
                    } while (left < right && *right == *(right + 1));
                } else if (t > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};