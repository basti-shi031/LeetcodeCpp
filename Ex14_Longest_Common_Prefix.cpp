#include<iostream>
#include<vector>
#include<string>

using namespace std;
//finished
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int index = 0;
		string result = "";
		if (strs.size() == 0)
		{
			return "";
		}
		if (strs.size() == 1)
		{
			return strs[0];
		}
		for (char c : strs[0])
		{
			for (int i = 1; i < strs.size(); i++)
			{
				//如果当前比较的字符index已经越界或者不同，退出循环，返回当前结果
				if (index >=strs[i].length()||strs[i][index] != c)
				{
					return result;
				}
			}
			index++;
			result += c;
		}

		return result;

	}
};

//int main()
//{
//	vector<string> strs;
//	while (true)
//	{
//		string s;
//		cin >> s;
//		if (s == "1") break;
//		strs.push_back(s);
//	}
//	Solution so = Solution();
//	string result = so.longestCommonPrefix(strs);
//	cout << result;
//	system("pause");
//}