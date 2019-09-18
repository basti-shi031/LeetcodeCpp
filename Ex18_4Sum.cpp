//
// Created by Basti031 on 2019/9/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:

    set<vector<int>> twoSum(vector<int> &nums, int startIndex, int target) {

        int size = nums.size();
        set<vector<int>> result;
        for (int i = startIndex; i < size - 1; ++i) {
            int num1 = nums[i];
            for (int j = i + 1; j < size; ++j) {
                vector<int> ans;
                int num2 = nums[j];
                if (num1 + num2 == target) {
                    ans.push_back(num1);
                    ans.push_back(num2);
                    result.insert(ans);
                }
                if (num1 + num2 > target) {
                    break;
                }
            }
        }

        return result;

    }

    set<vector<int>> threeSum(vector<int> &nums, int startIndex, int target) {
        set<vector<int>> result;
        int size = nums.size();
        for (int i = startIndex; i < size - 2; ++i) {
            set<vector<int>> twoNums = twoSum(nums, i + 1, target - nums[i]);
            set<vector<int>>::iterator it = twoNums.begin();
            while (it != twoNums.end()) {
                vector<int> a = *it;
                a.insert(a.begin(), nums[i]);
                result.insert(a);
                it++;
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target) {

        set<vector<int>> result;
        vector<vector<int>> result1;

        int size = nums.size();

        sort(nums.begin(), nums.end());

        if (size < 4) {
            return result1;
        }

        for (int i = 0; i < size - 3; ++i) {
            set<vector<int>> threeNums = threeSum(nums, i + 1, target - nums[i]);

            set<vector<int>>::iterator it = threeNums.begin();
            while (it != threeNums.end()) {
                vector<int> a = *it;
                a.insert(a.begin(), nums[i]);
                result.insert(a);
                it++;
            }
        }
        result1.assign(result.begin(), result.end());

        return result1;
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    Solution solution = Solution();
    vector<vector<int>> v1 = solution.fourSum(v, 10);
    for (int i = 0; i < v1.size(); i++) {
        vector<int> ans = v1[i];
        for (int j = 0; j < ans.size(); ++j) {
            cout << ans[j] << ' ';
        }
        cout << endl;
    }
}