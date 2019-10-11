//
// Created by Basti031 on 2019/10/11.
//

#include <iostream>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        set<int> resultSet;
        while (n != 1 && resultSet.find(n) == resultSet.end()) {
            resultSet.insert(n);
            int sum = 0;

            while (n != 0) {
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            n = sum;
        }

        if (n == 1) {
            return true;
        } else {
            return false;
        }

    }
};

/*
int main() {
    Solution solution = Solution();
    cout<<solution.isHappy(19);
}
*/

