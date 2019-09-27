//
// Created by Basti031 on 2019/9/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows == 0)
            return ret;

        vector<int> last(1,1);
        ret.push_back(last);
        for(int i = 2; i <= numRows; i ++)
        {// i_th level
            last.push_back(0);
            vector<int> cur = last;
            for(int j = 1; j < i; j ++)
            {
                cur[j] = last[j] + last[j-1];
            }
            ret.push_back(cur);
            last = cur;
        }
        return ret;
    }
};