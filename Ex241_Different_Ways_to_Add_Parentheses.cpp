//
// Created by Basti031 on 2019/12/10.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:

    int findFirstOperation(string s) {
        int index = -1;
        for (int i = 0; i < s.size(); ++i) {

            char c = s[i];

            if (c == '+' || c == '-' || c == '*') {
                return i;
            }
        }
        return index;
    }

    int findLastOperation(string s) {
        int index = -1;
        for (int i = s.size() - 1; i >= 0; --i) {

            char c = s[i];

            if (c == '+' || c == '-' || c == '*') {
                return i;
            }
        }
        return index;
    }


    int stringToInt(string input) {
        int sum = 0;
        for (int i = 0; i < input.size(); ++i) {

            sum = sum * 10 + input[i] - '0';

        }
        return sum;
    }

    int cal(int num1, char operation, int num2) {
        if (operation == '+') {
            return num1 + num2;
        }
        if (operation == '-') {
            return num1 - num2;
        }
        if (operation == '*') {
            return num1 * num2;
        }

        return 0;
    }


    vector<int> calculate(int num, char c, vector<int> result) {

        vector<int> newResult;

        for (int i:result) {
            newResult.push_back(cal(num, c, i));
        }

        return newResult;

    }

    vector<int> calculate(string input) {
        int firstOperationIndex = findFirstOperation(input);
        int lastOperationIndex = findLastOperation(input);

        vector<int> result;
        if (firstOperationIndex == -1) {
            //没有操作符直接返回结果
            int num = stringToInt(input);
            result.push_back(num);
            return result;
        } else if (firstOperationIndex == lastOperationIndex) {
            //只有一个操作符，直接计算
            char operation = input[firstOperationIndex];
            int num1 = stringToInt(input.substr(0, firstOperationIndex));
            int num2 = stringToInt(input.substr(lastOperationIndex + 1, input.size() - lastOperationIndex - 1));

            //计算a?b形式的结果
            int temp = cal(num1, operation, num2);
            result.push_back(temp);
            return result;
        } else {

            int firstNum = stringToInt(input.substr(0, firstOperationIndex));
            char firstOperation = input[firstOperationIndex];

            int lastNum = stringToInt(input.substr(lastOperationIndex + 1, input.size() - lastOperationIndex - 1));
            char lastOperation = input[lastOperationIndex];

            string firstInput = input.substr(firstOperationIndex + 1, input.size() - firstOperationIndex - 1);
            string lastInput = input.substr(0, lastOperationIndex);


            vector<int> firstResult = calculate(firstInput);
            vector<int> lastResult = calculate(lastInput);

            vector<int> first = calculate(firstNum, firstOperation, firstResult);
            if (lastOperation == '-') {
                lastOperation = '+';
                lastNum = -lastNum;
            }

            vector<int> last = calculate(lastNum, lastOperation, lastResult);

            for (int i = 0; i < last.size(); ++i) {

                first.push_back(last[i]);
            }
            return first;
        }


    }

    vector<int> diffWaysToCompute(string input) {

        vector<int> resultSet = calculate(input);

        return vector<int>(resultSet.begin(), resultSet.end());

    }
};

int main() {

    Solution solution = Solution();
    vector<int> v = solution.diffWaysToCompute("1-2+3");

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

}