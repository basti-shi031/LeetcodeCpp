//
// Created by Basti031 on 2019/12/7.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //  x       y       x    y        x      y      x      y

        int aArea = abs(C - A) * abs(D - B);
        int bArea = abs(G - E) * abs(H - F);

        //先计算不重叠的情况
        //EFGH在ABCD上方，即EFGH底边在ABCD上边的上方
        // 下方
        //左方
        //右方
        if (F >= D || B >= H || G <= A || E >= C) {
            return aArea + bArea;
        }

        //有重叠
        return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;


    }
};