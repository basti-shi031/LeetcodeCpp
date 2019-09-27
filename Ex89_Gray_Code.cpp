//
// Created by Basti031 on 2019/9/24.
//
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:

    void generate(vector<int> &result, int n) {

        if (n == 0) {
            result.push_back(0);
            return;
        }

        generate(result, n - 1);

        int delta = pow(2, n - 1);
        int size = result.size();
        for (int i = size - 1; i >= 0; --i) {
            result.push_back(result[i] + delta);
        }
    }

    vector<int> grayCode(int n) {

        vector<int> result;
        generate(result, n);
        return result;

    }
};

/*
int main() {
    Solution solution = Solution();
    vector<int> v = solution.grayCode(3);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        cout << endl;
    }
}*/
