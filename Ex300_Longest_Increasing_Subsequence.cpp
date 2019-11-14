//
// Created by Basti031 on 2019/10/13.
// ]

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {

        int size = nums.size();
        if (size == 0 || size == 1) {
            return size;
        }

        vector<int> v;
        v.push_back(1);

        for (int i = 1; i < size; ++i) {

            int num = nums[i];

            int max_length = -1;
            for (int j = 0; j < i; ++j) {

                if (nums[j] < num) {
                    max_length = max(max_length, v[j] + 1);
                }
            }
            if (max_length == -1) {
                v.push_back(1);
            } else {
                v.push_back(max_length);
            }
        }

        return *max_element(begin(v), end(v));
    }
};