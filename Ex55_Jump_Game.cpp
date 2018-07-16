//
// Created by Basti031 on 2018/7/14.
//

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//finished
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int size = nums.size();
        if (size == 1){
            return true;
        }

        vector<int> targetIndexs;
        targetIndexs.push_back(size - 1);
        while (true) {
            int targetSize = targetIndexs.size();
            if (targetSize == 0){
                return false;
            }
            for (int index = 0; index < targetSize; index++) {
                int targetIndex = targetIndexs[index];
                for (int i = 0; i < targetIndex; ++i) {
                    if (i + nums[i] >= targetIndex) {
                        if(find(targetIndexs.begin()+targetSize,targetIndexs.end(),i)==targetIndexs.end()) {
                            targetIndexs.push_back(i);
                        }
                        if (i == 0) {
                            return true;
                        }
                    }
                }
            }
            targetIndexs.erase(targetIndexs.begin(), targetIndexs.begin() + targetSize);

        }
    }
};

/*int main(){
    vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(1);
    vector1.push_back(2);
    vector1.push_back(2);
    vector1.push_back(0);
    Solution solution = Solution();
    cout << solution.canJump(vector1);

}*/
