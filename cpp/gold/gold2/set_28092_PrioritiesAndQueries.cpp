#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct sk 
{
	int index;
	int num;
	int min;
	bool isGraph;
};

struct node 
{
	bool isLoot;
	union 
	{
		sk* set;
		int parents;
	};
};

struct cmpSk{
	bool operator()(const sk* l, const sk* r) const
	{
		if (l->num > r->num)
			return true;
		else if (l->num < r->num)
			return false;
		else
			return l->min < r->min;
	}
};

int n, q;

node* nodeArray;

set<sk*, cmpSk> trees;

void getSet(int i, sk*& k, int& index);

int main()
{
	cin >> n >> q;
	nodeArray = new node[n];

	for (int i = 0; i < n; i++)
	{
		nodeArray[i] = { true,new sk{i,1,i,false} };
		trees.insert(nodeArray[i].set);
	}

	for (int i = 0; i < q; i++)
	{
		int qri;
		cin >> qri;
		if (qri == 1)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			int ui, vi;
			sk* uset;
			sk* vset;

			getSet(u, uset, ui);
			getSet(v, vset, vi);

			if (uset == vset && !uset->isGraph)
			{
				trees.erase(uset);
				uset->isGraph = true;
			}
			else if (uset != vset)
			{
				if (!uset->isGraph && !vset->isGraph)
				{
					trees.erase(vset);
					trees.erase(uset);
					uset->min = uset->min < vset->min ? uset->min : vset->min;
					uset->num += vset->num;
					trees.insert(uset);
					nodeArray[vi].isLoot = false;
					nodeArray[vi].parents = ui;
				}
				else
				{
					if (!uset->isGraph)
					{
						trees.erase(uset);
						uset->isGraph = true;
					}
					if (!vset->isGraph)
					{
						trees.erase(vset);
						vset->isGraph = true;
					}
				}
			}


		}
		else 
		{
			sk* firetTree = *trees.begin();
			trees.erase(firetTree);
			cout << firetTree->min + 1 << "\n";
		}


	}

}

void getSet(int i, sk*& k, int& index)
{
	while (!nodeArray[i].isLoot)
		i = nodeArray[i].parents;
	index = i;
	k = nodeArray[index].set;
}