//
// Created by Basti031 on 2019/9/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

    const static bool intervals_compare(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {

        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), intervals_compare);

        int size = intervals.size();

        if (size == 0) {
            return result;
        }

        vector<int> current = intervals[0];


        if (size == 1) {
            result.push_back(intervals[0]);
            return result;
        }

        for (int i = 1; i < size; ++i) {

            vector<int> next = intervals[i];

            if (next[0] <= current[1]) {
                //重合了，
                int right = max(next[1], current[1]);
                current[1] = right;
            } else {
                //没有重合
                result.push_back(current);
                current = next;

            }
        }
        result.push_back(current);

        return result;
    }
};

/*
int main() {

    vector<vector<int>> input;
    vector<int> interval;
    interval.push_back(1);
    interval.push_back(3);
    input.push_back(interval);

    interval.erase(interval.begin(), interval.end());
    interval.push_back(2);
    interval.push_back(6);
    input.push_back(interval);

    interval.erase(interval.begin(), interval.end());
    interval.push_back(8);
    interval.push_back(10);
    input.push_back(interval);

    interval.erase(interval.begin(), interval.end());
    interval.push_back(15);
    interval.push_back(18);
    input.push_back(interval);


    Solution solution = Solution();
    vector<vector<int>> v = solution.merge(input);


    for (int i = 0; i < v.size(); ++i) {
        cout << v[i][0];
        cout << ' ';
        cout << v[i][1];
        cout << endl;
    }


}*/
