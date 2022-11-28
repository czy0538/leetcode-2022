#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> dict,tmp;
//         for_each(nums1.begin(), nums1.end(), [&](const int& i) { dict.insert(i); });
//         for_each(nums2.begin(), nums2.end(), [&](const int& i) {
//             if (dict.count(i) != 0) {
//                 tmp.insert(i);
//             }
//         });
//         return vector<int>(tmp.begin(),tmp.end());
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> tmp(nums1.begin(), nums1.end()), ans;
        for_each(nums2.begin(), nums2.end(), [&] (const int&i){
            if(tmp.find(i)!=tmp.end()){
                ans.insert(i);
            }
        });
        return vector<int>(ans.begin(), ans.end());
    }
};