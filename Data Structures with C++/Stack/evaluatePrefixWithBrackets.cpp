#include "pch.h"
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

double calculate(const string& input)
{
	istringstream str(input);
	stack<int> numbers;
	stack<char> operators;
	stack<char> brackets;

	char symbol;
	int num;

	while (!str.eof())
	{
		int peek = str.peek();

		if (peek == '+' || peek == '*')
		{
			str >> symbol;
			operators.push(symbol);
		}
		else if (peek == '(')
		{
			str.ignore();
			brackets.push(peek);
		}
		else if (peek >= '0'&&peek <= '9')
		{
			str >> num;
			numbers.push(num);
			brackets.push('\0');
		}
		else if (peek == ')')
		{	
			str.ignore();
			double result;
			if (operators.top() == '+') result = 0;
			else if (operators.top() == '*') result = 1;
			while (brackets.top()!='('&&!brackets.empty())
			{	
				brackets.pop();
				if (operators.top() == '*') result = result * numbers.top();
				else if (operators.top() == '+') result = result + numbers.top();
				numbers.pop();
			}
			operators.pop();
			numbers.push(result);
			brackets.pop();
			brackets.push('\0');
		}
		else str.ignore();
	}
	return numbers.top();
}

int main(int argc, char const *argv[])
{
	std::string input = "+(*(2,3), 4 , +(4,5,6))";
	std::cout << calculate(input) << std::endl;

	return 0;
}