//
// Created by Basti031 on 2019/11/14.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {

        vector<vector<int>> result(1);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 0) {
            return result;
        }
        vector<int> first_v;
        first_v.push_back(nums[0]);
        result.push_back(first_v);
        if (size == 1) {
            return result;
        }
        int last = 0;
        int index = 1;//上一次循环结束的起始点
        for (int i = 1; i < size; ++i) {
            int start = 0;
            last = nums[i - 1];
            int current = nums[i];
            if (current == last) {
                start = index;
            }
            int current_size = result.size();
            index = current_size;

            for (int j = start; j < current_size; ++j) {
                vector<int> temp = result[j];
                temp.push_back(current);
                result.push_back(temp);
            }


        }
        return result;

    }
};

/*
int main() {

    Solution solution = Solution();

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);

    vector<vector<int>> result = solution.subsetsWithDup(v);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}*/
