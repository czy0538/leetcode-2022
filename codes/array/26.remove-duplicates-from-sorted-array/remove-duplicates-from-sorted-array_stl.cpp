#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto iter = unique(nums.begin(), nums.end());
        return iter - nums.begin();
    }
};

int main(){
    Solution s;
    auto v = vector<int>{1, 1, 2};
    cout<<s.removeDuplicates(v)<<endl;
}