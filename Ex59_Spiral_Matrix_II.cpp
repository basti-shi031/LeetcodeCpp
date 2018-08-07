//
// Created by Basti031 on 2018/7/26.
//
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int rows = n;
        int cols = n;
        int row=0;
        int col = 0;
        int i= row;
        int j = col;
        int iVal,jVal;
        while(rows>1 && cols > 1){
            while(j<cols+col){
                ans[i][j] = num++;
                ++j;
            }
            --j;
            ++i;
            while(i<rows+row){
                ans[i][j] = num++;
                ++i;
            }
            --i;
            jVal = j;
            --j;
            while(j>jVal-cols){
                ans[i][j] = num++;
                --j;
            }
            ++j;
            iVal = i;
            --i;
            while(i>iVal-rows+1){
                ans[i][j] = num++;
                --i;
            }
            rows -= 2;
            cols -= 2;
            row += 1;
            col += 1;
            i=row;
            j=col;

        }
        if(rows==1 && cols == 1){
            while(j<col+cols){
                ans[i][j] = num++;
                ++j;
            }
        }
        return ans;
    }
};
