//
// Created by Basti031 on 2019/9/16.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;

        int size_a = a.length();
        int size_b = b.length();

        int index_a = size_a - 1;
        int index_b = size_b - 1;

        int flag = 0;


        while (index_a >= 0 || index_b >= 0) {
            int int_a = index_a < 0 ? 0 : a[index_a] - '0';
            int int_b = index_b < 0 ? 0 : b[index_b] - '0';

            int sum = (int_a + int_b + flag) % 2;
            flag = (int_a + int_b + flag) / 2;
            result.push_back('0' + sum);
            index_a--;
            index_b--;
        }

        if (flag == 1) {
            result.push_back('0' + flag);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/*
int main() {
//    nums.push_back(-3);
//    nums.push_back(4);
//    nums.push_back(-1);
//    nums.push_back(2);
//    nums.push_back(1);
//    nums.push_back(-6);
//    nums.push_back(4);

    Solution solution = Solution();
    cout << solution.addBinary("10", "1011");

}*/
