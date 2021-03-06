#include "pch.h"
#include<stack>
#include<string>
#include <iostream>
using namespace std;

int value(char* s)
{
	int x, y, z;
	stack<int> help;
	int n = strlen(s), i = 0;

	while (i < n)
	{
		if (s[i] >= '0'&&s[i] <= '9' || s[i] >= 'a'&&s[i] <= 'z')
		{
			help.push(s[i]-'0');
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			x = help.top();
			help.pop();
			y = help.top();
			help.pop();
			switch (s[i])
			{
				case '+': z = x + y;
				case '-': z = y - x;
				case '*': z = x * y;
				case '/':z = y / x;
				case '^':z = pow(y, x);
			}
			help.push(z);
		}
		i++;
	}
	z = help.top();
	help.pop();
	return z;
}

int main()
{

}