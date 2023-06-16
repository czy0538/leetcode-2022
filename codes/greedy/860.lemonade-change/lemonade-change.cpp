#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.front()!=5){
            return false;
        }
        int money[2] = {};
        for (const auto& i : bills) {
            switch (i) {
            case 5:
                money[0]++;
                break;
            case 10:
                if (money[0] < 0) {
                    return false;
                }
                money[0]--;
                money[1]++;
                break;
            case 20:
                if (money[1] > 0 && money[0] > 0) {
                    money[0]--;
                    money[1]--;
                } else if (money[0] >=3) {
                    money[0] -= 3;
                } else {
                    return false;
                }

                break;
            }
        }
        return true;
    }
};