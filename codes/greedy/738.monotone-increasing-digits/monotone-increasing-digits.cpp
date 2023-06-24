#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        auto raw = to_string(n);
        int flag = raw.size();
        for (int i = raw.size() - 1; i > 0; i--) {
            if(raw[i-1]>raw[i]){
                flag = i;
                raw[i - 1]--;
            }
        }
        for (int i = flag; i < raw.size();i++){
            raw[i] = '9';
        }
        return stoi(raw);
    }
};