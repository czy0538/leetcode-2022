#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// 最笨的办法，先算出平方然后排序，时间复杂度为O(nlogn)，空间复杂度为O(1)
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for_each(nums.begin(), nums.end(), [](int& i) -> void {
//             i = pow(i, 2);
//         });
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

// 双指针版本，但有优化空间，时间复杂度O(n)，空间复杂度O(n)
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         // 找到最后一个小于0的数
//         int i = 0;
//         while (i < nums.size() && nums[i] < 0) {
//             i++;
//         }
//         i -= 1;
//         // 如果没有，那么直接原地修改nums即可
//         if (i < 0) {
//             for_each(nums.begin(), nums.end(), [](auto& i) { i = pow(i, 2); });
//             return nums;
//         }

//         // 用一个新的数组存放
//         vector<int> result;

//         // 如果有，则i当前指向负数中最大的，其平方最小的
//         int j = i + 1; // 指向正数中最小的
//         while (i >= 0 && j < nums.size()) {
//             int a, b;
//             a = pow(nums[i], 2);
//             b = pow(nums[j], 2);
//             // 这里有优化空间，a或者b算出来了就用了一次，如果可以再下一次也用上可以减少时间
//             if (a < b) {
//                 result.push_back(a);
//                 i--;
//             } else {
//                 result.push_back(b);
//                 j++;
//             }
//         }
//         // 处理一个先走到头的情况
//         while (i >= 0) {
//             result.push_back(pow(nums[i--], 2));
//         }
//         while (j < nums.size()) {
//             result.push_back(pow(nums[j++], 2));
//         }
//         return result;
//     }
// };

// 优化下pow
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         // 找到最后一个小于0的数
//         int i = 0;
//         while (i < nums.size() && nums[i] < 0) {
//             i++;
//         }
//         i -= 1;
//         // 如果没有，那么直接原地修改nums即可
//         if (i < 0) {
//             for_each(nums.begin(), nums.end(), [](auto& i) { i = pow(i, 2); });
//             return nums;
//         }

//         // 用一个新的数组存放
//         vector<int> result;

//         // 如果有，则i当前指向负数中最大的，其平方最小的
//         int j = i + 1; // 指向正数中最小的
//         int a, b;
//         if (i >= 0 && j < nums.size()) {
//             a = pow(nums[i], 2);
//             b = pow(nums[j], 2);
//         }
//         while (i >= 0 && j < nums.size()) {
//             // 这里优化以后减少了不必要的对于a,b的平方运算，理论上会快不少，因为乘法的时钟周期很长
//             if (a < b) {
//                 result.push_back(a);
//                 if(--i>=0){
//                     a = pow(nums[i], 2);
//                 }
//             } else {
//                 result.push_back(b);
//                 if(++j<nums.size()){
//                     b = pow(nums[j], 2);
//                 }
//             }
//         }
//         // 处理一个先走到头的情况
//         while (i >= 0) {
//             result.push_back(pow(nums[i--], 2));
//         }
//         while (j < nums.size()) {
//             result.push_back(pow(nums[j++], 2));
//         }
//         return result;
//     }
// };

// 查询了相关的资料，直接乘竟然会比pow快，因此再次修改
// https://stackoverflow.com/questions/2940367/what-is-more-efficient-using-pow-to-square-or-just-multiply-it-with-itself
// 优化下pow
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         // 找到最后一个小于0的数
//         int i = 0;
//         while (i < nums.size() && nums[i] < 0) {
//             i++;
//         }
//         i -= 1;
//         // 如果没有，那么直接原地修改nums即可
//         if (i < 0) {
//             for_each(nums.begin(), nums.end(), [](auto& i) { i *= i; });
//             return nums;
//         }

//         // 用一个新的数组存放
//         vector<int> result;

//         // 如果有，则i当前指向负数中最大的，其平方最小的
//         int j = i + 1; // 指向正数中最小的
//         int a, b;
//         if (i >= 0 && j < nums.size()) {
//             a = nums[i]*nums[i];
//             b = nums[j]*nums[j];
//         }
//         while (i >= 0 && j < nums.size()) {
//             // 这里优化以后减少了不必要的对于a,b的平方运算，理论上会快不少，因为乘法的时钟周期很长
//             if (a < b) {
//                 result.push_back(a);
//                 if (--i >= 0) {
//                     a = nums[i] * nums[i];
//                 }
//             } else {
//                 result.push_back(b);
//                 if (++j < nums.size()) {
//                     b = nums[j] * nums[j];
//                 }
//             }
//         }
//         // 处理一个先走到头的情况
//         while (i >= 0) {
//             result.push_back(nums[i] * nums[i]);
//             i--;
//         }
//         while (j < nums.size()) {
//             result.push_back(nums[j] * nums[j]);
//             j++;
//         }
//         return result;
//     }
// };

// 进一步研究特性我们可以发现两边的元素其实平方以后是最大的，因此可以倒着插入
// 这样可以节约第一次找负数的时间复杂度

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        auto i = nums.begin();
        auto j = nums.end() - 1;
        auto k = ans.rbegin();
        int a = *i * *i;
        int b = *j * *j;
        while (k != ans.rend()) {
            if (a < b) {
                *k = b;
                if (++k != ans.rend()) {
                    j--;
                    b = *j * *j;
                }

            } else {
                *k = a;
                if (++k != ans.rend()) {
                    i++;
                    a = *i * *i;
                }
            }
        }
        return ans;
    }
};