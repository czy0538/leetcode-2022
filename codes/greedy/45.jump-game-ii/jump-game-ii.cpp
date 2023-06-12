#include <vector>
using namespace std;
// 贪心策略：每次跳转到下一个具有最大元素的数据，但是这种策略是错误的，如这种情况
// [10,9,8,7,6,5,4,3,2,1,1,0]
// 问题出在了只考虑下一步的最大覆盖范围，不考虑当前的最大覆盖范围。正确的应该是选择当前和下一步之和的最大覆盖范围。
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        auto next = [&](int pos) -> int {
            if(pos+nums[pos]>=nums.size()-1){
                return nums.size() - 1;
            }
            int maxVal = 0;
            int maxPos = 0;
            for (int i = pos ; i <= pos + nums[pos] && i < nums.size(); i++) {
                if (nums[i]+i>=maxVal){
                    maxPos = i;
                    maxVal = nums[i];
                }
            }
            return maxPos;
        };

        int result = 0;
        int pos = 0;
        while (true) {
            result++;
            auto np = next(pos);
            if(np==nums.size()-1){
                break;
            }
            pos = np;
        }
        return result;
    }
};