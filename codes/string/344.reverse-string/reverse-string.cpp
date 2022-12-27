#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        char c;
        vector<char>::size_type i=0, j=s.size()-1;
        while (i < j) {
            c = s[i];
            s[i++] = s[j];
            s[j--] = c;
        }
    }
};