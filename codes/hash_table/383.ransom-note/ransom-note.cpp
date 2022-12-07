#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for (const auto c : magazine) {
            dict[c]++;
        }

        for (const auto c : ransomNote) {
            auto iter = dict.find(c);
            if (iter == dict.end() || iter->second == 0) {
                return false;
            }
            iter->second--;
        }
        return true;
    }
};