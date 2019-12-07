//
// Created by Basti031 on 2019/12/7.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {

        if (nums.size() == 0 || nums.size() == 1) {
            return false;
        }

        set<int> s;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //此次需要从s中移除的index
            j = i - k - 1;
            if (j >= 0) {
                s.erase(nums[j]);
            }

            int num = nums[i];
            if (s.find(num) != s.end()) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    Solution solution = Solution();
    solution.containsNearbyDuplicate(v, 2);
}