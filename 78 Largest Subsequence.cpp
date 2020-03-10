#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	int N;
	cin >> N;
	cin.get();

	stack<char> s;
	while (N>0)
	{
		char curr;
		while (scanf_s("%c", &curr) != EOF && curr != '\n')
		{
			if (s.empty())
			{
				s.push(curr);
				continue;
			}

			while (!s.empty()&& curr > s.top())
			{
				s.pop();
			}
			s.push(curr);
		}

		string str = "";
		while (!s.empty())
		{
			str.push_back(s.top());
			s.pop();
		}
		
		reverse(str.begin(), str.end());
		cout << str;

		if (N != 0)
		{
			cout << endl;
		}
		N--;
	}
}
