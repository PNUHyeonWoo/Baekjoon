#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int sCount;
int* S;
int n;

struct goodInt 
{
	long long data;
	long long goods;
	int low;
	int high;
	bool isLeft;

	goodInt() 
	{}

	goodInt(int data,int low,int high,bool isLeft)
	{
		this->data = data;
		this->low = low;
		this->high = high;
		if (low != -1)
			this->goods = (long long)(data - low) * (long long)(high - data) - 1;
		else
			this->goods = 0;
		this->isLeft = isLeft;
	}

	

};

bool operator <(const goodInt g1, const goodInt g2)
{
	if (g1.goods == g2.goods)
		return g1.data > g2.data;
	else
		return g1.goods > g2.goods;
}

void good();

int main() 
{
	cin >> sCount;
	S = new int[sCount];
	for (int i = 0; i < sCount; i++)
		cin >> S[i];
	cin >> n;
	sort(S, S + sCount);

	good();

}

void good() 
{
	priority_queue<goodInt> pq;

	for (int i = 0; i < sCount; i++)
		pq.push(goodInt(S[i], -1, -1, true));

	int low = 0;

	for (int i = 0; i < sCount; i++) 
	{	
		if (low + 1 < S[i])
			pq.push(goodInt(low + 1, low, S[i],true));

		if (low + 2 < S[i])
			pq.push(goodInt(S[i] - 1, low, S[i],false));

		low = S[i];
	}

	while (!pq.empty())
	{
		goodInt nowGoodInt = pq.top();
		pq.pop();

		cout << nowGoodInt.data << " ";
		if (--n <= 0)
			return;

		if (nowGoodInt.isLeft)
		{
			if (nowGoodInt.data < (nowGoodInt.low + nowGoodInt.high) / 2)
				pq.push(goodInt(nowGoodInt.data + 1, nowGoodInt.low, nowGoodInt.high, true));
		}
		else
		{
			if (nowGoodInt.data-1 > (nowGoodInt.low + nowGoodInt.high) / 2)
				pq.push(goodInt(nowGoodInt.data - 1, nowGoodInt.low, nowGoodInt.high, false));
		}

	}

	int last = S[sCount - 1]+1;
	for (int i = 0; i < n; i++)
		cout << last++<<" ";

}