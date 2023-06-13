#include <vector>
#include <algorithm>
using namespace std;
// 代码是没问题的，但是 leetcode 上会爆栈，本地运行咩有问题
class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        // 这个地方的 > 如果改成>= 就会出问题
        // The return value of the function call operation applied to an object of a type satisfying Compare, when
        // contextually converted to bool, yields true if the first argument of the call appears before the second in
        // the strict weak ordering relation induced by this type, and false otherwise.
        sort(nums.begin(), nums.end(), [](const auto &i, const auto &j) -> bool { return abs(i) > abs(j); });
        for_each(nums.begin(), nums.end(), [&](auto &it) -> void {
            if(it<0&&k>0){
                k--;
                it = -it;
            }
        });
        if(k%2==1){
            *(nums.end() - 1) = -nums.back();
        }
        auto result = 0;
        for_each(nums.begin(), nums.end(), [&](const auto it) -> void { result += it; });
        return result;
    }
};

