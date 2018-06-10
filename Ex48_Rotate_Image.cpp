#include<iostream>
#include<vector>
using namespace std;

//finished
class Solution {
public:

	int swapPixels(vector<vector<int>>& matrix, int& x, int& y,int next)
	{
		//首先获取下一个地址
		int x1 = y;
		int y1 = matrix.size() - 1 - x;
		int value = matrix[x1][y1];

		matrix[x1][y1] = next;
		x = x1;
		y = y1;
		return value;

	}

	void rotate(vector<vector<int>>& matrix, int i)
	{
		int size = matrix.size();
		for (int index = i; index < size - i - 1; index++)
		{
			int x = i;
			int y = index;
			int next = matrix[x][y];
			//依次交换坐标为[i,index]的坐标
			for (int j = 0; j < 4; j++)
			{

				next = swapPixels(matrix, x, y, next);
			}
		}
	}

	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		int count = (size - 1) / 2;
		if (size % 2 == 1) count--;

		for (int i = 0; i <= count; i++)
		{
			rotate(matrix, i);
		}

	}
};

//int main()
//{
//	vector<vector<int>> a;
//	int size = 4;
//	int num = 1;
//	for (size_t i = 0; i < size; i++)
//	{
//		vector<int> v;
//		for (size_t j = 0; j < size; j++)
//		{
//			v.push_back(num);
//			num++;
//		}
//		a.push_back(v);
//	}
//
//
//	Solution so = Solution();
//	so.rotate(a);
//
//	for (vector<int> v : a)
//	{
//		for (int num : v)
//		{
//			cout << num << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}