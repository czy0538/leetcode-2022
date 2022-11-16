#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int offsetX = 1, offsetY = 1;
        int sizeX = matrix[0].size();
        int sizeY = matrix.size();
        int loop = min(sizeX, sizeY) / 2;
        int startX = 0, startY = 0;
        ans.reserve(sizeX * sizeY);
        while (loop--) {
            int x = startX, y = startY;
            for (; x < sizeX - offsetX; x++) {
                ans.push_back(matrix[y][x]);
            }
            for (; y < sizeY - offsetY; y++) {
                ans.push_back(matrix[y][x]);
            }
            for (; x > startX; x--) {
                ans.push_back(matrix[y][x]);
            }
            for (; y > startY; y--) {
                ans.push_back(matrix[y][x]);
            }
            offsetX++;
            offsetY++;
            startX++;
            startY++;
        }
        if (startX == sizeX - offsetX && startY == sizeY - offsetY) {
            ans.push_back(matrix[startY][startX]);
        } else if (startX == sizeX - offsetX) {
            while (startY <= sizeY - offsetY) ans.push_back(matrix[startY++][startX]);
        } else if (startY == sizeY - offsetY) {
            while (startX <= sizeX - offsetX) ans.push_back(matrix[startY][startX++]);
        }
        return ans;
    }
};