#include<iostream>
using namespace std;
//finished
class Solution {
public:
	long long abs2(long long  dividend)
	{
		return dividend >= 0 ? dividend : -dividend;

	}
	int divide(int dividend, int divisor) {
		long long tempdvidend = dividend;
		long long tempdvisor = divisor;
		long long  a = abs2(dividend);
		long long  b = abs2(divisor);

		long long  result = 0;
		if (a == 0 || a < b)
		{
			return 0;
		}
		if (b ==1)
		{
			result = a;
		}

		while (a >= b&&b!=1)
		{
			a = a - b;
			result++;
		}


		if ((tempdvidend > 0 && tempdvisor < 0) || (tempdvidend < 0 && tempdvisor>0))
		{
			result = -result;
		}
		
		if (result>INT32_MAX||result<INT32_MIN)
		{
			return INT32_MAX;
		}
		else
		{
			return result;
		}
	}
};

//int main()
//{
//	Solution so = Solution();
//	cout<<so.divide(1, 1);
//	system("pause");
//}