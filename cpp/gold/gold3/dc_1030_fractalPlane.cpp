#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

Point operator-(Point p1,Point p2) 
{
	return Point{ p1.x - p2.x,p1.y - p2.y };
}

Point operator+(Point p1, Point p2)
{
	return Point{ p1.x + p2.x,p1.y + p2.y };
}

int s;
int n;
int k;
Point p1;
Point p2;
int** result;

void fill(Point w1, Point w2, Point l1);

int main() 
{
	cin >> s >> n >> k >> p1.y >> p2.y >> p1.x >> p2.x;

	result = new int*[p2.y - p1.y + 1];
	for (int i = 0; i < p2.y - p1.y + 1; i++)
		result[i] = new int[p2.x - p1.x + 1];

	fill(p1, p2, { 0,0 });

	for (int y = 0; y < p2.y - p1.y + 1; y++)
	{
		for (int x = 0; x < p2.x - p1.x + 1; x++)
			cout << result[y][x];
		cout << "\n";
	}

}

void fill(Point w1, Point w2, Point l1) 
{
	if (w2.x == 0 && w2.y ==0)
	{
		result[l1.y][l1.x] = 0;
		return;
	}


	int max = w2.x > w2.y ? w2.x : w2.y;

	int needS = 0;
	int needSize = 1;

	for (needSize = 1; needSize <= max; needSize *= n)
		needS++;

	int UnitSize = needSize / n;
	Point Unit1 = { w1.x / UnitSize,w1.y / UnitSize };
	Point Unit2 = { w2.x / UnitSize,w2.y / UnitSize };

	int lowk = n/2 - k/2;
	int highk = n%2 == 1 ? n / 2 + k / 2 : (n / 2 + k / 2 )-1;
	
	for(int y = Unit1.y;y<=Unit2.y;y++)
		for (int x = Unit1.x; x <= Unit2.x; x++)
		{
			Point nowW1;
			Point nowW2;
			nowW1.x = x * UnitSize > w1.x ? x * UnitSize : w1.x;
			nowW1.y = y * UnitSize > w1.y ? y * UnitSize : w1.y;
			nowW2.x = (x+1) * UnitSize - 1 < w2.x ? (x + 1) * UnitSize - 1 : w2.x;
			nowW2.y = (y+1) * UnitSize - 1 < w2.y ? (y + 1) * UnitSize - 1 : w2.y;

			Point nowL1 = l1 + (nowW1 - w1);

			if (lowk <= x && x <= highk && lowk <= y && y <= highk)
			{
				nowW2 = nowL1 + (nowW2 - nowW1);
				nowW1 = nowL1;

				for (int y2 = nowW1.y; y2 <= nowW2.y; y2++)
					for (int x2 = nowW1.x; x2 <= nowW2.x; x2++)
						result[y2][x2] = 1;
			}
			else
			{
				if (UnitSize == 1)
					result[nowL1.y][nowL1.x] = 0;
				{
					nowW1.x -= x * UnitSize;
					nowW1.y -= y * UnitSize;
					nowW2.x -= x * UnitSize;
					nowW2.y -= y * UnitSize;

					fill(nowW1, nowW2, nowL1);
				}
			}

		}


}

