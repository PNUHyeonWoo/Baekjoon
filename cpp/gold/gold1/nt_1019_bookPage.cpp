#include <iostream>

using namespace std;

int main() 
{
	long long* result = new long long[10];
	for (int i = 0; i < 10; i++)
		result[i] = 0;
	long long inp;
	cin >> inp;
	long long now = inp;
	long long degree = 1;
	while (now > 0)
	{
		long long tmp = now / 10;
		for (int i = 0; i < 10; i++)
			result[i] += tmp * degree;
		result[0] -= degree;
		tmp = inp % (degree * 10);
		int max = tmp / degree;
		for (int i = 0; i < max; i++)
			result[i] += degree;
		result[max] += (tmp % degree)+1;

		degree *= 10;
		now /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << result[i] << " ";

}