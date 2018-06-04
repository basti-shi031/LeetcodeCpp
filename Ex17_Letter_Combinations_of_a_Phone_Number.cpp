#include<vector>
#include<string>
#include<iostream>
using namespace std;


//finished
class Solution {
public:

	void combine(vector<string>& result, string add)
	{
		int resultSize = result.size();
		int addSize = add.length();
		for (int i = 0; i < resultSize; i++)
		{
			string temp = result[i];
			for (int j = 0; j < addSize; j++)
			{
				result.push_back(temp + add[j]);
			}
		}
		vector<string>::iterator begin = result.begin();
		result.erase(begin, begin+resultSize);
	}

	string a[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.length() == 0)
		{
			return result;
		}
		string temp = a[digits[0] - '0'];
		for (char c : temp)
		{
			string s(1, c);
			result.push_back(s);
		}
		if (digits.length() == 1)
		{
			return result;
		}

		int index = 1;

		for (index = 1; index < digits.length(); index++)
		{
			combine(result, a[digits[index] - '0']);
		}

		return result;

	}
};


//int main()
//{
//	Solution so = Solution();
//	string s;
//	cin >> s;
//	vector<string> result = so.letterCombinations(s);
//	for (string s:result)
//	{
//		cout << s << endl;
//	}
//	system("pause");
//}