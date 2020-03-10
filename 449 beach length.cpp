#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<sstream>
using namespace std;

char arr[51][51];
bool visited[51][51];
int row = 0;
int col = 0;

bool isValid(int i, int k)
{
	return(i >= 0 && i < row && k >= 0 && k < col);
}

void dfs(int i, int k, int &cnt)
{
	static int arr1[6] = { -1, -1, 0, 0, 1, 1 };//col
	static int arr2[6] = { -1,0,-1,1,-1,0 };//row
	static int arr3[6] = { 0, 1, -1, 1, 0, 1 } ;//row
	visited[i][k] = true;
	int Nr, Nk;
	
	for (int m = 0; m < 6; m++)
	{
		if (i % 2 == 0)
		{
			Nr = i + arr1[m];
			Nk = k + arr2[m];
		}
		else
		{
			Nr = i + arr1[m];
			Nk = k + arr3[m];
		}

		if (isValid(Nr, Nk))
		{
			if (arr[Nr][Nk] == '.')
			{
				cnt++;
			}
			else if (arr[Nr][Nk] == '#' && !visited[Nr][Nk])
			{
				dfs(Nr, Nk, cnt);
			}
		}
	}
}


void calculate()
{
	int cnt = 0;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			if ((arr[i][k] == '#') && !visited[i][k])
			{
				dfs(i, k, cnt);
			}
		}
	}
	cout << cnt << endl;
	//ÇåÁã
	memset(arr, NULL, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	row = col = 0;
}


int main()
{
	FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	
	//Initialization
	string str;

	while (getline(cin, str))
	{
		if (str == "")
		{
			calculate();
			continue;
		}
		else
		{
			stringstream ss(str);
			col = str.length();
			for (int i = 0; i < col; i++)
			{
				ss >> arr[row][i];
			}
			row++;
		}
	}
}