#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int lowPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i]<lowPrice){
                lowPrice=prices[i];
            }else if(prices[i]>lowPrice+fee){
                result += prices[i] - lowPrice - fee;
                lowPrice = prices[i] - fee;
            }
        }
        return result;
    }
};