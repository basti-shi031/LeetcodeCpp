//
// Created by Basti031 on 2019/9/17.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        if (rowIndex == 0) {
            vector<int> result;
            result.push_back(1);
            return result;
        }
        if (rowIndex == 1) {
            vector<int> result;
            result.push_back(1);
            result.push_back(1);
            return result;
        }
        vector<int> nums = getRow(rowIndex - 1);

        vector<int> result;

        result.push_back(1);

        for (int i = 1; i < rowIndex; ++i) {

            result.push_back(nums[i] + nums[i - 1]);

        }
        result.push_back(1);

        return result;


    }
};