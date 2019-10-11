//
// Created by Basti031 on 2019/10/10.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
public:


    void explore(int i, int j, vector<vector<char>> &grid) {
//        cout << i << ' ' << j << endl;
        grid[i][j] = '2';
        for (int k = 0; k < 4; ++k) {
            if (i + dy[k] >= 0 && i + dy[k] < grid.size() &&
                j + dx[k] >= 0 && j + dx[k] < grid[i + dy[k]].size()) {
                if (grid[i + dy[k]][j + dx[k]] == '1') {

                    explore(i + dy[k], j + dx[k], grid);
                }
            }
        }


    }

    int numIslands(vector<vector<char>> &grid) {


        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {

            for (int j = 0; j < grid[i].size(); ++j) {

//                cout << i << ' ' << j<<endl;
                char c = grid[i][j];
                if (c == '1') {

                    explore(i, j, grid);
                    count++;
                }
            }
        }

        return count;

    }
};

/*
int main() {
    vector<vector<char>> v;
    vector<char> a;
    vector<char> b;
    vector<char> c;
    vector<char> d;
    a.push_back('1');
    a.push_back('1');
    a.push_back('0');
    a.push_back('0');
    a.push_back('0');

    b.push_back('1');
    b.push_back('1');
    b.push_back('0');
    b.push_back('0');
    b.push_back('0');

    c.push_back('0');
    c.push_back('0');
    c.push_back('1');
    c.push_back('0');
    c.push_back('0');

    d.push_back('0');
    d.push_back('0');
    d.push_back('0');
    d.push_back('1');
    d.push_back('1');

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    Solution solution = Solution();
    cout << solution.numIslands(v);
}*/
