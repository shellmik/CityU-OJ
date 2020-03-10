#include<stdio.h>
#include<iostream>
#include<array>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define ar4 array<int, 4>
ar4 c;
int T;

void bfs()
{
	if (T > c[3]&&T>c[2]&&T>c[1]&&T>c[0])
	{
		cout << -1 << endl;
		return;
	}

	queue<ar4> q;
	q.push({ 0,0,0,0 });
	map<ar4, int> visited;
	visited[{0,0,0,0}] = 1;
	bool isFound = false;//see if there is a solution

	ar4 prev;
	while (!q.empty())
	{
		ar4 p = q.front();
		q.pop();
		
		if (p[0] > c[0] || p[1] > c[1] || p[2] > c[2] || p[3] > c[3] ||
			p[0] < 0 || p[1] < 0 || p[2] < 0 || p[3] < 0)
			continue;

		if (p[0] == T || p[1] == T || p[2] == T || p[3] == T)
		{
			cout << visited[p]-1 << endl;
			isFound = true;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			ar4 temp = p;
			temp[i] = c[i];
			if (!visited[temp])
			{
				visited[temp] = visited[p] + 1;
				q.push(temp);
			}
		
			temp[i] = 0;
			if (!visited[temp])
			{
				visited[temp] = visited[p] + 1;
				q.push(temp);
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//two cups are not the same
				if (i == j)
					continue;

				//new cup
				ar4 temp = p;

				//pour cup i to cup j;
				if (p[i] >= c[j] - p[j])
				{
					temp[j] = c[j];
					temp[i] = p[i] - (c[j] - p[j]);
				}
				else
				{
					temp[j] = p[i] + p[j];
					temp[i] = 0;
				}
				
				if (!visited[temp])
				{
					visited[temp] = visited[p] + 1;
					q.push(temp);
				}
			}
		}
	}

	if (!isFound)
	{
		cout << "-1" << endl;
		return;
	}
}


int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	while (cin >> c[0] >> c[1] >> c[2] >> c[3] >> T)
	{
		bfs();
	}
}