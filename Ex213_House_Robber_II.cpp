//
// Created by Basti031 on 2019/12/7.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int robber(vector<int> nums) {

        vector<int> v;

        v.push_back(0);
        v.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {

            //v[i] = v[i-1] or v[i-2]+nums[i]
            int result1 = v[i - 1] + nums[i];
            int result2 = v[i];
            v.push_back(max(result1, result2));
        }
        return v[v.size() - 1];
    }


    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> leftNums = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> rightNums = vector<int>(nums.begin() + 1, nums.end());

        int leftResult = robber(leftNums);
        int rightResult = robber(rightNums);

        return max(leftResult, rightResult);


    }
};
/*

int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    Solution solution = Solution();
    cout << solution.rob(v);

}*/
