#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	int N;
	cin >> N;
	int idx = 0;
	string blankline;
	getline(cin, blankline);

	while (N)
	{
		if (idx!=0)
		{
			getline(cin, blankline);
		}

		int n;
		cin >> n;

		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			string str;
			getline(cin, str);
			
			string tmp;
			stringstream ss(str);
			while (ss >> tmp)
			{
				if(idx!=0)
					cout<<"-";
				cout << tmp ;
				idx++;
			}
		}

		if (N != 1)
			printf("\n");
		printf("\n");
		N--;
		idx++;
	}
}