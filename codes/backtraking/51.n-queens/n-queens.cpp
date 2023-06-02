#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> result;
    vector<string> chessboard;
    vector<vector<string>> solveNQueens(int n) {
        chessboard = vector<string>(n, string(n, '.'));
        backtracing(0);
        return result;
    }
    bool isValid(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // upper-left
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // upper-right
        for (int i = row - 1, j = col + 1; i >= 0 && j < chessboard.size(); i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backtracing(int row) {
        if (row == chessboard.size()) {
            result.push_back(chessboard);
            return;
        }
        for (int i = 0; i < chessboard.size(); ++i) {
            chessboard[row][i] = 'Q';
            if(isValid(row,i)){
                backtracing(row + 1);
            }
            chessboard[row][i] = '.';
        }
    }
};
