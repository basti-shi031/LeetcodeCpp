#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	//  I             1
	//  IV			  4
	//	V             5
	//  IX			  9
	//	X             10
	//  XL			  40
	//	L             50
	//  XC			  90
	//	C             100
	//  CD			  400
	//	D             500
	//  CM			  900
	//	M             1000
	map<int, string> maps;
	vector<int> divides;
	string intToRoman(int num) {
		maps.insert(pair<int, string>(1, "I"));
		maps.insert(pair<int, string>(4, "IV"));
		maps.insert(pair<int, string>(5, "V"));
		maps.insert(pair<int, string>(9, "IX"));
		maps.insert(pair<int, string>(10, "X"));
		maps.insert(pair<int, string>(40, "XL"));
		maps.insert(pair<int, string>(50, "L"));
		maps.insert(pair<int, string>(90, "XC"));
		maps.insert(pair<int, string>(100, "C"));
		maps.insert(pair<int, string>(400, "CD"));
		maps.insert(pair<int, string>(500, "D"));
		maps.insert(pair<int, string>(900, "CM"));
		maps.insert(pair<int, string>(1000, "M"));

		divides.push_back(1);
		divides.push_back(4);
		divides.push_back(5);
		divides.push_back(9);
		divides.push_back(10);
		divides.push_back(40);
		divides.push_back(50);
		divides.push_back(90);
		divides.push_back(100);
		divides.push_back(400);
		divides.push_back(500);
		divides.push_back(900);
		divides.push_back(1000);

		string result = "";
		int i = maps.size()-1;
		while (num >0)
		{
			int d = divides[i];
			int count = num / d;
			num = num % d;
			string temp = maps[d];

			for (int index = 0; index < count; index++)
			{
				result += temp;
			}
			i--;
		}
		return result;
	}
};