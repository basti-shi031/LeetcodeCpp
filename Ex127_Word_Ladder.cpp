//
// Created by Basti031 on 2019/11/27.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {

    class Word {
    public:
        string word;
        int level;
    };

public:
    bool canTransform(string start, string next) {
        if (start.length() != next.length()) {
            return false;
        }

        int diffNum = 0;
        for (int i = 0; i < start.length(); ++i) {
            char c = start[i];

            if (c != next[i]) {
                diffNum++;
            }
            if (diffNum > 1) {
                return false;
            }
        }
        return true;

    }

    map<string, vector<string>> construct(string beginWord, string endWord, vector<string> wordList) {
        wordList.push_back(beginWord);
        map<string, vector<string>> graph;
        for (int i = 0; i < wordList.size(); ++i) {
            string word = wordList[i];
            vector<string> v;
            graph.insert(pair<string, vector<string>>(word, v));
        }

        for (int index = 0; index < wordList.size() - 1; ++index) {
            string word = wordList[index];
            for (int j = index + 1; j < wordList.size(); ++j) {
                string nextWord = wordList[j];
                bool transform = canTransform(word, nextWord);
                if (transform) {
                    graph[word].push_back(nextWord);
                    graph[nextWord].push_back(word);
                }
            }
        }
        return graph;
    }


    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        set<string> wordSet;
        map<string, vector<string>> graph = construct(beginWord, endWord, wordList);

        queue<Word> q;
        Word word;
        word.word = beginWord;
        word.level = 1;
        q.push(word);
        wordSet.insert(beginWord);
        int step = 1;
        while (!q.empty()) {

            Word topWord = q.front();
            q.pop();
            vector<string> candidateList = graph[topWord.word];

            for (int i = 0; i < candidateList.size(); ++i) {
                string candidate = candidateList[i];
                if (candidate.compare(endWord) == 0) {
                    return topWord.level + 1;
                } else {
                    if (wordSet.find(candidate) == wordSet.end()) {
                        Word candidateWord;
                        candidateWord.word = candidate;
                        candidateWord.level = topWord.level + 1;
                        q.push(candidateWord);
                        wordSet.insert(candidate);
                    }
                }
            }
        }

        return 0;
    }
};

/*int main() {
    Solution solution = Solution();
    vector<string> v;
    v.push_back("hot");
    v.push_back("dot");
    v.push_back("dog");
    v.push_back("lot");
    v.push_back("log");
    v.push_back("cog");
    int a = solution.ladderLength("hit", "cog", v);
    cout << a;
}*/

