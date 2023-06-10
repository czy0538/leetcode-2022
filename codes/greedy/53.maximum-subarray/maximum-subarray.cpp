#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;
        for (auto& i : nums) {
            count += i;

            // 一定要放到前面
            result = max(result, count);
            if(count<0){
                count = 0;
            }

        }
        return result;
    }
    };