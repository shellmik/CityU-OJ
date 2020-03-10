#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
 
int city[100][100];

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	int n, m;
	while (cin >> n >> m)
	{
		memset(city, 0, sizeof(city));
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			city[u][v] = city[v][u] = w;
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j||i==k||j==k)continue;
					if (city[i][j] == 0 && city[i][k] != 0 && city[k][j] != 0)
					{
						city[i][j] = city[i][k] + city[k][j];
					}
					else if(city[i][k] != 0 && city[k][j] != 0&& city[i][j] > city[i][k] + city[k][j])
					{	
						city[i][j] = city[i][k] + city[k][j];
					}
				}
			}
		}
		
		int min = 0;
		int min_idx = 0;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += city[i][k];
			}
			if (i == 0)
			{
				min = sum;
				min_idx = i + 1;
			}
			else if (sum < min)
			{
				min = sum;
				min_idx = i + 1;
			}
		}
		
		cout << min_idx << endl;
	}
}