//
// Created by Basti031 on 2019/9/27.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class Solution {
public:

    int sum1(vector<int> nums) {
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {

            sum += nums[i];

        }
        return sum;
    }

    bool init(vector<vector<bool>> &statusVector, int target, vector<int> nums) {

        vector<bool> firstLine;
        for (int i = 0; i <= target; ++i) {
            if (i == nums[0]) {
                firstLine.push_back(true);
                if (i == target){
                    return true;
                }

            } else {
                firstLine.push_back(false);
            }
        }
        statusVector.push_back(firstLine);

        for (int j = 1; j < nums.size(); ++j) {
            vector<bool> temp;
            temp.push_back(false);
            statusVector.push_back(temp);
        }
        return false;
    }


    bool canPartition(vector<int> &nums) {

        int sum = sum1(nums);

        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        int size = nums.size();

        if (size == 1) {
            return false;
        }

        vector<vector<bool>> statusVector;

        bool success = init(statusVector, target, nums);

        if (success) {
            return true;
        }

        for (int i = 1; i < size; ++i) {
            for (int j = 1; j < target + 1; ++j) {

                int i1 = i - 1;
                int j1 = j;
                int i2 = i - 1;
                int j2 = j - nums[i];
                bool first = statusVector[i1][j1];
                bool second = j2 < 0 ? false : statusVector[i2][j2];
                bool result = first || second;
                statusVector[i].push_back(result);
                if (target == j && result) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(11);
    a.push_back(5);

    Solution solution = Solution();
    cout<<solution.canPartition(a);
}