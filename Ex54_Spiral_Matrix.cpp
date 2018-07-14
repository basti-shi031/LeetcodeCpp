//
// Created by Basti031 on 2018/7/14.
//

#include "vector"

using namespace std;
//finished
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int left = 0;
        if (matrix.size() == 0) {
            return result;
        }
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (left <= right && top <= bottom) {
            vector<int> topList = matrix[top];
            //=====>
            for (int i = left; i <= right; i++) {
                result.push_back(topList[i]);
            }
            int verticalDivider = bottom - top;
            int horiDivider = right - left;
            //↓
            if (verticalDivider >= 2) {
                for (int i = top + 1; i < bottom; ++i) {
                    result.push_back(matrix[i][right]);
                }
            }
            //←
            if (verticalDivider >= 1) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
            }
            //↑
            if (verticalDivider >= 2&&horiDivider>=1) {
                for (int i = bottom - 1; i >= top + 1; --i) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
            top++;
            bottom--;
            right--;
        }

        return result;
    }

};