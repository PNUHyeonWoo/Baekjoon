#include <iostream>
#include <queue>
using namespace std;

int peopleCount;
int partyCount;
int* know;
int** partys;
queue<int> listners;

int check();

int main() 
{
	cin >> peopleCount >> partyCount;
	know = new int[peopleCount + 1];
	for (int i = 1; i <= peopleCount; i++)
		know[i] = 0;

	int liC = 0;
	cin >> liC;
	for (int i = 0; i < liC; i++)
	{
		int tmp;
		cin >> tmp;
		listners.push(tmp);
	}

	partys = new int*[partyCount];

	for (int i = 0; i < partyCount; i++)
	{
		int tmp;
		cin >> tmp;
		partys[i] = new int[tmp + 1];
		partys[i][0] = tmp;
		for (int j = 1; j <= tmp; j++) 
		{
			int ttmp;
			cin >> ttmp;
			partys[i][j] = ttmp;
		}
	}

	cout << check();


}

int check() 
{
	while (!listners.empty())
	{
		int nowCheck = listners.front();
		listners.pop();
		for (int i = 0; i < partyCount; i++)
		{
			if (partys[i][0] != -1)
			{
				bool isIn = false;
				for (int j = 1; j <= partys[i][0]; j++)
				{
					if (partys[i][j] == nowCheck)
					{
						isIn = true;
						break;
					}
				}

				if (isIn)
				{
					for (int j = 1; j <= partys[i][0]; j++)
					{
						if (know[partys[i][j]] == 0)
						{
							listners.push(partys[i][j]);
							know[partys[i][j]] = 1;
						}
					}

					partys[i][0] = -1;
				}


			}
		}


	}

	int result = 0;
	for (int i = 0; i < partyCount; i++)
		if (partys[i][0] != -1)
			result++;

	return result;
}