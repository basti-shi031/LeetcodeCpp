//
// Created by Basti031 on 2019/12/18.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<1){
            return false;
        }

        if (n == 1) {
            return true;
        }

        if (n % 2 == 1) {
            return false;
        }
        return isPowerOfTwo(n / 2);
    }
};