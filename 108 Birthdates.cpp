#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	int N;
	scanf_s("%d", &N);
	char name[16];
	char OLD_name[16];
	int OLDDate;
	char YOUNG_name[16];
	int YOUNGDate;
	for (int i = 0; i < N; i++)
	{
		memset(name, '\0', 16);
		int d, m, y;
		scanf_s("%s", name, 16);
		scanf_s("%d %d %d", &d, &m, &y);
		int tot = y * 10000 + m * 100 + d;

		if (i == 0)
		{
			OLDDate = YOUNGDate = tot;
			strcpy_s(OLD_name, name);
			strcpy_s(YOUNG_name, name);
		}

		if (tot< OLDDate)
		{
			strcpy_s(OLD_name, name);
			OLDDate = tot;
		}

		if (tot > YOUNGDate)
		{
			strcpy_s(YOUNG_name, name);
			YOUNGDate = tot;
		}
	}
	printf("%s\n", YOUNG_name);
	printf("%s\n", OLD_name);
}

