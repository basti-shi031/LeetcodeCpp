//
// Created by Basti031 on 2019/11/7.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {

        vector<vector<int>> result(1);
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

        for (int i = 1; i < size; ++i) {

            int result_size = result.size();

            for (int k = 0; k < result_size; ++k) {

                vector<int> temp = result[k];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }

        return result;


    }
};