#include "pch.h"
#include "string.h"
#include "stack"
#include <iostream>
using namespace std;

bool boolFormula(const char* expr)
{
	stack<char> s1, s2;
	int i = 0;
	int n = strlen(expr);
	char c,x,y,z;
	while (i < n)
	{
		if (expr[i] == 't' || expr[i] == 'f')
		{
			s1.push(expr[i]);
		}
		else if (expr[i] == '*' || expr[i] == '+' || expr[i]=='~' || expr[i] == '(')
		{
			s2.push(expr[i]);
		}
		if (expr[i] == ')')
		{
			c=s2.top();
			s2.pop();
			switch (c)
			{
				case'~': 
					x=s1.top();
					s1.pop();
					if (x == 't') z = 'f';
					else z = 't';
					s1.push(z);
					break;
				case '*':
					x = s1.top();
					s1.pop();
					y = s1.top();
					s1.pop();
					if (x == 't'&&y == 't') z = 't';
					else z = 'f';
					s1.push(z);
					break;
				case '+':
					x = s1.top();
					s1.pop();
					y = s1.top();
					s1.pop();
					if (x == 'f'&&y == 'f') z = 'f';
					else z = 't';
					s1.push(z);
					break;
				case '(':
					x = s1.top();
					s1.pop();
			}
		}
		i++;
	}
	c = s1.top();
	s1.pop();
	return c == 't';
}
int main()
{
	cout << boolalpha << boolFormula("(((~f)+t)*f)") << endl;


}