//
// Created by Basti031 on 2018/8/23.
//
#include <stack>
#include<vector>
#include <iostream>
#include<string>

using namespace std;

class Solution {

    bool visited[][];//先定义一个global布尔类型的2D数组，用来标记访问过的char
public:
    bool exist(vector<vector<char>> &board, string word) {
        visited = new boolean[board.length][board[0].length];//初始化visited，默认都是0 or false
        for (int i = 0; i < board.length; i++) {//遍历char数组,以里面每一个board[i][j]作为dfs的起始点
            for (int j = 0; j < board[0].length; j++) {
                if (word.charAt(0) == board[i][j] &&
                    dfs(board, word, i, j, 0))//如果数组里能匹配word的第一个字母 &&能匹配剩下的？index=0 to start
                    return true;//上面的index，作为dfs的一个input去递增访问上下左右4个方向
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index) {
        if (index == word.length())//定义一下dfs函数的true返回条件，就是这个index长度和word一样
            return true;
        //返回false的条件： i和j越界（upper and lower bound）或和单词里面的不符，或者已经visit，那个sub-dfs就stop！返回false
        if (i >= board.length || i < 0 || j >= board[i].length || j < 0 || board[i][j] != word.charAt(index) ||
            visited[i][j])
            return false;
        visited[i][j] = true;//每访问一个新的[i][j]，先标记为true（以便上面返回的不是false...保证dfs进行下去）
        if (dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i, j - 1, index + 1) ||
            dfs(board, word, i, j + 1, index + 1))//每多比较一个word的字符，就在这个char的上下左右四个方向进行dfs
            return true;//最上面那个for loop里调用函数的返回
        visited[i][j] = false;//dfs完了，再进行到下一个[i][j]的时候要把它改回false，因为下一个[i][j]的dfs依然要访问它。
        return false;//没找到？for loop里[i][j]点不返回true，继续找。。。。
    }
};