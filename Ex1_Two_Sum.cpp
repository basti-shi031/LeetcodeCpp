#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//finished
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		map<int, int> maps;
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			maps.insert(make_pair(nums[i], i));
		}
		for (int i = 0; i < size; i++)
		{
			int remain = target - nums[i];
			if (maps.count(remain) == 1 && maps[remain] != i)
			{
				result.push_back(i);
				result.push_back( maps[remain]);
				return result;
			}
		}
	}
};