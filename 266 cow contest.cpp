#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int m[105][105];


//Count the cows who can have their position determined
int count(int N)
{
	int sum = 0;
	bool ok;
	for (int i = 0; i < N; i++)
	{
		ok = true;
		for (int j = 0; j < N; j++)
		{
			if (i == j)continue;
			if (m[i][j] == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
			sum = sum + 1;
	}
	return sum;
}

int calculate(int N)
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		
			for (int j = i+1; j < N; j++)
			{
				if (k == j||k==i||i==j)
					continue;
				if (m[i][j] != 0)
					continue;
				if (m[i][k] == 1 && m[k][j] == 1)
				{
					m[i][j] = 1;
					m[j][i] = -1;
					continue;
				}
				else if (m[i][k] == -1 && m[k][j] == -1)
				{
					m[i][j] = -1;
					m[j][i] = 1;
					continue;
				}
			}
		}
	}
	return count(N);
}

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	int N, M;
	int x, y;
	while (cin >> N >> M)
	{
		memset(m, NULL, sizeof(m));
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y;
			x = x - 1;
			y = y - 1;
			m[x][y] = 1;
			m[y][x] = -1;
		}
		cout << calculate(N) << endl;
	}
}