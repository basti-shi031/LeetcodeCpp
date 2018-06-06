#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
		{
			return 0;
		}

		int long_index = 0;
		int long_length = haystack.length();
		int short_length = needle.length();
		if (long_length<short_length)
		{
			return -1;
		}
		for (long_index = 0; long_index <= long_length-short_length; long_index++)
		{
			int long_temp_index = long_index;
			for (int shortIndex = 0; shortIndex < short_length; shortIndex++)
			{
				if (haystack[long_temp_index] != needle[shortIndex])
				{
					break;
					
				}
				long_temp_index++;
				if (shortIndex == short_length-1)
				{
					return long_index;
				}
			}
		}

		return -1;
	}
};

int main() 
{
	string longS, shortS;
	cin >> longS>>shortS;
	Solution so = Solution();

	cout << so.strStr(longS, shortS);
	system("pause");
}