//
// Created by Basti031 on 2018/8/23.
//

#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        vector<double> v;
        vector<double> p;
        if (n == 0) {
            return 1;
        }

        if (x == 1.0) {
            return 1;
        }

        if (x == -1.0) {
            return n % 2 ? -1 : 1;
        }
        double n2 = n;

        bool positive = n2 > 0;
        if (!positive) {
            n2 = abs(n2);
            x = 1 / x;
        }
        double a = x;
        double p1 = 1;
        v.push_back(a);
        p.push_back(p1);
        for (int i = 2; i <= n2; i = i * 2) {
            a = a * a;
            if (a == 0.0) {
                return 0;
            }
            v.push_back(a);
            p1 = p1 * 2;
            p.push_back(p1);
        }
        double result = 1;
        int size = p.size();
        int index = size - 1;
        while (n2 > 0) {
            int pow = p[index];
            if (n2 >= pow) {
                n2 -= pow;
                result = result * v[index];
                index--;
            } else {
                index--;
                continue;
            }
        }

        return result;

    }
};