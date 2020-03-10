#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
#define llt long long int

int main()
{
	llt a, b;
	char op;
	string str;
	while (getline(cin, str))
	{
		stringstream ss(str);
		ss >> a >> op >> b;
		if (op == '+')
			cout << a + b << endl;
		else
			cout << a - b << endl;
	}
}