#include <iostream>

using namespace std;

int n, k;
int* e;
int* re;

int getMaxE(int*);

int main() 
{
	
	cin >> n >> k;
	e = new int[n];
	re = new int[n];
	for (int i = 0; i < n; i++)
		cin >> e[i];

	int result = getMaxE(e);

	for (int i = 0; i < n; i++)
		re[i] = e[n - i - 1];

	int result2 = getMaxE(re);

	cout << (result > result2 ? result : result2);


}

int getMaxE(int* energy) 
{
	int maxI = -2147483648;
	int result = -2147483648;
	

	for (int j = 1; j < n; j++)
	{
		int nowI = (energy[j - 1] + (j - 1) * k);
		maxI =  nowI > maxI ? nowI : maxI;
		int nowj = maxI - energy[j] - j * k;
		result = nowj > result ? nowj : result;
	}

	return result;
}
