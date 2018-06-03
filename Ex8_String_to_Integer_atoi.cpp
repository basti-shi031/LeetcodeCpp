#include<iostream>
#include<vector>
using namespace std;
//finished
class Solution {
public:
    bool isPalindrome(int x) {
		if (x<0)
		{
			return false;
		}
		long long x_l = x;
		vector<int> nums;
		long long result = 0;

		while (x !=0)
		{
			int a = x % 10;
			x = x / 10;
			nums.push_back(a);
		}

		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			result = result * 10 + nums[i];
		}

		return result == x_l;
	}
};

int main()
{
	int nums;
	cin >> nums;
	Solution so = Solution();
	bool result = so.isPalindrome(nums);
	cout << result;
	system("pause");
}