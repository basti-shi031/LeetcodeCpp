//
// Created by Basti031 on 2019/11/28.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(" ") + 1);

        int i = 0;
        int j = 0;

        int start = 0;
        int index = 0;
        while (true) {
            int index = s.find_first_of(' ', start);

            if (index == -1) {
                reverse(s.begin() + start, s.end());
                break;
            } else {
                reverse(s.begin() + start, s.begin() + index);
                start = index + 1;

                while (s[start] == ' ') {
                    s.erase(s.begin() + start);
                }
            }
        }

        return s;
    }
};

int main() {
    Solution solution = Solution();
    string s = solution.reverseWords("   a   b  c d   e  ");
    cout << s;
}