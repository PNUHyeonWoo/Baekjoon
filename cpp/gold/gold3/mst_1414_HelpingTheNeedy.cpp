#include <iostream>
#include <queue>

using namespace std;

int kruskalTotalAmount(int** graph, int size);


struct LAN 
{
	int amount;
	int i;
	int j;
};

bool operator <(const LAN l1, const LAN l2)
{
	return l1.amount > l2.amount;
}

int main() 
{
	int size;
	cin >> size;

	int** Graph = new int*[size];
	for (int i = 0; i < size; i++)
		Graph[i] = new int[size];

	int total = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			char c;
			cin >> c;
			int tmp = (int)c;
			if (tmp != 48)
				Graph[i][j] = tmp < 91 ? tmp - 38 : tmp - 96;
			else
				Graph[i][j] = 0;

			total += Graph[i][j];	
		}

	int result = kruskalTotalAmount(Graph, size);

	cout << (result == -1 ? -1: total - result) ;

	
}

int kruskalTotalAmount(int** graph, int size) 
{
	priority_queue<LAN> lans;
	int result = 0;

	for(int i = 0; i< size;i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				continue;
			LAN lan;
			lan.amount = graph[i][j];
			if (lan.amount == 0)
				continue;
			lan.i = i;
			lan.j = j;
			lans.push(lan);
		}

	int* set = new int[size];

	for (int i = 0; i < size; i++)
		set[i] = i; //if direct self, then it is head

	int sumAmount = 0;

	while (sumAmount < size - 1)
	{
		if (lans.size() == 0)
			return -1;

		LAN lan = lans.top();
		lans.pop();

		int iHead = set[lan.i];

		while (iHead != set[iHead])
			iHead = set[iHead];

		int jHead = set[lan.j];

		while (jHead != set[jHead])
			jHead = set[jHead];

		if (iHead == jHead)
			continue;

		result += lan.amount;
		set[jHead] = iHead;
		sumAmount++;
	}

	return result;

}


