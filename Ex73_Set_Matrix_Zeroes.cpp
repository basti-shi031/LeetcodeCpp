#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int mark = -9876;
        if (matrix.empty()) {
            return;
        }
        if (matrix[0].size() == 0) {
            return;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = mark;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == mark) {
                    matrix[i][j] = 0;
                    for (int tempI = 0; tempI < m; ++tempI) {
                        if (matrix[tempI][j] != mark) {
                            matrix[tempI][j] = 0;
                        }
                    }
                    for (int tempJ = 0; tempJ < n; ++tempJ) {
                        if (matrix[i][tempJ] != mark) {
                            matrix[i][tempJ] = 0;
                        }
                    }
                }
            }
        }
    }
};

/*
int main() {
    vector<vector<int>> matrix;
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(2);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(2);
    matrix.push_back(v1);
    Solution solution = Solution();
    solution.setZeroes(matrix);
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}*/
