//
// Created by Basti031 on 2019/10/21.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {

        if (num < 1) {
            return false;
        }

        while (true) {

            if (num == 1) {
                return true;
            }

            if (num % 2 == 0) {
                num = num / 2;
                continue;
            }
            if (num % 3 == 0) {
                num = num / 3;
                continue;
            }

            if (num % 5 == 0) {
                num = num / 5;
                continue;
            }
            return false;
        }
    }
};