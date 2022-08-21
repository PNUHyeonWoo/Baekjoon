#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

int xSize;
int ySize;
int** board;
int** route;
int** bestStart;
int result = 0;

bool isFinish = false;

void traking(Point pos, int jumps);

int main() 
{
	cin >> ySize >> xSize;

	board = new int* [ySize];
	route = new int* [ySize];
	bestStart = new int* [ySize];

	for (int i = 0; i < ySize; i++)
	{
		board[i] = new int[xSize];
		route[i] = new int[xSize];
		bestStart[i] = new int[xSize];
	}

	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			char c;
			cin >> c;
			if (c == 'H')
				board[y][x] = -1;
			else
				board[y][x] = c - '0';

			route[y][x] = 0;
			bestStart[y][x] = 0;
		}
	
	traking({ 0,0 }, 0);

	cout << result;

}

//백트래킹 + 다이나믹 프로그래밍
void traking(Point pos,int jumps) //start ({0,0} , 0)
{

	if (isFinish || !(0 <= pos.x && pos.x < xSize && 0 <= pos.y && pos.y < ySize) || board[pos.y][pos.x] == -1)
		return;

	result = result > ++jumps ? result : jumps;

	if (jumps <= bestStart[pos.y][pos.x])
		return;
	else
		bestStart[pos.y][pos.x] = jumps;

	if(route[pos.y][pos.x] == 0)
		route[pos.y][pos.x] = 1;
	else
	{
		isFinish = true;
		result = -1;
		return;
	}

	traking({ pos.x + board[pos.y][pos.x],pos.y}, jumps);
	traking({ pos.x - board[pos.y][pos.x],pos.y }, jumps);
	traking({ pos.x,pos.y + board[pos.y][pos.x] }, jumps);
	traking({ pos.x,pos.y - board[pos.y][pos.x] }, jumps);

	route[pos.y][pos.x] = 0;


}

/*
다이나믹 프로그래밍 방법 (int 리턴받는 방식)
트래킹 함수를 pos하나만 받고 int를 리턴하는 방식으로 만들고 루트 함수의 리턴값을 결과값으로 받는 형식으로 수정한다.
각 보드칸에서 시작했을때 가장 많이 움직일 수 있는 양을 저장하는 전역 -1들로 초기화된 int**를 하나만든다.
트레킹 함수가 특정 보드칸에 호출되면 구멍or초과 인지 숫자인지 루트인지 체크한다.
루트면 result 무한으로 특수 종료한다.
구멍or초과이면 0을 리턴한다.
숫자면 아래를 단계들을 실행한다.
위의 int**의 자기 인덱스를 참고하여 0보다 크거나 같다면 이미 계산이 된것으로 그 값을 그대로 리턴해준다.
-1이면 아직 갱신이 되지 않은 것이므로 사방향 재귀 트래킹을 하여 갱신해준다.
사방향 재귀트래킹시 4방향 재귀를 호출하고 그 리턴 값중 가장 큰 값에 + 1한 값을 전역 int** 의 자기 인덱스에 갱신해주고 리턴한다.
result = function({0,0});
이렇게 호출해주면 result에 결과값이 담긴다.
*/

