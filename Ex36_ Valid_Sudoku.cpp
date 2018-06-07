#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

//finished
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		set<string> r_set, c_set, g_set;

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char ch = board[i][j];
				if (ch != '.') {
					int grid = ((i / 3) * 3) + (j / 3);
					string r_str = "r" + to_string(i) + string(1, ch);
					string c_str = "c" + to_string(j) + string(1, ch);
					string g_str = "g" + to_string(grid) + string(1, ch);

					if (r_set.find(r_str) != r_set.end() ||
						c_set.find(c_str) != c_set.end() ||
						g_set.find(g_str) != g_set.end())
						return false;
					r_set.insert(r_str);
					c_set.insert(c_str);
					g_set.insert(g_str);
				}
			}
		}
		return true;
	}
};