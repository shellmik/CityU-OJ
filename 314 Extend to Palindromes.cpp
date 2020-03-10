#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string>
#include <algorithm>
using namespace std;

//Ç°×º±í
void prefix_table(string pattern, int* prefix, int n)
{
	prefix[0] = 0;
	int len = 0;
	int i = 1;
	while (i<n)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			prefix[i] = len;
			i++;//detect the next thing
		}
		else {
			if (len > 0)
			{
				len = prefix[len - 1];
			}
			else 
			{
				prefix[i] = len;
				i++;
			}
		}
	}
}

void move_prefix_table(int prefix[], int n)
{
	int i;
	for (int i = n - 1; i > 0; i--)
	{
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}

int kmp_search(string text, string pattern)
{
	int n = pattern.length();
	int m = text.length();

	//prefix table of pattern
	int* prefix = new int[n];
	prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);

	//text[i]	,len(text)	= m
	//pattern[j] , len(pattern) = n;
	int i = 0;
	int j = 0;
	while (i < m)
	{
		if (i == m - 1 && text[i] == pattern[j])
		{
			return j + 1;//append j to n-1 to the original string
		}
		if (text[i] == pattern[j])
		{
			i++; j++;
		}
		else
		{
			j = prefix[j];
			if (j == -1) {
				i++; j++;
			}
		}
	}
}

int main()
{
	string s, rev_s;
	while (cin >> s)
	{
		rev_s = s;
		reverse(rev_s.begin(), rev_s.end());
		
		int m = kmp_search(s, rev_s);
		
		s.append(rev_s.begin() + m, rev_s.end());
		cout << s << endl;
	}

}