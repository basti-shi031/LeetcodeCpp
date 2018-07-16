//
// Created by Basti031 on 2018/7/16.
//

#include <iostream>

using namespace std;
//finished
class Solution {
public:
    int dp[1000][1000];

    bool isValid(int i, int j) {
        return i >= 0 && j >= 0;
    }

    int uniquePaths(int m, int n) {
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                int topI = i - 1;
                int topJ = j;

                int leftI = i;
                int leftJ = j - 1;
                int left = 0;
                int top = 0;
                if (isValid(topI, topJ)) {
                    top = dp[topI][topJ];
                }
                if (isValid(leftI, leftJ)) {
                    left = dp[leftI][leftJ];
                }
                dp[i][j] = top + left;
            }
        }

        return dp[n - 1][m - 1];
    }
};
