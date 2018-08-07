//
// Created by Basti031 on 2018/8/7.
//
#include <iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row_num = matrix.size();
        if (row_num == 0){
            return false;
        }
        int col_num = matrix[0].size();

        if (row_num == 0 || col_num == 0){
            return false;
        }

        int begin = 0, end = row_num * col_num - 1;

        while (begin <= end) {
            int mid = (begin + end) / 2;
            int mid_value = matrix[mid / col_num][mid % col_num];

            if (mid_value == target) {
                return true;

            } else if (mid_value < target) {
                //Should move a bit further, otherwise dead loop.
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    vector<int> v1, v2, v3, v4;
    vector<vector<int>> result;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);

    v2.push_back(10);
    v2.push_back(11);
    v2.push_back(16);
    v2.push_back(20);

    v3.push_back(23);
    v3.push_back(30);
    v3.push_back(34);
    v3.push_back(50);

    v4.push_back(61);
    v4.push_back(67);
    v4.push_back(70);
    v4.push_back(71);

//    result.push_back(v1);
//    result.push_back(v2);
//    result.push_back(v3);
//    result.push_back(v4);
    Solution solution = Solution();
    cout << solution.searchMatrix(result, 0);
}