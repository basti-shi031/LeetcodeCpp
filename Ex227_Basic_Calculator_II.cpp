//
// Created by Basti031 on 2019/12/10.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:

    long long calculate(long long a1, long long a2, char c) {
        if (c == '+') {
            return a1 + a2;
        }
        if (c == '-') {
            return a2 - a1;
        }
        if (c == '*') {
            return a1 * a2;
        }
        if (c == '/') {
            return a2 / a1;
        }

        return 0;
    }


    int calculate(string s) {

        long long currentResult = 0;

        stack<long long> numStack;
        stack<char> operationStack;

        int index = 0;

        while (index < s.size()) {
            char c = s[index];

            if (c == '+' || c == '-') {
                //加减号

                if (operationStack.size() == 0) {
                    operationStack.push(c);
                } else {
                    char operation = operationStack.top();
                    operationStack.pop();
                    long long a1 = numStack.top();
                    numStack.pop();
                    long long a2 = numStack.top();
                    numStack.pop();
                    long long temp = calculate(a1, a2, operation);
                    numStack.push(temp);
                    operationStack.push(c);
                }
            } else if (c == '*' || c == '/') {
                //乘除
                if (operationStack.size() == 0) {
                    operationStack.push(c);
                } else {
                    char operation = operationStack.top();
                    if (operation == '+' || operation == '-') {

                        operationStack.push(c);

                    } else {
                        long long a1 = numStack.top();
                        numStack.pop();
                        long long a2 = numStack.top();
                        numStack.pop();

                        long long temp = calculate(a1, a2, operation);
                        numStack.push(temp);
                        operationStack.pop();
                        operationStack.push(c);
                    }
                }

            } else if (c >= '0' && c <= '9') {
                //数字
                long long num = c - '0';
                index += 1;
                while (index < s.size()) {
                    char c = s[index];
                    if (c >= '0' && c <= '9') {
                        num = num * 10 + c - '0';
                        index++;
                    } else {
                        index--;
                        break;
                    }
                }
                numStack.push(num);
            }
            index++;
        }

        while (numStack.size() != 0) {

            int num1 = numStack.top();
            numStack.pop();
            currentResult = num1;
            if (numStack.size() == 0) {
                return currentResult;
            }
            int num2 = numStack.top();
            numStack.pop();

            char c = operationStack.top();
            operationStack.pop();

            long long num = calculate(num1, num2, c);
            numStack.push(num);
        }

        return 0;


    }

    int calculate2(string s) {
        long res = 0, num = 0, n = s.size();
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+')
                    st.push(num);
                if (op == '-')
                    st.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }

};
/*

int main() {

    Solution solution = Solution();
    cout << solution.calculate2("3-1*2");

}*/
