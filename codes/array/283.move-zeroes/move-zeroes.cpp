#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()<=1){
            return;
        }
        auto i = nums.begin();
        auto j = nums.begin();
        while (j!=nums.end()){
            if(*j==0){
                j++;
            }else{
                *i++ = *j++;
                // 等价写法
                // *i=*j;
                // i++;
                // j++;
            }
        }
        while(i!=nums.end()){
            *i++ = 0;
        }
    }
};