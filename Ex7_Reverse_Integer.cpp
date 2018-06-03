#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;

//finished
class Solution {
public:
	int reverse(int x) {
		if (x == 0)
		{
			return 0;
		}

		if (x>= INT32_MAX||x<=-INT32_MAX)
		{
			return 0;
		}
		long long result = 0;
		vector<int> nums;
		bool positive = x > 0;
		long long  x1 = abs(x);

		while (x1 != 0)
		{
			int a = x1 % 10;
			x1 = x1 / 10;
			nums.push_back(a);
		}

		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			result = result * 10 + nums[i];
		}

		if (result >= INT32_MAX)
		{
			return 0;
		}
		else
		{
			return positive ? result : -result;
		}


	}
};

//int main()
//{
//int nums;
//cin >> nums;
//Solution so = Solution();
//int result = so.reverse(nums);
//cout << result;
//system("pause");
//}