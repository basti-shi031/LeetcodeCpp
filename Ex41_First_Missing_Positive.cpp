//
// Created by Basti031 on 2019/11/6.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {

        int size = nums.size();

        for (int i = 0; i < size; ++i) {

            while (true) {
                int num = nums[i];
                if (num >= 1 && num <= size && num != nums[num - 1]) {


                    int correctIndex = num - 1;
                    int temp = nums[correctIndex];
                    nums[correctIndex] = num;
                    nums[i] = temp;
                } else {
                    break;
                }
            }
        }

        for (int j = 0; j < size; ++j) {

            int num = nums[j];
            if (num != j + 1) {
                return j + 1;
            }
        }
        return size + 1;

    }
};

/*
int main() {
    Solution solution = Solution();
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(1);

    int a = solution.firstMissingPositive(v);
    cout << a;
}*/
