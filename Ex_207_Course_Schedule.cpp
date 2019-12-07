//
// Created by Basti031 on 2019/12/7.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {


        vector<int> inVector = vector<int>(numCourses);//记录每个点的入度

        for (int i = 0; i < prerequisites.size(); ++i) {
            vector<int> edge = prerequisites[i];
            int outPoint = edge[1];
            int inPoint = edge[0];
            inVector[inPoint] = inVector[inPoint] + 1;

        }

        queue<int> q;
        vector<int> v;

        for (int i = 0; i < inVector.size(); ++i) {
            if (inVector[i] == 0) {
                q.push(i);
                v.push_back(i);
            }
        }

        while (!q.empty()) {

            int start = q.front();
            q.pop();

            for (int i = 0; i < prerequisites.size(); ++i) {
                vector<int> edge = prerequisites[i];
                if (edge[1] == start) {
                    inVector[edge[0]]--;
                    if (inVector[edge[0]] == 0) {
                        q.push(edge[0]);
                        v.push_back(edge[0]);
                    }
                }
            }
        }

        return v.size() == numCourses;

    }
};