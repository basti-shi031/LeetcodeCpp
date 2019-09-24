//
// Created by Basti031 on 2019/9/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;
//https://www.jianshu.com/p/cbb59321c306
class Solution {
public:
    void nextPermutation(vector<int> &nums) {

        int size = nums.size();
        if (size == 0 || size == 1) {
            return;
        }

        int needChangeIndex = size - 2;
        for (int i = size - 2; i >= -1; --i) {

            if (i == -1) {
                needChangeIndex = -1;
            } else if (nums[i] < nums[i + 1]) {
                needChangeIndex = i;
                break;
            }
        }

        if (needChangeIndex == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int min = INT_MAX;
        int minIndex = 0;
        //找大于needChangeIndex且最小的数
        for (int j = needChangeIndex + 1; j < size; ++j) {
            int n = nums[j];
            if (n > nums[needChangeIndex] && n < min) {
                min = n;
                minIndex = j;
            }
        }

        int temp = nums[needChangeIndex];
        nums[needChangeIndex] = nums[minIndex];
        nums[minIndex] = temp;
        sort(nums.begin() + needChangeIndex + 1, nums.end());
    }
};
/*

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);

    Solution solution = Solution();
    solution.nextPermutation(nums);
}*/
