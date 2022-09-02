#include <iostream>
#include <string>
using namespace std;

int** prices;
int*** Depths;

bool* buy;
int n;

int traking(int buyer, int price);

int main() 
{
	cin >> n;
	buy = new bool[n];
	for (int i = 1; i < n; i++)
		buy[i] = false;

	Depths = new int**[n];


	for(int k = 0; k<n;k++)
	{		
		Depths[k] = new int*[10];
		for (int i = 0; i < 10; i++)
		{
			Depths[k][i] = new int[20000];
			for (int j = 0; j < 20000; j++)
				Depths[k][i][j] = -1;
		}
	}

	prices = new int* [n];
	for (int i = 0; i < n; i++)
		prices[i] = new int[n];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char tmp;
			cin >> tmp;
			prices[i][j] = tmp - '0';
		}

	buy[0] = true;

	cout << traking(0,0) + 1;

}

int traking(int buyer,int price)
{
	string s = "";
	for (int i = 1; i < n; i++)
		s += buy[i] ? "1" : "0";

	int key = stoi(s, nullptr, 2);

	if (Depths[buyer][price][key] != -1)
	{
		buy[buyer] = false;
		return Depths[buyer][price][key];
	}
	else
	{
		int nowDepth = 0;
		for(int i = 1; i< n; i++)
			if (!buy[i] && prices[buyer][i] >= price)
			{
				buy[i] = true;
				int tmpDepth = traking(i, prices[buyer][i]) + 1;
				nowDepth = nowDepth > tmpDepth ? nowDepth : tmpDepth;
			}

		Depths[buyer][price][key] = nowDepth;
		buy[buyer] = false;
		return nowDepth;
	}
}
