#include<stdio.h>
#include<string.h>
#include<stack>
#include<map>
#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;

int convertDtoDec(char c)
{
	if (c >= 'A' && c <= 'F')
	{
		return c - 'A' + 10;
	}
	else
	{
		return c - '0';
	}
}

string convertDtoHex(int c)
{
	string digit[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
		"A", "B", "C", "D", "E", "F" };
	return digit[c];
}

string decToHex(int m)
{
	string str = "";
	if (m == 0)
	{
		str = "0";
	}

	while (m)
	{
		int num = m % 16;
		string character = convertDtoHex(num);
		str.insert(0, character);
		m /= 16;
	}
	return str;
}

int main()
{
	string str;	
	map<char, int> M;
	M['('] = M[')'] = 1;
	M['+'] = 2;
	M['*'] = 3;
	while (getline(cin, str))
	{
		stringstream ss(str);
		stack<int> s1;//operands
		stack<char> s2;//operators
		char c;
		int ans = 0;

		//Processing
		while (ss >> c)
		{
			if (c == '*' || c == '+')
			{
				if (s2.empty() || M[s2.top()] < M[c])
				{
					s2.push(c);
				}
				else if (M[s2.top()]>=M[c])
				{
					while ((!s2.empty()) && M[s2.top()] >= M[c])
					{
						int op1 = s1.top();
						s1.pop();
						int op2 = s1.top();
						s1.pop();
						char c_temp = s2.top();
						s2.pop();

						if (c_temp == '*')
							s1.push(op1 * op2);
						else
							s1.push(op1 + op2);
					}
					s2.push(c);
				}
			}
			else if (c == '(')
			{
				s2.push(c);
			}
			else if (c == ')')
			{
				while (s2.top() != '(')
				{
					int op1 = s1.top();
					s1.pop();
					int op2 = s1.top();
					s1.pop();
					char c_temp = s2.top();
					s2.pop();

					if (c_temp == '*')
						s1.push(op1 * op2);
					else
						s1.push(op1 + op2);
				}
				s2.pop();
			}
			else
			{
				int d = convertDtoDec(c);
				s1.push(d);
			}
		}
		while (!s2.empty())
		{
			if (s2.top() != '(')
			{
				int op1 = s1.top();
				s1.pop();
				int op2 = s1.top();
				s1.pop();
				char c_temp = s2.top();
				if (c_temp == '*')
					s1.push(op1 * op2);
				else
					s1.push(op1 + op2);
			}
			s2.pop();
		}

		if (!s1.empty())
		{
			ans = s1.top();
			//cout << ans << endl;
			cout << decToHex(ans) << endl;
		}
	}
}