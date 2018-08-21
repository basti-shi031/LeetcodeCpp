//
// Created by Basti031 on 2018/8/7.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        bool flag = true;
        for (int i = size - 1; i >= 0; --i) {
            if (flag) {
                int a = digits[i];
                a += 1;
                if (a >= 10) {
                    flag = true;
                    a = a % 10;
                    digits[i] = a;
                } else {
                    digits[i] = a;
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
