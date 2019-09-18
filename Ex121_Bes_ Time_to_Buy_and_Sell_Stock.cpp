//
// Created by Basti031 on 2019/9/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if (prices.size() <= 1) {
            return 0;
        }


        int size = prices.size();

        vector<int> nums;

        for (int i = 1; i < size; ++i) {
            nums.push_back(prices[i] - prices[i - 1]);
        }

        int size1 = nums.size();
        int max_result = nums[0];
        int sum = max_result;


        for (int index = 1; index < size1; ++index) {

            if (sum < 0) {
                sum = 0;
            }
            sum = sum + nums[index];

            if (sum >= max_result) {
                max_result = sum;
            }
        }

        return max_result < 0 ? 0 : max_result;


    }
};