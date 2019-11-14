//
// Created by Basti031 on 2019/11/6.
//

#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] * i;
        }
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};

/*
int main() {
    Solution solution = Solution();
    string a = solution.getPermutation(3, 2);
    cout << a;
};*/
