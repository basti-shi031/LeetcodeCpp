#include<iostream>
#include<string>
#include<vector>

using namespace std;
//finished
class Solution {
public:
	vector<string> nums;

	string convert(string num)
	{
		int preIndex = 0;
		int lastIndex = 1;
		string result = "";
		while (preIndex<num.length())
		{

			if (lastIndex>=num.length())
			{
				//不同的情况
				int count = lastIndex - preIndex;
				//一共count个num[preIndex]
				char c = num[preIndex];
				result = result + to_string(count) + c;
				return result;
			}
			if (num[preIndex] == num[lastIndex])
			{
				lastIndex++;
			}
			else
			{
				//不同的情况
				int count = lastIndex - preIndex;
				//一共count个num[preIndex]
				char c = num[preIndex];
				result = result + to_string(count) + c;
				preIndex = lastIndex;
			}
		}
		return result;
	}

	string countAndSay(int n) {
		nums.push_back("1");
		nums.push_back("11");

		if (n<=2)
		{
			return nums[n-1];
		}

		for (int i = 2; i < n; i++)
		{
			string num = convert(nums[i - 1]);
			nums.push_back(num);
		}
		return nums[n-1];
	}
};

//int main()
//{
//	int n;
//	cin >> n;
//	Solution so = Solution();
//	cout << so.countAndSay(n);
//	system("pause");
//}