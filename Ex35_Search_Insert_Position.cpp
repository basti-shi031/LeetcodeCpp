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

int main()
{
	vector<int> v;
	while (true)
	{
		int a;
		cin >> a;
		if (a == 10)
		{
			break;
		}
		v.push_back(a);
	}
	int target;
	cin >> target;
	Solution so = Solution();
	cout<<so.searchInsert(v,target);
	system("pause");
}
