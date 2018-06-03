#include<iostream>
#include<string>

using namespace std;
/*
i表示从第i开始，j表示到第j个结束，所有的index都从0开始
dp[i][j] Si-Sj是否是回文
dp[i][j] = {dp[i+1][j-1] && si==sj}
*/
//finished
class Solution {
	bool dp[1001][1001];
public:
	void init(int size) {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <= size; j++)
			{
				dp[i][j] = false;
			}
		}

		for (int i = 0; i < size; i++)
		{
			dp[i][i] = true;
			if (i >= 1)
			{
				dp[i][i - 1] = true;
			}
		}




	}

	string longestPalindrome(string s) {
		int size = s.length();
		if (size == 1)
		{
			return s;
		}

		init(size);
		int start = 1;
		int i = 0;
		int max = 0;
		int maxI = 0;
		int maxJ = 0;
		while (true)
		{
			for (int j = start; j < size; j++)
			{
				dp[i][j] = dp[i + 1][j - 1] && (s.at(i)==s.at(j));
				if (dp[i][j])
				{
					int size = j - i + 1;
					if (size>max&&i<maxI){}
					{
						maxJ = j;
						maxI = i;
						max = size;
					}
				}
				i++;
			}
			i = 0;
			start++;
			if (start==size)
			{
				break;
			}
		}
		return s.substr(maxI,maxJ-maxI+1);
	}
};

/*
int main() 
{
	string s;
	cin >> s;
	Solution so = Solution();
	string result = so.longestPalindrome(s);
	cout << result;
	system("pause");
}*/