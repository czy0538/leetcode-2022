#include <vector>
using namespace std;
// 直觉版本
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int sum = 0;
//         int size = INT_MAX;
//         for (int i = 0, j = 0; j < nums.size(); ++j) {
//             sum += nums[j];
//             while(sum>=target&&i<=j){
//                 if(sum-nums[i]>=target){
//                     sum -= nums[i++];
//                 }else{
//                     break;
//                 }
//             }
//             if(sum>=target&&j-i+1<size){
//                 size = j - i + 1;
//             }
//         }
//         if(size==INT_MAX){
//             return 0;
//         }else{
//             return size;
//         }
//     }
// };

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                // 当满足sum >= s时无条件的更新i是这个方法的精髓，哪怕更新以后的sum不满足条件了
                // 其实仔细想一下的话，当前的满足了，去掉一个不满足了，
                // 那下一步继续加入新的，如果不满足那么窗口会比现在大，如果满足那么会跟现在一样
                // 因此满足以后无脑移动左是合理的
                // 移动到两个都相等了那么sum==0了，也就隐含了i不会越过j
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};