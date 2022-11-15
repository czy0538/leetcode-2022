#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startX = 0, startY = 0;
        int offsetX = 1, offsetY = 1;
        int sizeX = matrix[0].size();
        int sizeY = matrix.size();
        int loop = min(matrix.size(), matrix[0].size()) / 2;
        vector<int> ans;
        ans.reserve(sizeX * sizeY);
        while (loop--) {
            int x = startX, y = startY;
            for (; x < sizeX - offsetX; ++x) {
                ans.push_back(matrix[y][x]);
            }
            for (; y < sizeY - offsetY; ++y) {
                ans.push_back(matrix[y][x]);
            }
            for (; x > startX; x--) {
                ans.push_back(matrix[y][x]);
            }
            for (; y > startY; y--) {
                ans.push_back(matrix[y][x]);
            }
            startX++;
            startY++;
            offsetX++;
            offsetY++;
        }
        // 处理因为奇偶性造成的还有一部分没有处理完的情况
        // 剩余中心元素
        if (startX == sizeX - offsetX && startY == sizeY - offsetY) {
            ans.push_back(matrix[startY][startX]);
        }
        // 剩余一列元素
        else if (startX == sizeX - offsetX) {
            while (startY <= sizeY - offsetY) {
                ans.push_back(matrix[startY++][startX]);
            }
        }
        // 剩余一行元素
        else if (startY == sizeY - offsetY) {
            while (startX <= sizeX - offsetX) {
                ans.push_back(matrix[startY][startX++]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}};
    auto ans = s.spiralOrder(v);
}