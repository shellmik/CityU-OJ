#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int grid[50][50];
//这个题是神经病吗？？？

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	int n, m;
	while (cin >> n >> m)
	{
		memset(grid, 0, sizeof(grid));
		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= m; k++)
			{
				cin >> grid[i][k];
			}
		}

		bool isFound = false;
		for (int i = n; i >= 1; i--)
		{
			for (int k = m; k >= 1; k--)
			{
				if (grid[i][k] == 1 && (i == n || i == 1 || k == m || k == 1))
					isFound = true;
			}
		}

		if (isFound)
			cout << 2 << endl;
		else
			cout << 4 << endl;
	}
}