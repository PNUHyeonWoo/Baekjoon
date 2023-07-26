#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct zem 
{
	int weight;
	int value;
};

struct cmp 
{
	bool operator()(const zem a,const zem b) const 
	{
		return a.value < b.value;
	}
};


priority_queue<zem, vector<zem>, cmp> zems;
multiset<int, greater<int>> bags;

int n, k;
long long totalValue = 0;

int main() 
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		zems.push({ w,v });
	}

	for (int i = 0; i < k; i++)
	{
		int w;
		cin >> w;
		bags.insert(w);
	}

	for (int i = 0; i < n; i++) 
	{
		if (bags.empty())
			break;

		zem nowZem = zems.top();
		zems.pop();

		auto iter = bags.insert(nowZem.weight);

		if (iter == bags.begin())
			bags.erase(iter);
		else 
		{
			totalValue += nowZem.value;
			auto begin = --iter;
			iter++;
			iter++;
			auto end = iter;
			bags.erase(begin, end);
		}

	
	}

	cout << totalValue;



}
