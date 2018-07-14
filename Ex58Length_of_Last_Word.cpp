//
// Created by Basti031 on 2018/7/14.
//
#include<iostream>
#include<string>

using namespace std;
//finished
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int length = 0;
        for (int index = size - 1; index >= 0; index--) {
            char c = s[index];
            if (c == ' ') {
                if (length == 0) {
                    continue;
                } else {
                    break;
                }
            }
            length++;
        }
        return length;
    }
};