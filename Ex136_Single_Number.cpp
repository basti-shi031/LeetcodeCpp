#include<iostream>
#include<set>
#include<vector>

using namespace std;
//finished
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		set<int> sets;
		int allSum = 0,setSum = 0;

		for (int a : nums)
		{
			allSum += a;
			if (sets.count(a) == 0)
			{
				setSum += a;
				sets.insert(a);
			}
		}
		return 2 * setSum - allSum;

	}
};