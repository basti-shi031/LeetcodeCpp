//
// Created by Basti031 on 2019/12/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * https://blog.csdn.net/jeanphorn/article/details/47028041 分治法
     * @param matrix
     * @param target
     * @return
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        int ySize = matrix.size();

        if (ySize == 0) {
            return false;
        }

        int xSize = matrix[0].size();
        if (xSize == 0) {
            return false;
        }

        while (true) {

            int rightTop = matrix[0][matrix[0].size() - 1];

            if (rightTop == target) {
                return true;
            } else if (rightTop > target) {
                //去除最后一列
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i].erase(matrix[i].begin()+matrix[i].size()-1);
                }
            } else if (rightTop < target) {
                //去除最顶上一行
                matrix.erase(matrix.begin());
            }

            if (matrix.size() == 0 || matrix[0].size() == 0) {
                return false;
            }
        }
    }
};