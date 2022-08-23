#include <iostream>
#include <list>
#include <map>
#include <cmath>

using namespace std;


const int dpMax = 4000000;
int* mins;

int a;
int b;
int k;

void calMin(int target);
int sk(int i);

int main() 
{
	mins = new int[dpMax];
	for (int i = 0; i < dpMax; i++)
		mins[i] = -1;

	cin >> a >> b >> k;
	long long result = 0;
	for (int i = a; i <= b; i++)
	{
		calMin(i);
		result += mins[i];
	}
	cout << result;
	
}

void calMin(int target)
{
	if (mins[target] != -1)
		return;

	list<int> ll;
	ll.push_back(target);
	list<int>::iterator node = ll.begin();
	map<int, bool> roof;

	int nowMin;

	while (true)
	{
		if (mins[*node] != -1)
		{
			nowMin = mins[*node];
			for (list<int>::iterator n = --node; n != ll.begin(); --n)
			{
				if (nowMin > *n)
				{
					nowMin = *n;
					mins[*n] = *n;
				}
				else
					mins[*n] = nowMin;

			}
			mins[target] = nowMin < target ? nowMin : target;
			break;
		}
		else if (roof.find(*node) != roof.end())
		{
			int roofdata = *node;
			node--;
			nowMin = roofdata;
			while (*node != roofdata)
			{
				nowMin = nowMin < *node ? nowMin: *node;
				node--;
			}

			for (list<int>::iterator n = ++node; n != ll.end(); ++n)
				mins[*n] = nowMin;

			node--;

			if (node == ll.begin())
				break;

			for (list<int>::iterator n = --node; n != ll.begin(); --n)
			{
				if (nowMin > *n)
				{
					nowMin = *n;
					mins[*n] = *n;
				}
				else
					mins[*n] = nowMin;
			}
			mins[target] = nowMin < target ? nowMin : target;
			break;
		}
		else
		{
			roof.insert({ *node,false });
			ll.push_back(sk(*node));
			node++;
		}
	}


}

int sk(int i) 
{
	int result = 0;
	while (i > 0)
	{
		result += pow((i % 10),k);
		i = i / 10;
	}
	return result;

}