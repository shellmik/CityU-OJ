#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char a[1001];
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		int len = strlen(a);
		int sum = 0;
		for (int i = 0; i < len; i++)
		{ 
			sum += min(a[i]-'A', 26-(a[i]-'A'));
		}

		int ans = sum + len - 1;
		for (int i = 1; i < len; i++)
		{
			if (a[i] == 'A')
			{
				int j;
				for (j = i + 1; j < len && a[j] == 'A'; j++);
				ans = min(ans , sum + min((len - j) * 2 + i - 1, (i - 1) * 2 + len - j));
			}

		}
		cout << ans << endl;
	}
}