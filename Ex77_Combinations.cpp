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
        if (n == k) {
            vector<int> a;
            for (int i = 1; i <= n; ++i) {
                a.push_back(i);
            }
            result.push_back(a);
            return;
        }

        if (k == 1) {

            for (int i = 1; i <= n + 1 - inputK; ++i) {
                vector<int> a;
                a.push_back(i);
                result.push_back(a);
            }
        } else {
            //        正常情况
            generate(result, n, k - 1);

            for (int i = 0; i < result.size(); ++i) {

                vector<int> item = result[i];
                result.erase(result.begin() + i);
                int max = item[item.size() - 1];
                for (int j = max + 1; j <= n; ++j) {
                    vector<int> temp = item;
                    temp.push_back(j);
                    result.insert(result.begin() + i, temp);
                }
                i += n - max-1;
            }
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
    vector<vector<int>> v = solution.combine(5,3);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ' ';
        }
        cout<<endl;
    }
}*/
