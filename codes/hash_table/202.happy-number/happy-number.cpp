#include <unordered_set>
using namespace std;
class Solution {
public:
    int getDigit(int &n) {
        int t = n % 10;
        n = n / 10;
        return t * t;
    }
    bool isHappy(int n) {
        unordered_set<int> history;
        while (true) {
            int tmp = 0;
            while (n) {
                tmp += getDigit(n);
            }
            if(tmp==1){
                return true;
            }else{
                auto ret = history.insert(tmp);
                if(ret.second==false){
                    return false;
                }else{
                    n = tmp;
                }
            }
        }
    }
};