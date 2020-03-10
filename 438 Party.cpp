#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;


#include<stdio.h>
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		if (n <= 2)
			printf("0\n");
		if (n > 2)
			printf("%d\n", n - 2);
	}
	return 0;
}