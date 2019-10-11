//
// Created by Basti031 on 2019/10/11.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {

        vector<int> v;
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        v.push_back(nums[0]);
        v.push_back(max(nums[0], nums[1]));

        for (int i = 2; i < nums.size(); ++i) {

            int a = max(v[i - 1], v[i - 2] + nums[i]);
            v.push_back(a);
        }

        return v[v.size() - 1];
    }
};
/*

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(1);

    Solution solution = Solution();
    cout << solution.rob(a);
}*/
