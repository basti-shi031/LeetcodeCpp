#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct Node 
{
	string key;
	string sortKey;
};

//finished
class Solution {
public:
	string convert(string s)
	{
		string temp = s;
		
		sort(temp.begin(),temp.end());
		return temp;
	}

	map<string, vector<string>> keys;
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		for (string s:strs)
		{
			string key = convert(s);
			if (keys.count(key) == 0)
			{
				vector<string> v;
				v.push_back(s);
				keys.insert(pair<string,vector<string>>(key,v));
			}
			else
			{
				keys[key].push_back(s);
			}
		}

		//±éÀú
		map<string, vector<string>> ::iterator it;
		it = keys.begin();
		vector<vector<string>> result;
		while (it!=keys.end())
		{
			result.push_back(it->second);
			it++;
		}
		return result;
	}
};
