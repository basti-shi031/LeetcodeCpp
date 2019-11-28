//
// Created by Basti031 on 2019/11/28.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isDigits(char c) {
        return c >= '0' && c <= '9';
    }

    bool isAlpha(char c) {
        return c >= 'a' && c <= 'z';
    }

    bool isPalindrome(string s) {

        int size = s.length();
        if (size <= 1) { return true; }


        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int i = 0;
        int j = size - 1;
        while (i < j) {
            while (i < size && (!isAlpha(s[i]) && !isDigits(s[i]))) {
                i++;
            }
            while (j >= 0 && (!isAlpha(s[j]) && !isDigits(s[j]))) {
                j--;
            }

            if (i >= j) {
                break;
            }

            char ci = s[i];
            char cj = s[j];

            if (ci != cj) {
                return false;
            }
            i++;
            j--;

        }

        return true;

    }
};

/*
int main() {
    Solution solution = Solution();
    cout << solution.isPalindrome("ab2a");
}*/
