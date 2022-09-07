#include <iostream>
#include <cmath>

using namespace std;

int n;
int* p;

int getCycles();

int main() 
{
	cin >> n;
	p = new int[n];

	for (int i = 0; i < n; i++)
		cin >> p[i];

	cout << getCycles();

}

int getCycles() 
{
	int result = 1;
	bool* check = new bool[n];

	for (int i = 0; i < n; i++)
		check[i] = false;

	check[0] = true;
	int count = 1;
	int traking = 0;
	while (count < n)
	{
		traking = p[traking];
		if (check[traking] == true)
		{
			result++;
			for(int i = 0; i < n; i++)
				if (!check[i])
				{
					count++;
					traking = i;
					check[i] = true;
					break;
				}
		}
		else
		{
			count++;
			check[traking] = true;
		}
	}

	return result > 1 ? result : 0;

}