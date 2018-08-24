//
// Created by Basti031 on 2018/8/24.
//

#include <string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {

        vector<int> v;

        int cnt = 0;
        int size = s.length();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return s[0] == '0' ? 0 : 1;
        }
        v.push_back(0);
        int a = s[size-1]-'0'+(s[size-2]-'0')*10;
        if (s[size-1] == '0') {
            v.push_back(0);
        } else {
            v.push_back(1);
        }
        if (s[size-1] == '0' && s[size-2] == '0') {
            v.push_back(0);
        } else if ((s[size-1] == '0' && s[size-2] != '0')||(a>26||a<10)) {
            v.push_back(1);
        } else {
            v.push_back(2);
        }
        for (int i = 3; i <= size; ++i) {
            int ge = s[size-i+1] - '0';
            int shi = s[size-i] - '0';
            int num = ge + shi * 10;
            if (num >= 1 && num <= 26) {
                v.push_back(v[i - 1] + v[i - 2]);
            } else {
                v.push_back(v[i - 1]);
            }
        }
        return v[size];
    }
};

int main() {
    Solution solution = Solution();
    int a = solution.numDecodings("07");
    cout << a;
}