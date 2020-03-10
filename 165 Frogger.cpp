#include <cstring>
#include <cstdio>
#include <cmath>

double x[202], y[202];
double dist[202][202];

int main()
{
	int n, t = 1;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf", &x[i], &y[i]);

		//fill in the array
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j) 
			{//calculate distance compared to previous stones
				dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				dist[j][i] = dist[i][j];
			}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) 
				{
					double max = dist[i][k] > dist[k][j] ? dist[i][k] : dist[k][j];
					if (dist[i][j] > max)
						dist[i][j] = max;
				}

		printf("Scenario #%d\n", t++);
		printf("Frog Distance = %.3lf\n\n", dist[0][1]);
	}
	return 0;
}