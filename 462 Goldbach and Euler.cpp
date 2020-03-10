#include<iostream>
#include<stdio.h>
#include<cmath>
#include<sstream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 10001;
bool prime[N];
vector<int> pl;

void determinePrimes()
{
	memset(prime, true, sizeof(prime));
	prime[1] = false;

	for (int p = 2; p*p < N; p++)
	{
		if (prime[p])
		{
			for (int i = p*p; i < N; i+=p)
			{
				prime[i] = false;
			}
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (prime[i])
		{
			pl.push_back(i);
		}
	}
}

bool isPrime(int n)
{
	if (n <= 10000)
		return prime[n];
	else if ((n & 1) == 0) 
		return 0;
	else
	{
		int sr = (int)sqrt((double)n);
		int sp = pl.size();
		for (int i = 0; i < sp && pl[i]<=sr ; i++)
		{
			if (n % pl[i] == 0)
				return false;
		}
		return true;
	}
}

void testok(int n)
{

	if (n < 5)
		printf("%d is not the sum of two primes!\n", n);
	else if (n % 2 != 0)
	{
		if (isPrime(n - 2))
			printf("%d is the sum of %d and %d.\n", n, 2, n - 2);
		else
			printf("%d is not the sum of two primes!\n", n);
	}
	else
	{
		int mid = n / 2 - 1;
		for (int i = mid; i > 0; i--)
		{
			if (isPrime(i) && isPrime(n - i))
			{
				printf("%d is the sum of %d and %d.\n", n, i, n - i);
				return;
			}
		}
		printf("%d is not the sum of two primes!\n", n);
	}
}


int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	
	determinePrimes();
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		testok(n);
	}

}