#include<iostream>
#include<stdio.h>
#include<cmath>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
#define llt long long int

bool isPrime(llt n)
{
	// Corner case 
	if (n <= 1)
		return false;

	// Check from 2 to n-1 
	for (llt i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

int CNT(llt m)
{
	int cnt = 0;
	while (m)
	{
		cnt++;
		m /= 10;
	}
	return cnt;
}

int main()
{
	char arr[256];
	string str;
	while (cin >> str)
	{
		//to store the number in arr[256];
		stringstream ss(str);
		int cnt = 0;
		while (ss >> arr[cnt])
		{
			cnt++;
		}
		arr[cnt] = '\n';

		//find largest prime
		int numOfDig = cnt;
		int mAX = 0;
		for (int i = 0; i < numOfDig; i++)
		{
			int j = i;
			int number = 0;
			while ((j < i + 5) && (j < numOfDig))
			{
				number = number * 10 + (arr[j] - '0');
				if (isPrime(number))
				{
					mAX = max(mAX, number);
				}
				j++;
			}
		}
		if (mAX != 0)
			cout << mAX << endl;
	}
}