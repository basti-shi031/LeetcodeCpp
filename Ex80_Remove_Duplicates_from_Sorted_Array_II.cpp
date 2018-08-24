//
// Created by Basti031 on 2018/8/23.
//
#include <iostream>

#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }

        int cnt = 0;
        int index = 0;
        int lastNum = 0;
        bool isFirst = true;
        int dup = 0;
        int lastIndex = 0;
        while (true) {
            int num = nums[index];
            if (!isFirst && num == lastNum) {
                //相等，前指针不动,后指针往后走
                cnt++;
                lastIndex = index + 1;
                while (nums[lastIndex] == lastNum && lastIndex < size) {
                    nums.erase(nums.begin()+lastIndex);
                    size = nums.size();
                }
                index = lastIndex;
            } else {
                //不等
                lastNum = nums[index];
                cnt++;
                index++;
            }
            isFirst = false;

            if (index == size) {
                return cnt;
            }
        }
    }
};
