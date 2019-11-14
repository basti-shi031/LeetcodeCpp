//
// Created by Basti031 on 2019/10/21.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums);
        res[nums.size() - 1] = 1;
        for(int i = res.size() - 2; i >= 0; i--)
            res[i] = nums[i + 1] * res[i + 1];
        for(int i = 1; i < res.size(); i++){
            res[i] *= nums[i - 1];
            nums[i] *= nums[i - 1];
        }
        return res;
    }
};