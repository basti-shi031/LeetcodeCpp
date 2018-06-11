#include<iostream>
#include<string>
#include<vector>
using namespace std;

//finished
class Solution {
public:
	vector<string> nums;
	string multiply(string num1, char c)
	{
		if (c == '0')
		{
			return "0";
		}

		int size = num1.size();
		string result = "";
		int flag = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			int mul = (num1[i] - '0')*(c - '0') + flag;
			result = to_string(mul % 10) + result;
			flag = mul / 10;
		}
		if (flag>=1)
		{
			result = to_string(flag) + result;
		}

		return result;


	}

	string add(string a, string b)
	{
		if (a.length() < b.length())
		{
			swap(a, b);
		}
		//确保a比长
		string sum = "";
		int flag = 0;
		int aSize = a.length();
		int bSize = b.length();
		for (int ai = aSize - 1, bi = bSize - 1; ai >= 0; ai--, bi--)
		{
			int an = a[ai] - '0';
			int bn = bi < 0 ? 0 : b[bi] - '0';

			int s = an + bn + flag;
			flag = s / 10;
			sum = to_string(s % 10) + sum;
		}

		if (flag>=1)
		{
			sum = to_string(flag) + sum;
		}

		return sum;
	}

	string multiply(string num1, string num2) 
	{
		if (num1[0] == '0' || num2[0] == '0')
		{
			return "0";
		}

		int size = num2.size();
		string sum = "";
		for (int i = size - 1; i >= 0; i--)
		{
			string result = multiply(num1, num2[i]);
			//补零
			for (int j = 0; j < size-1-i; j++)
			{
				result += "0";
			}
			sum = add(sum, result);
		}
		return sum;
	}
};
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//	Solution so = Solution();
//	cout << so.multiply(a, b);
//	system("pause");
//}