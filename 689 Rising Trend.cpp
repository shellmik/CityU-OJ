#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int d[1000005];
int stocks[1000005];

int binarysearch(int n, int target)
{
	int low = 0, high = n, middle = 0;
	while (low < high)
	{
		middle = (low + high) / 2;
		if (d[middle]>target&&d[middle-1]<=target){
			return middle;
		}
		else if (d[middle-1]>target) {
			high = middle;
		}
		else if (d[middle] <= target){
			low = middle + 1;
		}
	}
}

int main()
{
	int N;

	while (cin >> N)
	{
		memset(d, 0, sizeof(d));
		memset(d, 0, sizeof(stocks));

		for (size_t i = 0; i < N; i++)
		{
			cin >> stocks[i];
		}

		int pos = 0;
		d[pos] = stocks[0];
		for (int i = 1; i < N; i++)
		{
			if (stocks[i] >= d[pos])
			{
				pos++;
				d[pos] = stocks[i];
			}
			else
			{
				int insert_pos = binarysearch(pos + 1, stocks[i]);
				d[insert_pos] = stocks[i];
			}
		} 
		cout << pos+1 << endl;
	}
}

/*
int pos;
for (int j = 0; j <len ; j++)
{
	if (stocks[i] < d[j])
	{
		pos = j;
		break;
	}
}
d[pos] = stocks[i];
*/