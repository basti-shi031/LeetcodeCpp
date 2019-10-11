//
// Created by Basti031 on 2019/9/17.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if (prices.size() <= 1) {
            return 0;
        }


        int size = prices.size();

        int min = INT_MAX;
        int max_profit = -1;

        for (int i = 0; i < size; ++i) {
            int a = prices[i];
            if (a < min) {
                min = a;
            }
            int profit = a - min;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};

/*
int main(){
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    Solution solution = Solution();
    cout<<solution.maxProfit(prices);
}*/
