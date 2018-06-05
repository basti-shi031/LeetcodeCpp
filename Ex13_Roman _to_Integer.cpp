#include<iostream>
#include<string>
#include<map>
using namespace std;

//finished
class Solution {
public:
	map<char, int> maps;
	bool near(char c, string s, int index)
	{
		if (index == s.length()-1)
		{
			return false;
		}
		int div = maps[s[index + 1]] - maps[c];
		return div == 4 || div == 9 || div == 90 || div == 40 || div == 400 || div == 900;

	}
	//Symbol       Value
	//	I             1
	//	V             5
	//	X             10
	//	L             50
	//	C             100
	//	D             500
	//	M             1000

	//I can be placed before V(5) and X(10) to make 4 and 9.
	//X can be placed before L(50) and C(100) to make 40 and 90.
	//C can be placed before D(500) and M(1000) to make 400 and 900.
	int romanToInt(string s) {

		maps.insert(pair<char, int>('I', 1));
		maps.insert(pair<char, int>('V', 5));
		maps.insert(pair<char, int>('X', 10));
		maps.insert(pair<char, int>('L', 50));
		maps.insert(pair<char, int>('C', 100));
		maps.insert(pair<char, int>('D', 500));
		maps.insert(pair<char, int>('M', 1000));
		int result = 0;

		int size = s.length();
		for (int i = 0; i < size; i++)
		{
			char c = s[i];
			int num = maps[c];
			if (near(c,s,i))
			{
				num = -num;
			}

			result += num;
		}

		return result;
	}


};

//int main()
//{
//	string s;
//	cin >> s;
//	Solution so = Solution();
//	cout << so.romanToInt(s);
//
//	system("pause");
//}