//
// Created by Basti031 on 2018/6/24.
//

#include<iostream>
#include<vector>

using namespace std;

//finished
class Solution {
public:
    void generate(vector<int> nums, int index, vector<vector<int>> &result) {

        if (index == nums.size()) {
            return;
        }

        if (index == 0) {
            vector<int> a;
            a.push_back(nums[0]);
            result.push_back(a);
        } else {

            int num = nums[index];

            int size = result.size();
            for (int i = 0; i < size; ++i) {
                vector<int> item = result[i];

                int itemSize = item.size();
                for (int j = 0; j < itemSize + 1; ++j) {
                    vector<int> temp = item;
                    temp.insert(temp.begin() + j, num);
                    result.push_back(temp);
                }
            }
            result.erase(result.begin(), result.begin() + size);
        }
        generate(nums, index + 1, result);


    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }

        generate(nums, 0, result);

        return result;
    }
};