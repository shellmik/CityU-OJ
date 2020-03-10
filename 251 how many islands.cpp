#include<stdio.h>
#include <string.h> 
#include<iostream>
using namespace std;

int island[51][51];
bool visited[51][51];
int arr1[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int arr2[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

bool isOK(int height, int width, int row, int col)
{
	return(row >= 0 && row < height && col >= 0 && col < width && island[row][col] && !visited[row][col]);
}

void dfs(int height, int width, int row, int col)
{
	visited[row][col] = true;
	for (int i = 0; i < 8; i++)
	{
		if (isOK(height, width, row + arr1[i], col + arr2[i]))
			dfs(height, width, row + arr1[i], col + arr2[i]);
	}
}

int main()
{
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);

	int w, h;
	while (scanf_s("%d %d", &w, &h) != EOF)
	{
		int cnt = 0;
		if ((w == 0) && (h == 0))
			break;
		memset(island, 0, sizeof(island));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < h; i++)//height for rows
		{
			for (int k = 0; k < w; k++)//width for columns
			{
				cin >> island[i][k];
			}
		}

		for (int i = 0; i < h; i++)//height for rows
		{
			for (int k = 0; k < w; k++)//width for columns
			{
				if (island[i][k] && !visited[i][k])
				{
					dfs(h, w, i, k);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
}
