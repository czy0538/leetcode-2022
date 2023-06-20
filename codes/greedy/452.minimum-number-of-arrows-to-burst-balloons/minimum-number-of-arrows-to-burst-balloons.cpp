#include <vector>
#include <algorithm>
#include <list>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) -> bool { return a[0] < b[0]; });
        int count = 1;
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if(points[i][0]>right){
                right = points[i][1];
                count++;
            }else{
                right = min(right, points[i][1]);
            }
        }
        return count;
    }
};