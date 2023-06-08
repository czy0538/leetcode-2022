#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        auto sit = s.cbegin();
        auto git = g.cbegin();
        int sum = 0;
        while (sit != s.cend() && git != g.cend()) {
            while (*git > *sit) {
                if (++sit == s.cend()) {
                    return sum;
                }
            }
            sum++;
            sit++;
            git++;
        }
        return sum;
    }
};