//
// Created by Basti031 on 2019/11/28.
//


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {

        string ret = "";
        while(n)
        {
            ret = (char)((n-1)%26+'A') + ret;
            n = (n-1)/26;
        }
        return ret;
    }
};