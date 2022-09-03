#include <iostream>
#include <queue>
using namespace std;

struct road 
{
	int start;
	int end;
};

bool operator<(const road r2, const road r1)
{
	if (r1.start < r2.start)
		return true;
	else if (r1.start > r2.start)
		return false;
	
	return r1.end < r2.end;
}

priority_queue<road> roads;
priority_queue<road> remains;
queue<road> results;

int n;
int m;

bool getResult();

int main() 
{
	cin >> n >> m;

	for(int i = 0; i< n; i++)
		for (int j = 0; j < n; j++)
		{
			char inp;
			cin >> inp;
			if (j > i && inp == 'Y')
				roads.push({ i,j });
		}

	if (getResult())
	{
		int* numbers = new int[n];
		for (int i = 0; i < n; i++)
			numbers[i] = 0;

		while (!results.empty())
		{
			road nowRoad = results.front();
			results.pop();

			numbers[nowRoad.start]++;
			numbers[nowRoad.end]++;
		}

		for (int i = 0; i < n; i++)
			cout << numbers[i] << " ";

	}
	else
	{
		cout << -1;
	}

}

bool getResult() 
{
	int* set = new int[n];
	for (int i = 0; i < n; i++)
		set[i] = i;

	while (!roads.empty())
	{
		road nowRoad = roads.top();
		roads.pop();

		int sh = nowRoad.start;
		int eh = nowRoad.end;

		while (set[sh] != sh)
			sh = set[sh];

		while (set[eh] != eh)
			eh = set[eh];

		if (sh != eh)
		{
			results.push(nowRoad);
			set[eh] = sh;
			if (results.size() == n - 1)
				break;
		}
		else
			remains.push(nowRoad);

	}

	if (results.size() != n - 1)
		return false;

	for (int i = 0; i < m - (n - 1); i++)
	{
		if (!remains.empty())
		{
			results.push(remains.top());
			remains.pop();
		}
		else if (!roads.empty())
		{
			results.push(roads.top());
			roads.pop();
		}
		else
			return false;
	}

	return true;

}