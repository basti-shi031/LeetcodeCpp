//
// Created by Basti031 on 2019/9/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int inputN;
    int inputK;

    void generate(vector<vector<int>> &result, int n, int k) {

        if (k == 0) {
            return;
        }

        //初始化
        if (k == inputK) {
            for (int i = 0; i < n - k + 1; ++i) {
                vector<int> v;
                v.push_back(i + 1);
                result.push_back(v);
            }

            generate(result, n, k - 1);
        } else {
            int size = result.size();
            int i = 0;
            for (; i < size; ++i) {
                vector<int> tempResult = result[i];
                result.erase(result.begin() + i);
                int maxIndex = inputK - k - 1;
                int currentMax = tempResult[maxIndex];
                int max = n - k + 1;

                for (int j = currentMax + 1; j < max + 1; ++j) {
                    tempResult.push_back(j);
                    result.insert(result.begin() + i, tempResult);
                    tempResult.erase(tempResult.begin() + tempResult.size() - 1);
                }

                size = result.size();
                i = i + max - currentMax-1;
            }
            generate(result, n, k - 1);
        }


    }

    vector<vector<int>> combine(int n, int k) {

        inputK = k;
        inputN = n;
        vector<vector<int>> result;
        generate(result, n, k);

        return result;
    }
};


/*
int main() {
    Solution solution = Solution();
    vector<vector<int>> v = solution.combine(4, 3);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}
*/
