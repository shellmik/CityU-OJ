#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
char board[8][8];

int arr1[8] = { -1,-2,-2,-1,1,2,2,1 };
int arr2[8] = { -2,-1,1,2,2,1,-1,-2 };
#define pii pair<int, int>
#define mp(x,y) make_pair(x,y)
pii b, w;
bool isFound;

void bfs(pii c)
{
	queue<pii> q;
	q.push(c);
	
	int visited[8][8] = { 0 };
	int xC = c.first;
	int yC = c.second;
	visited[xC][yC] = 1;

	while(!q.empty())
	{ 
		pii c = q.front();
		q.pop();

		int xC = c.first;
		int yC = c.second;

		for (int i = 0; i < 8; i++)
		{
			int xN = xC + arr1[i];
			int yN = yC + arr2[i];
			if (xN < 0 || xN > 7 || yN < 0 || yN > 7)
				continue;
			else if (visited[xN][yN])
				continue;
			else if (board[xN][yN] == '*')
				continue;
			else
			{
				visited[xN][yN] = visited[xC][yC] + 1;
				q.push(mp(xN, yN));
			}
			if (board[xN][yN] == '@')
			{
				isFound = true;
				printf("%d\n", visited[xN][yN]-1);
			}
			
		}
	}
}

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	int N;
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		printf("Case %d: ", i);
		memset(board, NULL, sizeof(board));
		isFound = false;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '#')
				{
					b.first = i;
					b.second = j;
				}
			}
		}
		bfs(b);
		if (!isFound)
		{
			cout << "IMPOSSIBLE" << endl;
		}
	}
}