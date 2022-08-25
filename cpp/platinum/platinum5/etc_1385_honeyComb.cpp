#include <iostream>

using namespace std;

int a;
int b;

int ax;
int ay;
int bx;
int by;

int** honeycomb;

const int arraylength = 1200;
const int xCenter = 600;
const int yCenter = 600;

void buildComb(int max);
void atob();

int test = 0;

int main() 
{
	cin >> a >> b;

	honeycomb = new int* [arraylength];
	for (int i = 0; i < arraylength; i++)
		honeycomb[i] = new int[arraylength];

	buildComb(1078000);
	atob();

}

void buildComb(int max)
{
	int level = 1;
	int i = 1;
	int x = 600;
	int y = 600;

	honeycomb[y][x] = i;

	int count = 1;
	int state = 0;



	while (i < max)
	{
		i++;
		if (0 > --count)
		{
			if (state == 6)
			{
				level++;
				count = 0;
				state = 0;
			}
			else if (state == 0)
			{
				state++;
				count = level - 2;
				if (count < 0)
				{
					state++;
					count = level - 1;
				}
			}
			else
			{
				state++;
				count = level - 1;
			}
		}

		switch (state)
		{
		case 0:
			y--;
			break;
		case 1:
			x++;
			break;
		case 2:
			x++;
			y++;
			break;
		case 3:
			y++;
			break;
		case 4:
			x--;
			break;
		case 5:
			x--;
			y--;
			break;
		case 6:
			y--;
			break;
		default:
			break;
		}

		//cout << x << " " << y << "\n";

		if (i == a)
		{
			ax = x;
			ay = y;
		}
		if (i == b)
		{
			bx = x;
			by = y;
		}

		honeycomb[y][x] = i;

	}

	if (1 == a)
	{
		ax = 600;
		ay = 600;
	}
	if (1 == b)
	{
		bx = 600;
		by = 600;
	}


}

void atob() 
{
	while (true)
	{
		//test++;
		cout << honeycomb[ay][ax] << " ";
		if (ax == bx && ay == by)
			break;

		if (ax == bx)
		{
			if (ay > by)
				ay--;
			else
				ay++;

		}
		else if (ax > bx)
		{
			if (ay == by)
				ax--;
			else if (ay > by)
			{
				ax--;
				ay--;
			}
			else
				ay++;
		}
		else
		{
			if (ay == by)
				ax++;
			else if (ay > by)
				ay--;
			else
			{
				ax++;
				ay++;
			}		
		}


	}
	//cout << test;


}



