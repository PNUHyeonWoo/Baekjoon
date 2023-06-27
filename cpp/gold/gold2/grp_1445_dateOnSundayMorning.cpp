#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;
int** cost;
pair<int, int> goal, start;

struct node 
{
	int y;
	int x;
	int pathCost;
};

struct cmp{
	bool operator()(node a, node b)
	{
		return a.pathCost > b.pathCost;
	}
};

priority_queue<node, vector<node>, cmp> fronteir;
set<pair<int, int>> endSet;

pair<int, int> UCS();

int main() 
{
	cin >> n >> m;
	cost = new int* [n];
	for (int i = 0; i < n; i++)
	{
		cost[i] = new int[m];
		for (int j = 0; j < m; j++)
			cost[i][j] = 0;
	}

	char tmp;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == 'F')
				goal = { i,j };
			else if (tmp == 'S')
				start = { i,j };
			else if (tmp == 'g')
			{
				cost[i][j] = 10000;
				if (0 < i && !cost[i - 1][j])
					cost[i - 1][j] = 1;
				if (i < n - 1 && !cost[i + 1][j])
					cost[i + 1][j] = 1;
				if (0 < j && !cost[i][j - 1])
					cost[i][j-1] = 1;
				if (j < m - 1 && !cost[i][j+1])
					cost[i][j+1] = 1;
			}
		}

	cost[start.first][start.second] = 0;
	cost[goal.first][goal.second] = 0;

	pair<int,int> result= UCS();
	cout << result.first << " " << result.second;
	

}


pair<int, int> UCS() 
{
	fronteir.push({ start.first,start.second,cost[start.first][start.second] });
	while (!fronteir.empty()) 
	{
		node nowNode = fronteir.top();
		fronteir.pop();
		if (!endSet.insert({ nowNode.y,nowNode.x }).second)
			continue;
		if (goal == pair<int,int>{nowNode.y, nowNode.x})
			return { nowNode.pathCost / 10000,nowNode.pathCost % 10000 };

		if (0 < nowNode.y && endSet.end() == endSet.find({ nowNode.y - 1,nowNode.x }))
			fronteir.push({ nowNode.y - 1,nowNode.x,nowNode.pathCost + cost[nowNode.y - 1][nowNode.x] });
		if (nowNode.y < n - 1 && endSet.end() == endSet.find({ nowNode.y + 1,nowNode.x }))
			fronteir.push({ nowNode.y + 1,nowNode.x,nowNode.pathCost + cost[nowNode.y + 1][nowNode.x] });
		if (0 < nowNode.x && endSet.end() == endSet.find({ nowNode.y,nowNode.x - 1 }))
			fronteir.push({ nowNode.y,nowNode.x - 1,nowNode.pathCost + cost[nowNode.y][nowNode.x - 1] });
		if (nowNode.x < m - 1 && endSet.end() == endSet.find({ nowNode.y,nowNode.x + 1 }))
			fronteir.push({ nowNode.y,nowNode.x + 1,nowNode.pathCost + cost[nowNode.y][nowNode.x + 1] });
			

	}

}

