#include<iostream>
#include<vector>

using namespace std;

//finished
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int length = nums.size();
		if (length == 0)
		{
			return 0;
		}

		int low = 0;
		int high = nums.size() - 1;
		int mid;
		int flag = 0;
		while(low <= high)
		{
			mid = (low + high) / 2;
			int a = nums[mid];
			if (a == target)
			{
				flag = 0;
				return mid;
			}
			if (a>target)
			{
				flag = -1;
				high = mid - 1;
			}
			else
			{
				flag = 1;
				low = mid + 1;
			}
		}
		return flag == -1?mid:mid+1;
	}
};