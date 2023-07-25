#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int v;

struct result 
{
	int totalMax;
	int lineMax;
};

struct node 
{
	int index;
	vector<node*> nhs;
	vector<int> weights;
};

node* nodes;

result getMaxs(node* loot, int parentIndex);

int main() 
{
	cin >> v;

	nodes = new node[v];

	for (int i = 0; i < v; i++)
		nodes[i].index = i;

	for (int i = 0; i < v; i++)
	{
		int index;
		cin >> index;
		index--;
		int toIndex;
		cin >> toIndex;
		while (toIndex != -1)
		{
			toIndex--;
			nodes[index].nhs.push_back(&nodes[toIndex]);
			int w;
			cin >> w;
			nodes[index].weights.push_back(w);
			cin >> toIndex;
		}
	}

	 cout << getMaxs(nodes, -1).totalMax;

}

/*
부분트리의 최대값과 일자 최대값을 리턴하는 함수:

리프 = (0,0)
스템 = totalMax = (max(자신 포함 max값, 자신 비포함 max값)  , lineMax = max(각 자식의 일자 최대값 + 각 자식으로의 간선) )
자신 포함 max값 = 자식 하나일땐 : 자식 일자 최대값 + 간선 , 자식 둘이상일땐  (자식 일자값 + 간선)값이 가장 큰 두개의 합
자신 비포함 max값 = max(자식 토탈 최대값)
*/

result getMaxs(node* loot,int parentIndex) 
{
	if (loot->nhs.size() == 1 && loot->nhs[0]->index == parentIndex)
		return { 0,0 };

	result r;

	vector<result> cResults;
	int parentInNhs = -1;

	for (int i = 0; i < loot->nhs.size(); i++)
		if (loot->nhs[i]->index != parentIndex)
			cResults.push_back(getMaxs(loot->nhs[i], loot->index));
		else
			parentInNhs = i;

	if(parentInNhs != -1)
		loot->weights.erase(loot->weights.begin() + parentInNhs);

	int lmax1 = 0;
	int lmax2 = 0;

	for (int i = 0; i < cResults.size(); i++)
	{
		int nowResult = cResults[i].lineMax + loot->weights[i];
		if (lmax1 < nowResult)
		{
			lmax2 = lmax1;
			lmax1 = nowResult;
		}
		else if (lmax2 < nowResult)
			lmax2 = nowResult;
	}

	r.lineMax = lmax1;

	int totalMaxIncludeSelf = lmax1 + lmax2;

	int totalMaxNotInlcudeSelf = 0;
	for (int i = 0; i < cResults.size(); i++)
		totalMaxNotInlcudeSelf = totalMaxNotInlcudeSelf > cResults[i].totalMax ? totalMaxNotInlcudeSelf : cResults[i].totalMax;

	r.totalMax = max(totalMaxIncludeSelf, totalMaxNotInlcudeSelf);



	return r;



}