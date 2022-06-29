#include <iostream>
using namespace std;

void calRatios();
int gcd(int a, int b);

int n;
int** inp;
int* ratios;
int* isCheck; // 0 nocheck, -1 checked, -2 check

int main() 
{
	cin >> n;
	ratios = new int[n];
	isCheck = new int[n];
	inp = new int*[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			int* tmp = new int[4];
			for (int j = 0; j < 4; j++)
				cin >> tmp[j];
			inp[i] = tmp;
		}
		isCheck[i] = 0;
		ratios[i] = 0;
	}

	calRatios();

	for (int i = 0; i < n; i++)
		cout << ratios[i] << " ";

}

void calRatios() 
{
	if (n == 1)
	{
		ratios[0] = 1;
		return;
	}

	isCheck[0] = -1;
	ratios[inp[0][0]] = inp[0][2];
	ratios[inp[0][1]] = inp[0][3];
	int count = 1;

	while (count < n-1)
	{
		int i;
		for (i = 0; i < n-1; i++)
			if (isCheck[i] == -1)
				break;

		isCheck[i] = -2;

		for (int j = 0; j < n-1; j++)
		{
			if (isCheck[j] == 0)
			{
				if (inp[j][0] == inp[i][0])
				{
					int t = ratios[inp[i][0]] * inp[j][3];
					for (int k = 0; k < n; k++)
						ratios[k] *= inp[j][2];
					ratios[inp[j][1]] = t;
					isCheck[j] = -1;
					count++;
				}
				else if (inp[j][1] == inp[i][0])
				{
					int t = ratios[inp[i][0]] * inp[j][2];
					for (int k = 0; k < n; k++)
						ratios[k] *= inp[j][3];
					ratios[inp[j][0]] = t;
					isCheck[j] = -1;
					count++;
				}
				else if (inp[j][0] == inp[i][1])
				{
					int t = ratios[inp[i][1]] * inp[j][3];
					for (int k = 0; k < n; k++)
						ratios[k] *= inp[j][2];
					ratios[inp[j][1]] = t;
					isCheck[j] = -1;
					count++;
				}
				else if (inp[j][1] == inp[i][1])
				{
					int t = ratios[inp[i][1]] * inp[j][2];
					for (int k = 0; k < n; k++)
						ratios[k] *= inp[j][3];
					ratios[inp[j][0]] = t;
					isCheck[j] = -1;
					count++;
				}


			}

		}

	}

	int allGcd = gcd(ratios[0],ratios[1]);
	for (int i = 2; i < n; i++)
		allGcd = gcd(allGcd, ratios[i]);

	for (int k = 0; k < n; k++)
		ratios[k] /= allGcd;


}



int gcd(int a, int b) 
{
	int tmp = a % b;
	while (tmp != 0)
	{
		a = b;
		b = tmp;
		tmp = a % b;
	}
	return b;
}