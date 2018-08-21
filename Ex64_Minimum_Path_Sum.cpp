//
// Created by Basti031 on 2018/8/7.
//
#include <vector>
#include<iostream>

using namespace std;

class Solution {
    int min(int a, int b) {
        return a < b ? a : b;
    }

public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int column = grid[0].size();
        int row = grid.size();

        for (int i = 1; i < column; ++i) {
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        }
        for (int j = 1; j < row; ++j) {
            grid[j][0] = grid[j - 1][0] + grid[j][0];
        }

        for (int j = 1; j < column; ++j) {
            for (int i = 1; i < row; ++i) {
                int top = grid[i - 1][j];
                int left = grid[i][j - 1];
                grid[i][j] = min(top, left) + grid[i][j];
            }
        }
        return grid[row-1][column-1];
    }
};