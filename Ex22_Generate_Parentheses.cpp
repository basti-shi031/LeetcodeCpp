#include<iostream>
#include<vector>
#include<string>

using namespace std;

//finished
class Solution {
public:

    void generate(int left, int right, string arg, vector<string>& result) {

        if (left > right) return;
        if (left == 0 && right == 0) {
            result.push_back(arg);
        }

        if (left > 0) {
            generate(left - 1, right, arg + "(", result);
        }
        if (right > 0) {
            generate(left, right - 1, arg + ")", result);
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> result;

        if (n <= 0) {
            return result;
        }

        generate(n, n, "", result);
        return result;
    }
};

/*
int main() {
    Solution solution = Solution();
    vector<string> result = solution.generateParenthesis(3);
    cout<<result.size();
}
*/

