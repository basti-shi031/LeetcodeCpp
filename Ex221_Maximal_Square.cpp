//
// Created by Basti031 on 2019/10/16.
//

class Solution {
public:
    int maximalSquare(vector <vector<char>> &matrix) {


        int height = matrix.size();
        if (height == 0)
            return 0;
        int width = matrix[0].size();
        vector <vector<int>> vec(height, vector<int>(width, 0));
        int result = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == '1') {
                    vec[i][j] = 1;
                    if (i > 0 && j > 0)
                        vec[i][j] += min(min(vec[i - 1][j], vec[i][j - 1]), vec[i - 1][j - 1]);
                }
                result = max(result, vec[i][j]);
            }
        }
        return result * result;
    }
};