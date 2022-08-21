#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node 
{
	vector<node*> childs;
};

node* nodes;

int getMinTime(node n);

bool compare(int i, int j)
{
	return i > j;
}

int main() 
{
	int size;
	cin >> size;

	nodes = new node[size];

	int tmp;
	cin >> tmp;

	for (int i = 1; i < size; i++)
	{
		cin >> tmp;
		nodes[tmp].childs.push_back(nodes + i);
	}

	cout<<getMinTime(nodes[0]);

}

int getMinTime(node n)
{
	if (n.childs.size() == 0)
		return 0;


	int* times = new int[n.childs.size()];

	for (int i = 0; i < n.childs.size(); i++)
		times[i] = getMinTime(*(n.childs[i]));

	int result = 0;

	sort(times, times + n.childs.size(), compare);
	
	for (int i = 0; i < n.childs.size(); i++)
		result = result > times[i] + i + 1 ? result : times[i] + i + 1;

	return result;

}

