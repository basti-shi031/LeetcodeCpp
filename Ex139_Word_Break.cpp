//
// Created by Basti031 on 2019/10/9.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {

        set<string> wordSet;

        for (int k = 0; k < wordDict.size(); ++k) {

            wordSet.insert(wordDict[k]);

        }

        int size = s.length();
//        vector<bool> results;
        vector<int> tempResult;
        tempResult.push_back(-1);
        for (int i = 0; i < size; ++i) {

            /*   if (tempResult.size() == 0) {
                   string waitToMatch = s.substr(0, i + 1);
                   if (find(wordDict.begin(), wordDict.end(), waitToMatch) == wordDict.end()) {
   //                    没找到
                   } else {
                       tempResult.push_back(i);
                       continue;
                   }
               } else */{
                for (int j = 0; j < tempResult.size(); ++j) {

                    int startIndex = tempResult[j];
                    string waitToMatch = s.substr(startIndex + 1, i - startIndex);
                    if (find(wordSet.begin(), wordSet.end(), waitToMatch) == wordSet.end()) {
//                    没找到
                    } else {
                        tempResult.push_back(i);
                        break;
                    }

                }
            }
        }

        return !(find(tempResult.begin(), tempResult.end(), size - 1) == tempResult.end());
    }
};

/*
int main() {
    string s1 = "leetcode";
    Solution solution = Solution();
    vector<string> se;
    se.push_back("le");
    se.push_back("leetcode");
    cout << solution.wordBreak(s1, se);
}*/
