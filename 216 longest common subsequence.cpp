#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

string a;
string b;
int dp[1005][1005];

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	while (getline(cin,a) && getline(cin, b);)
	{
		memset(dp, 0, sizeof(dp));
		int m = a.size();
		int n = b.size();

		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else if (a[i] == b[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		cout << dp[m][n] << endl;
	}
}