#include<stdio.h>
#include<string.h>
#include<stack>
#include<map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	scanf_s("%d", &N);
	getchar();
	getchar();
	//define priorities
	map<char, int> M;
	M['('] = M[')'] = 1;
	M['+'] = M['-'] = 2;
	M['*'] = M['/'] = 3;

	for (int i = 0; i < N; i++)
	{
		char str[51];
		memset(str, NULL, 51);
		int idx = 0;

		//infix to postfix
		char c;
		string s;
		stack<char> S;
		while (getline(cin, s))
		{
			if (s.length() == 0) { break; }
			else
			{
				c = s[0];
			}
			if (c >= '0' && c <= '9')
			{
				str[idx] = c;
				idx++;
			}
			else if (c == '(')
			{
				S.push(c);
			}
			else if (c == ')')
			{
				while (S.top() != '(')
				{
					str[idx] = S.top();
					idx++;
					S.pop();
				}
				S.pop();
			}
			else
			{
				if (S.empty() || M[S.top()] < M[c])
				{
					S.push(c);
				}
				else if (M[S.top()] >= M[c])
				{ 
					while (!S.empty() && M[S.top()] >= M[c])
					{
						str[idx] = S.top();
						idx++;
						S.pop();
					}
					S.push(c);
				}
			}
		}
		while (!S.empty())
		{
			if (S.top() != '(')
			{
				str[idx] = S.top();
				idx++;
			}
			S.pop();
		}
		str[idx] = '\0';
		printf("%s\n", str);
		if (i != N - 1)
			printf("\n");
	}
}