//
// Created by Basti031 on 2018/8/24.
//

#include <string>
#include<vector>
#include<iostream>
#include <map>

using namespace std;

class Solution {

    map<string, int> maps;

public:
    int numDecodings(string s) {

        if (s.length() == 0) {
            return 1;
        }

        if (s.length() == 1) {
            if (s.at(0) == '0') {
                return 0;
            } else {
                return 1;
            }
        }

        char c1 = s.at(0);
        char c2 = s.at(1);

        int i1 = c1 - '0';
        int i2 = i1 * 10 + c2 - '0';

        int flag1 = 0;
        int flag12 = 0;
        if (i1 >= 1 && i1 <= 26) {
            flag1 = 1;
        }
        if (i2 >= 1 && i2 <= 26 && i1 != 0) {
            flag12 = 1;
        }

        int result1 = 0;
        int result12 = 0;

        if (flag1 == 1) {
            string temp_s1 = s.substr(1, s.length() - 1);
            if (maps.find(temp_s1) != maps.end()) {
                result1 = maps[temp_s1];
            } else {
                result1 = numDecodings(temp_s1);
            }
            maps[temp_s1] = result1;

        }
        if (flag12 == 1) {
            string temp_s12 = s.substr(2, s.length() - 2);
            if (maps.find(temp_s12) != maps.end()) {
                result12 = maps[temp_s12];
            } else {
                result12 = numDecodings(temp_s12);
            }
            maps[temp_s12] = result1;
        }


        return result1 + result12;
    }
};
/*

int main() {

    Solution solution = Solution();
    int a = solution.numDecodings(
//            "6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155");
           "9355141842519423434975558424574331479338913773268525913972842463395324957127519863135646135786662832");
    cout << a;
}
*/

