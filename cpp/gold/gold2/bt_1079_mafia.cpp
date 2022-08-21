#include <iostream>

using namespace std;

void kill(int date);

bool isFinish = false;

int** doubtChanges;

bool** life;
int** doubt;

int maxDate;
int numPeople;
int myIndex;

int result = 0;

int main() 
{
	cin >> numPeople;
	if (numPeople == 1)
	{
		cin >> numPeople;
		cin >> numPeople;
		cin >> numPeople;
		cout << 0;
		return 0;
	}

	maxDate = numPeople / 2 - 1;

	life = new bool* [maxDate + 1];
	doubt = new int* [maxDate + 1];
	doubtChanges = new int* [numPeople];

	for (int i = 0; i < maxDate + 1; i++)
	{
		life[i] = new bool[numPeople];
		doubt[i] = new int[numPeople];
	}

	for (int i = 0; i < numPeople; i++)
	{
		life[0][i] = true;
		cin >> doubt[0][i];
		doubtChanges[i] = new int[numPeople];
	}

	for (int i = 0; i < numPeople; i++)
		for (int j = 0; j < numPeople; j++)
			cin >> doubtChanges[i][j];

	cin >> myIndex;

	int max = doubt[0][0];
	int maxIndex = 0;

	for (int j = 1; j < numPeople; j++)
		if (max < doubt[0][j])
		{
			max = doubt[0][j];
			maxIndex = j;
		}

	if (numPeople % 2 == 1)
	{
		if (maxIndex == myIndex)
			cout << 0;
		else
		{
			life[0][maxIndex] = false;
			kill(0);
			cout << result;
		}	
	}
	else
	{
		kill(0);
		cout << result;
	}
}

void kill(int date)
{
	result = result < date + 1 ? date + 1 : result;
	if (date == maxDate)
	{
		isFinish = true;
		return;
	}

	for (int i = 0; i < numPeople; i++)
		if (life[date][i] && i != myIndex)
		{
			for (int j = 0; j < numPeople; j++)
				doubt[date + 1][j] = doubt[date][j] + doubtChanges[i][j];

			int max = - 2147483647;
			int maxIndex = -1;

			for (int j = 0; j < numPeople; j++)
				if (max < doubt[date + 1][j] && life[date][j] && j != i)
				{
					max = doubt[date + 1][j];
					maxIndex = j;
				}

			if (maxIndex != myIndex)
			{
				for (int j = 0; j < numPeople; j++)
					life[date + 1][j] = life[date][j];

				life[date + 1][i] = false;
				life[date + 1][maxIndex] = false;

				kill(date + 1);

				if (isFinish)
					return;

			}

		}

}

