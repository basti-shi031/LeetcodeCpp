//
// Created by Basti031 on 2019/10/21.
//

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {

        set<int> numsSet;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {

            if (find(numsSet.begin(), numsSet.end(), nums[i]) != numsSet.end()) {
                return nums[i];
            }
            numsSet.insert(nums[i]);
        }

        return -1;
    }
};
/*

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    Solution solution = Solution();
    cout << solution.findDuplicate(v);
}*/
