#include<iostream>
using namespace std;
int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	int k, a, b, v;
	while (cin >> k >> a >> b >> v)
	{

		int ans = 0;

		//Number of sections needed
		int sections = a / v;
		if (v * sections < a)sections++;

		//n boxes that have full divided, capaity: k
		int n = b / (k - 1);

		//1 box that are not fully divided, capacity: c
		int c = b - (k - 1) * n + 1;

		int remainder;
		if (sections <= n * k)
		{
			ans = sections / k;
			if (ans * k < sections)ans++;
		}
		else
		{
			ans += n;
			remainder = sections - n * k;
			if (remainder <= 1*c)
			{
				ans++;
			}
			else
			{
				ans++;
				remainder -= c;
				ans += remainder;
			}
		}
		cout << ans << endl;

	}
}