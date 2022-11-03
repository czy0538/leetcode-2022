#include<cmath>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num, mid = num >> 1;
        while(l<=r){
            auto t = mid * mid;
            if(t<num){
                l = r + 1;
            }else if(t>num){
                r = l - 1;
            }else{
                return true;
            }
            mid = (l + r) >> 1;
        }
        return false;
    }
};