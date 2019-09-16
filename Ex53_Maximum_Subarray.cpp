//
// Created by Basti031 on 2019/9/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int max_result = nums[0];
        int sum = max_result;

        for (int i = 1; i < size; i++) {
            if (sum < 0) {
                sum = 0;
            }
            sum = sum + nums[i];

            if (sum >= max_result) {
                max_result = sum;
            }


        }

        return max_result;
    }
};

/*
int main() {
    // [-2,1,-3,4,-1,2,1,-5,4],
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
//    nums.push_back(-3);
//    nums.push_back(4);
//    nums.push_back(-1);
//    nums.push_back(2);
//    nums.push_back(1);
//    nums.push_back(-6);
//    nums.push_back(4);

    Solution solution = Solution();
    cout<<solution.maxSubArray(nums);



    system("pause");
}*/
