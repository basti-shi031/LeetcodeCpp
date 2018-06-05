#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//finished
class Solution {
public:

	vector<vector<int>> twoSum(vector<int> nums, int low, int high, int first)
	{
		vector<vector<int>> result;
		int target = -first;
		while (low < high)
		{
			int a = nums[low];
			int b = nums[high];
			int sum = a + b;
			if (sum > target)
			{
				high--;
			}
			else if (sum < target)
			{
				low++;
			}
			else
			{
				vector<int> twoV;
				twoV.push_back(first);
				twoV.push_back(a);
				twoV.push_back(b);
				result.push_back(twoV);
				while (low < high&&nums[low] == nums[low++])
				{
					low++;
				}
			}
		}

		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			int first = nums[i];
			if (i != 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			if (first > 0)
			{
				return result;
			}
			vector<vector<int>> two = twoSum(nums, i + 1, size - 1, first);
			for (vector<int> v : two)
			{
				result.push_back(v);
			}
		}

		return result;
	}
};

//int main()
//{
//	vector<int> nums;
//	while (true)
//	{
//		int a;
//		cin >> a;
//		if (a == 10)
//		{
//			break;
//		}
//		nums.push_back(a);
//	}
//
//	Solution so = Solution();
//	vector<vector<int>> result = so.threeSum(nums);
//
//	for (vector<int> v : result)
//	{
//		for (int a : v)
//		{
//			cout << a << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//}