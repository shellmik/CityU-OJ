//4:40 2/2/2020
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;

class graph
{
public:
	int vertices;
	list<int> *l;
	graph(int N)
	{
		vertices = N;
		l = new list<int>[N];
	}
	void add(int i1,int i2)
	{
		l[i1].push_back(i2);
		l[i2].push_back(i1); 
	}
	void print()
	{
		for (int i=0; i< vertices; i++)
		{
			for (auto it = l[i].begin(); it != l[i].end(); it++)
			{
				cout << *it << "-";
			}
			cout << endl;
		}
	}
	void bfs(int a, int b);
};

void graph::bfs(int ip1, int ip2)
{
	int visited[10000];
	memset(visited, 0, sizeof(visited));
	visited[ip1] = 1;

	queue<int> q;
	q.push(ip1);
	bool isFound = false;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (auto it = l[num].begin(); it !=l[num].end(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = visited[num]+1;
				q.push(*it);
			}
			if (*it == ip2)
			{
				cout << visited[*it] - 1 << endl;
				isFound = true;
				break;
			}
		}
	}

}

void sieve(vector <int> &V)
{
	const int N = 10000;
	bool prime[N];
	memset(prime, true, sizeof(prime));
	prime[1] = false;

	for (int p = 2; p*p < N; p++)
	{
		if (prime[p])
		{
			for (int i = p*p; i < N; i+=p)
			{
				prime[i] = false;
			}
		}
	}
	for (int i = 1000; i < N; i++) 
	{
		if (prime[i])
		{
			V.push_back(i);
		}
	}
}

bool compare(int a, int b)
{
	string str_a = to_string(a);
	string str_b = to_string(b);
	int judge[4] = { 0 };
	if (str_a[0] == str_b[0])
		judge[0] = 1;
	if (str_a[1] == str_b[1])
		judge[1] = 1;
	if (str_a[2] == str_b[2])
		judge[2] = 1;
	if (str_a[3] == str_b[3])
		judge[3] = 1;

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!judge[i])
			sum++;
	}

	if (sum == 1)
		return true;
	else
		return false;
}

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	//find all the primes from 1000 to 9999
	vector <int> prime;
	sieve(prime);

	//push all the adjacent primes in the adjacency list
	int n = prime.size();
	graph g(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (compare(prime[i], prime[j]))
			{
				g.add(i, j);
			}
		}
	}

	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int p1, p2;
		scanf_s("%d %d", &p1, &p2);
		
		//find the index of both p1 and p2, then do bfs
		int ip1, ip2;
		for (int i = 0; i < n; i++)
		{
			if (prime[i] == p1)
			{
				ip1 = i;
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (prime[i] == p2)
			{
				ip2 = i;
				break;
			}
		}
		g.bfs(ip1, ip2);
	}
}