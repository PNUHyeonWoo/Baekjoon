#include <iostream>

using namespace std;

int n, m;
int** pool;
int** isChecked;
int result = 0;


void getWater();
int dfs(int** isChecked, int i, int j, int base);

int main() 
{
	cin >> n >> m;
	pool = new int* [n];
	isChecked = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		pool[i] = new int[m];
		isChecked[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			char tmp;
			cin >> tmp;
			pool[i][j] = tmp - '0';
			isChecked[i][j] = 0;
		}
	}

	getWater();
	cout << result;

}

void getWater() 
{  
	for (int check = 8; check > 0; check--)
	{
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (pool[i][j] != check)
					continue;

				for (int a = 0; a < n; a++)
					for (int b = 0; b < m; b++)
						isChecked[a][b] = 0;
						
				try 
				{
					int water = dfs(isChecked, i, j, check) - check;
					result += water;
					pool[i][j] += water;
				}
				catch(int a)
				{
					continue;
				}


			}
	}
}

int dfs(int** isChecked,int i,int j,int base)
{
	if (isChecked[i][j] == 1)
		return 10;
	if (pool[i][j] > base)
		return pool[i][j];

	if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
		throw 0;

	int nowR[4] = {0,0,0,0};
	isChecked[i][j] = 1;

	nowR[0] = dfs(isChecked, i+1, j, base);
	nowR[1] = dfs(isChecked, i-1, j, base);
	nowR[2] = dfs(isChecked, i, j+1, base);
	nowR[3] = dfs(isChecked, i, j-1, base);

	int min = 10;
	for (int k = 0; k < 4; k++)
		min = min < nowR[k] ? min : nowR[k];

	return min;

}