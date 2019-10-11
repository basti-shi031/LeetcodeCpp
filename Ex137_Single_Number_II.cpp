//
// Created by Basti031 on 2019/10/9.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {

        set<int> single;

        int size = nums.size();
        long sum = 0;
        long set_sum = 0;
        for (int i = 0; i < size; ++i) {
            int a = nums[i];
            sum += a;
            if (single.find(a) == single.end()) {
                single.insert(a);
                set_sum += a;
            }
        }

        return (set_sum * 3 - sum) / 2;

    }
};

/*
int main() {
    vector<int> a;
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(2);
    Solution solution = Solution();
    cout << solution.singleNumber(a);
}*/
