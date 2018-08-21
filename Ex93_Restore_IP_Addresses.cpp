//
// Created by Basti031 on 2018/8/21.
//
#include <vector>
#include <iostream>
#include <string>
#include<stack>

using namespace std;

class Solution {
public:

    void dfs(string s, int start, int step, string ip, vector<string>& result) {

        if (ip=="255.255.111."){
            int a = 1;
        }
        if(start==s.size()&&step==4){
            ip.erase(ip.end()-1); //remove the last '.' from the last decimal number
            result.push_back(ip);
            return;
        }
        if(s.size()-start>(4-step)*3) return;
        if(s.size()-start<(4-step)) return;

        int num=0;
        for(int i=start;i<start+3;i++){
            num=num*10+(s[i]-'0');
            if(num<=255){
                ip+=s[i];
                dfs(s,i+1,step+1,ip+'.',result);
            }
            if(num==0) break;
        }
    }

    vector<string> restoreIpAddresses(string s) {

        string ip;
        vector<string> result;
        dfs(s, 0, 0, ip, result);
        return result;
    }
};

int main(){
    Solution solution = Solution();
    vector<string> v = solution.restoreIpAddresses("25525511135");
    cout<<v.size();
}