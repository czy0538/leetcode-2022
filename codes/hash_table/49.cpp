#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    unordered_map<string, vector<string>> dict;

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (const auto& s : strs) {
            auto t = s;
            sort(t.begin(), t.end());
            dict[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (const auto& i : dict) {
            ans.emplace_back(i.second);
        }
        return ans;
    }
};