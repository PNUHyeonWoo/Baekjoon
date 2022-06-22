#include <iostream>
using namespace std;

void count(unsigned int n); 

int main()
{
    unsigned int n;
	cin >> n;
	unsigned int* list = new unsigned int[n*2];
	for (unsigned int i = 0; i < n*2; i++)  cin >> list[i];

	for (unsigned int i = 0; i < n; i++)
		count(list[i*2 + 1] - list[i*2]);

	return 0;
}

unsigned int sum(unsigned int n) 
{
	return n * (n + 1) / 2;
}

void count(unsigned int n) 
{
	unsigned int result = 0;
	unsigned int speed = 0;
	while (n > 0)
	{
		if (sum(speed + 1) <= n) 
			n -= (++speed);
		else if(sum(speed) <= n)
			n -= (speed);
		else
			n -= (--speed);
		result++;
	}

	cout << result<<"\n";

}