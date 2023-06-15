#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        multimap<int, int> ratings_map; // rating:position
        vector<int> ans(ratings.size(), 0);
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++) {
            ratings_map.insert(pair<int, int>(ratings[i], i));
        }
        for_each(ratings_map.begin(), ratings_map.end(), [&](const auto &it) {
            int candies = 1;
            if (it.second != 0) {
                if (it.first > ratings[it.second - 1]) {
                    candies = max(candies, ans[it.second - 1] + 1);
                }
            }
            if (it.second != ratings.size() - 1) {
                if (it.first > ratings[it.second + 1]) {
                    candies = max(candies, ans[it.second + 1] + 1);
                }
            }
            ans[it.second] = candies;
            sum += candies;
        });
        return sum;
    }
};