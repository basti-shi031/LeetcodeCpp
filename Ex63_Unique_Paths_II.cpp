//
// Created by Basti031 on 2018/7/16.
//

#include <vector>
#include <iostream>

using namespace std;
//finished
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int rows = obstacleGrid.size();
        if (rows == 0) return 0;
        int cols = obstacleGrid[0].size();
        if (cols == 0 || obstacleGrid[rows - 1][cols - 1] == 1) return 0;

        vector<int> v(cols, 0);
        v.back() = 1;
        for (int r = rows - 1; r >= 0; --r) {
            if (obstacleGrid[r][cols - 1])
                v.back() = 0;
            for (int c = cols - 2; c >= 0; --c) {
                v[c] = obstacleGrid[r][c] == 1 ? 0 : v[c] + v[c + 1];
            }
        }

        return v[0];
    }
};