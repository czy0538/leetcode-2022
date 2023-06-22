#include <vector>
#include <string>
#include <array>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        array<int, 26> hash;
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};