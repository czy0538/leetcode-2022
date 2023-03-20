#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        stack<int> index;
        result.resize(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size();i++){
            while(!index.empty()&&temperatures[i]>temperatures[index.top()]){
                result[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }
        return result;
    }
};