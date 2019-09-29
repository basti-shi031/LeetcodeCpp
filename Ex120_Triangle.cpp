//
// Created by Basti031 on 2019/9/29.
//

#include <vector>
#include <math.h>
#include <iostream>
#include <limits.h>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> result;

        if (triangle.size() == 0) {
            return 0;
        }

        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        vector<int> first;
        first.push_back(triangle[0][0]);
        result.push_back(first);
        int size = triangle.size();
        for (int i = 1; i < size; ++i) {

            vector<int> next;
            vector<int> current = result[result.size() - 1];

            for (int j = 0; j < triangle[i].size(); ++j) {
                int iIndex = i - 1;
                int jIndex1 = j - 1;
                int jIndex2 = j;

                int candidateLeft = jIndex1 < 0 ? INT_MAX : result[iIndex][jIndex1] + triangle[i][j];
                int candidateRight =
                        jIndex2 > triangle[i].size()-2? INT_MAX : result[iIndex][jIndex2] + triangle[i][j];
                next.push_back(min(candidateLeft, candidateRight));
            }
            result.push_back(next);
        }

        vector<int> last = result[result.size() - 1];

        int minResult = INT_MAX;
        for (int k = 0; k < last.size(); ++k) {

            minResult = min(minResult, last[k]);

        }
        return minResult;

    }
};

/*
int main() {

    vector<vector<int>> input;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;

    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    c.push_back(6);
    c.push_back(5);
    c.push_back(7);
    d.push_back(4);
    d.push_back(1);
    d.push_back(8);
    d.push_back(3);

    input.push_back(a);
    input.push_back(b);
    input.push_back(c);
    input.push_back(d);

    Solution solution = Solution();
    cout<<solution.minimumTotal(input);

}*/
