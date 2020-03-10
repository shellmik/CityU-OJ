#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
#define pii pair<int, int>

int m[130][130];//The matrix
int arr1[4] = { -1, 1, 0, 0 };
int arr2[4] = { 0,0,1,-1 };//вСсриооб

int solution(int N)
{
	int **sol = new int*[N];
	for (int i = 0; i < N; i++)
	{
		sol[i] = new int[N];
	}

	bool** visited = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new bool[N];
		for (int k = 0; k < N; k++)
		{
			visited[i][k] = false;
		}
	}
	queue<pii> q;

	sol[0][0] = m[0][0];
	q.push(make_pair(0,0));

	while (!q.empty())
	{
		pii curr = q.front();
		visited[curr.first][curr.second] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = curr.first + arr1[i];
			int y = curr.second + arr2[i];
			if(x>=0&&x<N&&y>=0&&y<N)
			{
				if (!visited[x][y])
				{
					sol[x][y] = m[x][y] + sol[curr.first][curr.second];
					q.push(make_pair(x, y));
					visited[x][y] = true;
				}
				else
				{
					if (m[x][y] + sol[curr.first][curr.second] < sol[x][y])
					{
						sol[x][y] = m[x][y] + sol[curr.first][curr.second];
						q.push(make_pair(x, y));
					}
				}
			}
		}
	}
	int ans = sol[N - 1][N - 1];
	delete[] sol;
	delete[] visited;
	return ans;
}

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	int N;
	int cases = 0;
	while (cin >> N)
	{
		if (N == 0)
			break;
		cases++;
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> m[i][k];
			}
		}

		printf("Problem %d: %d\n", cases, solution(N));
	}

}