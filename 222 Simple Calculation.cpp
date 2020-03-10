#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
#define sd double
 
int main()
{
	string str;
	int idx = 0;
	while (getline(cin, str))
	{
		if (idx != 0)
			printf("\n");

		stringstream ss(str);
		
		double tmp;
		double sum = 0;
		while (ss >> tmp)
		{
			sum += tmp;
		}

		int ans = round(sum * 10000);

		printf("%.4lf\n", double(ans)/10000.0);
		idx++;
	}

}
