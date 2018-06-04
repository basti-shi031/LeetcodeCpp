#include<iostream>
#include<vector>
using namespace std;

//finished
class Solution {
public:

	int min(int a, int b) {
		return a < b ? a : b;
	}

	int max(int a, int b) {
		return a > b ? a : b;
	}
	int maxArea(vector<int>& height) {
		int size = height.size();
		int preIndex = 0;
		int lastIndex = size - 1;
		int maxArea = 0;
		while (preIndex <= lastIndex)
		{
			int area = (lastIndex - preIndex) * min(height[preIndex], height[lastIndex]);
			maxArea = max(area, maxArea);
			height[preIndex] < height[lastIndex] ? preIndex++ : lastIndex--;
		}

		return maxArea;
	}
};