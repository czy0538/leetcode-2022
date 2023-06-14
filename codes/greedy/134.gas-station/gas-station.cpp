#include <vector>
using namespace std;

// 最笨的方法，会超出时间限制
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         for (int start = 0; start < gas.size(); start++) {
//             int rest = gas[start] - cost[start];
//             int i = (start + 1) % gas.size();
//             while (rest >= 0 && i != start) {
//                 rest += gas[i] - cost[i];
//                 i = (i + 1) % gas.size();
//             }
//             if (rest >= 0) {
//                 return start;
//             }
//         }
//         return -1;
//     }
// };

// 全局思考， 从 0 开始走一趟
// 记录总油量和总耗油量差值，如果是＜0，说明无论如何也没有结果
// 同时计算油箱里的最小油量
// 需要从后向前，找到一个使这个最小油量>=0的点，也就是从这个点出发，经过其后面的种种节点，最终保证邮箱里有油
// 这里也存在一种可能就是这个点压根就不存在，所以最后要返回-1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int minRest = INT_MAX;
        for (int i = 0; i < gas.size(); i++) {
            auto rest = gas[i] - cost[i];
            curSum += rest;
            minRest = min(minRest, curSum);
        }
        if (curSum < 0) {
            return -1;
        }
        if(minRest>=0){
            return 0;
        }

        for (int i = gas.size() - 1; i >= 0; --i) {
            minRest += gas[i] - cost[i];
            if(minRest>=0){
                return i;
            }
        }
        return -1;
    }
};