//
// Created by Basti031 on 2019/9/17.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i1 = m - 1, i2 = n - 1, k = m + n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] < nums2[i2]) {
                nums1[k--] = nums2[i2--];
            } else {
                nums1[k--] = nums1[i1--];
            }
        }
        while (i2 >= 0) {
            nums1[k--] = nums2[i2--];
        }

        return;
    }
};

/*
int main() {
    Solution solution = Solution();

    vector<int> num1, num2;

    num1.push_back(1);
    num1.push_back(2);
    num1.push_back(3);
    num1.push_back(4);
    num1.push_back(0);
    num1.push_back(0);
    num2.push_back(5);
    num2.push_back(6);


    solution.merge(num1, 4, num2, 2);


    for (int i = 0; i < num1.size(); ++i) {
        cout << num1[i] << endl;
    }

    return 0;
}*/
