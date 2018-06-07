#include<iostream>
#include<vector>
using namespace std;

//finished
class Solution {
public:
	int bSearch(vector<int> nums, int target)
	{
		int low = 0;
		int high = nums.size()-1;

		while (low<=high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				high = mid-1;
			}
			else {
				low = mid+1;
			}
		}
		return -1;
	}

	int findStart(vector<int> nums, int target, int index)
	{
		for (int i = index; i >=0 ; i--)
		{
			if (nums[i] != target)
			{
				return i + 1;
			}
		}
		return 0;
	}

	int findEnd(vector<int> nums, int target, int index)
	{
		int size = nums.size();
		for (int i = index; i < size; i++)
		{
			if (nums[i] != target)
			{
				return i - 1;
			}
		}
		return size-1;
	}

	vector<int> searchRange(vector<int>& nums, int target) {

		int index = bSearch(nums, target);
		vector<int> result;
		if (index == -1)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		int start = findStart(nums, target,index);
		int end = findEnd(nums, target, index);
		result.push_back(start);
		result.push_back(end);

		return result;
	}
};

//int main()
//{
//	vector<int> v;
//	v.push_back(5);
//	v.push_back(5);
//	v.push_back(7);
//	v.push_back(8);
//	v.push_back(8);
//	v.push_back(10);
//	Solution so = Solution();
//	vector<int> result = so.searchRange(v, 6);
//	for (int a:result)
//	{
//		cout << a << endl;
//	}
//	system("pause");
//}