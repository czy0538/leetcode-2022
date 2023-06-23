#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) -> bool { return a[0] < b[0]; });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0]<=result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};