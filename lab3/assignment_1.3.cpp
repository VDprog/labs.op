#include <iostream>
#include <string>
#include <math.h>
#include "stack_array.h"

using namespace std;

int getPriority(char c)
{
	switch(c)
	{
		case '(':
			return 0;
		case '+':
			return 1;
		case '-':
			return 1;
		case ')':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '@':
			return 2;
		case '^':
			return 3;
		////////////
		case '!':
			return 4;
	}
	return 0;
}
string ShuntingYard(string &Input)
{
	string Output = "";
	Stack<char> operators;
	char lastOperator = '(';

	for (int i = 0; i < Input.size(); i++)
	{
		if (Input[i] == ' ')
			continue;
		if (isdigit(Input[i]))
		{
			if (!isdigit(Input[i + 1]))
			{
				Output.push_back(Input[i]);
				Output.push_back(' ');
			}
			else
				Output.push_back(Input[i]);
			continue;
		}
		if (Input[i] == ')')
		{
			operators.top(lastOperator);
			while (lastOperator != '(')
			{
				operators.pop(lastOperator);
				Output += lastOperator;
				operators.top(lastOperator);
			}
			operators.pop(lastOperator);
			continue;
		}
		if (Input[i] == '^' || Input[i] == '(')
			operators.push(Input[i]);
		else
		{
			if (Input[i] == '-')
			{
				lastOperator = Input[i - 1];
				if (lastOperator == ' ')
					lastOperator = Input[i - 2];
				if (!isdigit(lastOperator))
					Input[i] = '@';
			}
			operators.top(lastOperator);
			while (getPriority(Input[i]) <= getPriority(lastOperator) && operators.pop(lastOperator))
			{
				Output.push_back(lastOperator);
				operators.top(lastOperator);
			}
			operators.push(Input[i]);
		}
	}
	while (operators.pop(lastOperator))
	{
		Output.push_back(lastOperator);
	}
	return Output;
}

int calculate(int first, int sec, char oper) {
	switch (oper) {
	case '+':
		return first + sec;
	case '-':
		return first - sec;
	case '*':
		return first * sec;
	case '/':
		return first / sec;
	case '^':
		return pow(first,sec);
	}
}

int factotial(int n)
{
	if (n <= 1)
		return 1;
	return factotial(n - 1) * n;
}

int Find_Result(string out) {
	int result,first,second;
	Stack<int> numbers;
	size_t pos;
	for (; out.length() > 0;) {
		if (isdigit(out.front())) {
			numbers.push(stoi(out, &pos));
			out.erase(0, pos + 1);
		}
		else { 
			if (out.at(0) == '@') {
				numbers.pop(result);
				result *= -1;
				numbers.push(result);
			}
			else if (out.at(0) == '!')
			{
				numbers.pop(result);
				result = factotial(result);
				// cout << "! > " << result << endl;
				numbers.push(result);
			}
			else {
				numbers.pop(second);
				numbers.pop(first);
				result = calculate(first,second,out.at(0));
				numbers.push(result);
			}
			out.erase(0, 1);
		}
	}
	return result;
}

int main(int argc, char const *argv[]) {
	string str;
	for (int i = 1; i < argc; i++) {
		str.append(argv[i]);
	}
	str = ShuntingYard(str);
	cout << str << endl;
	cout << "Result: " << Find_Result(str) << endl;
	// system("pause");
	return 0;
}
