#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;
#define llt long long int
const int MOD = 1000000007;
llt dp[1000001];
llt arr[1000001];

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));

		//Store all the box sizes in the array {1£¬2£¬4}
		llt k = 0;
		llt idx = 0;
		llt tmp = pow(M, k);
		while (tmp <= N)
		{
			arr[idx++] = tmp;
			tmp = pow(M, ++k);
		}

		dp[0] = 1;
		for (llt i = 0; i < idx; i++)
			for (llt j = arr[i]; j <= N; j++)
				dp[j] = dp[j] + dp[j - arr[i]]% MOD;

		cout << dp[N] % MOD << endl;
	}

}