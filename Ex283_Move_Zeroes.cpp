//
// Created by Basti031 on 2019/12/10.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {

        int size = nums.size();

        if (size == 0 || size == 1) {
            return;
        }

        int firstZeroIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                firstZeroIndex = i;
                break;
            }
        }

        if (firstZeroIndex == -1) {
            return;
        }

        for (int j = firstZeroIndex + 1; j < size; ++j) {

            int num = nums[j];
            if (num == 0) {
                continue;
            } else {
                nums[firstZeroIndex] = nums[j];
                nums[j] = 0;

                firstZeroIndex++;
            }
        }
    }
};
