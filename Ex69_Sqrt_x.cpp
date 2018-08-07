//
// Created by Basti031 on 2018/8/7.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int mid = 0;
        while (low < high) {
            long mid = (low + high) >> 1;
            if (mid * mid <= x)
                low = mid + 1;
            else
                high = mid;
        }
        return x > 1 ? low - 1 : x;
    }
};
