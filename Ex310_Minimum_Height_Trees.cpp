
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {

        vector<int> countsVector;
        for (int i = 0; i < n; ++i) {
            countsVector.push_back(i, 0);
        }

        for (int j = 0; j < edges.size(); ++j) {
            vector<int> edge = edges[j];
            int v0 = edge[0];
            int v1 = edge[1];
            countsVector[v0] = countsVector[v0] + 1;
            countsVector[v1] = countsVector[v1] + 1;
        }
        vector<int> result;
        while (true) {
            vector<int> zeroV;
            for (int k = 0; k < n; ++k) {
                if (countsVector[k] == 1) {
                    zeroV.push_back(k);
                }
            }

            for (int i = 0; i < edges; ++i) {
                vector<int> edge = edges[i];
                int v0 = edge[0];
                int v1 = edge[1];

                if (find(zeroV.begin(), zeroV.end(), v0) != zeroV.end()) {

                }


            }

        }
    }
};