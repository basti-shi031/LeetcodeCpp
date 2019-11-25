//
// Created by Basti031 on 2019/11/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int findPivotIndex(vector<int> &nums) {

        int size = nums.size();

        for (int i = 0; i < size - 1; ++i) {

            int current = nums[i];
            int next = nums[i + 1];

            if (next < current) {
                return i;
            }
        }
        return size - 1;
    }

    bool search(vector<int> &nums, int start, int end, int target) {

        if (start < 0 || end >= nums.size()) {
            return false;
        }

        while (start <= end) {

            int mid = (start + end) / 2;
            int current = nums[mid];

            if (current < target) {
                start = mid + 1;
            } else if (current > target) {
                end = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }

public:
    bool search(vector<int> &nums, int target) {

        int size = nums.size();
        if (size == 0) {
            return false;
        }

        if (size == 1) {
            return nums[0] == target;
        }

        int pivotIndex = findPivotIndex(nums);

        return search(nums, 0, pivotIndex, target) || search(nums, pivotIndex + 1, size - 1, target);
    }
};