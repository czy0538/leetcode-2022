#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, mid = x >> 1, t = 0;
        while (l <= r) {
            t = mid * mid;
            if (t <= x && t + (mid << 1) + 1 > x) {
                break;
            } else if (t > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = (l + r) >> 1;
        }
        return mid;
    }
};