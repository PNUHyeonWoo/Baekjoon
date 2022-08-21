#include <iostream>
using namespace std;

int* height;
int* seeCount;
int n;

int FindBest();
bool checkBuilding(int low, int high);

int main() 
{
	cin >> n;
	height = new int[n];
	seeCount = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> height[i];
		seeCount[i] = 0;
	}

	cout << FindBest();
}

int FindBest() 
{
	for(int i = 0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			if (checkBuilding(i, j))
			{
				seeCount[i]++;
				seeCount[j]++;
			}
		}

	int max = 0;
	for (int i = 0; i < n; i++)
		max = max < seeCount[i] ? seeCount[i] : max;

	return max;
}


bool checkBuilding(int low, int high) 
{
	double d = (double)(height[high] - height[low]) / (double)(high - low);

	for (int i = low + 1; i < high; i++)
		if (height[i] >= height[low] + d * (i - low))
			return false;

	return true;
}