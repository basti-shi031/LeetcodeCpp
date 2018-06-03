#include<iostream>
#include<string>

using namespace std;

//finished
class Solution {
public:
	string convert(string s, int numRows) {
		string result = "";
		int length = s.length();
		if (length == 1 || numRows==1)
		{
			return s;
		}
		for (int i = 0; i < numRows; i++)
		{
			bool pre = true;
			int index = i;
			while (index < length)
			{
				result = result + s[index];
				int divider = 0;
				if (pre)
				{
					divider = 2 * numRows - 2 * (i + 1);
				}
				else
				{
					divider = 2 * i;
				}
				pre = !pre;
				if (divider == 0)
				{
					//第0行和最后一行会出现
					divider = 2 * numRows - 2;
				}
				index = index + divider;
			}
		}

		return result;
	}

};

//int main()
//{
//string s;
//int nums;
//cin >> s;
//cin >> nums;
//Solution so = Solution();
//string result = so.convert(s,nums);
//cout << result;
//system("pause");
//}