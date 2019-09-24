//
// Created by Basti031 on 2019/9/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void generateResult(vector<vector<int>> &result, vector<int> nums, vector<int> &candidates, int index, int target) {

        if (target == 0) {
            result.push_back(nums);
        }
        int size = candidates.size();

        for (int i = index; i < size; ++i) {

            if (candidates[i] > target) {
                break;
            }
            nums.push_back(candidates[i]);
            generateResult(result, nums, candidates, i, target - candidates[i]);
            nums.pop_back();

        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        generateResult(result, nums, candidates, 0, target);

        return result;
    }
};

/*
int main() {

    Solution solution = Solution();

    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    vector<vector<int>> res = solution.combinationSum(v, 7);

    for (int i = 0; i < res.size(); ++i) {

        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j];
        }
        cout << endl;
    }
}*/
