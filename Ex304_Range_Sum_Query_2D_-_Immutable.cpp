//
// Created by Basti031 on 2019/12/26.
//

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:

    vector<vector<int>> m;

    NumMatrix(vector<vector<int>> &matrix) {

        m = matrix;

    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = 0;

        for (int i = row1; i <= row2; ++i) {

            for (int j = col1; j <= col2; ++j) {
                sum += m[i][j];
            }
        }
        return sum;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){

    vector<vector<int>> v;


}