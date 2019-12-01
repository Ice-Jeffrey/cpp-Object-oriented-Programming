#include <iostream>
#include <cstring>
#include "Jeffrey's_stack.hpp"
//#include<stack>
#define maxsize 256
using namespace std;
typedef int Elemtype;

char ops[7] = { '+', '-', '*', '/', '(', ')', '#' }; //锟斤拷锟斤拷锟斤拷锟斤拷锟�

char cmp[7][7] = {
	{'>', '>', '<', '<', '<', '>', '>'}, //锟斤拷锟斤拷锟斤拷锟叫比斤拷锟斤拷锟斤拷锟斤拷锟斤拷燃锟斤拷木锟斤拷锟�
	{'>', '>', '<', '<', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'<', '<', '<', '<', '<', '=', '$'},
	{'>', '>', '>', '>', '$', '>', '>'},
	{'<', '<', '<', '<', '<', '$', '='} };

int GetOperator(char ch)
{
	int i;
	if (ch >= '0' && ch <= '9')
		return -1;
	else
		for (i = 0; i < 7; i++)
		{
			if (ch == ops[i])
			{
				return i;
				break;
			}
		}
	if (i == 7)
		return -2;
}

char Compare(int m, int n)
{
	char priority = cmp[m][n];
	if (priority == '$')
	{
		return '\0';
	}
	else
		return priority;
}

int Execute(int a, int op, int b)
{
	int result;
	switch (op)
	{
	case 0:
		result = a + b;
		break;
	case 1:
		result = a - b;
		break;
	case 2:
		result = a * b;
		break;
	case 3:
		result = a / b;
		break;
	}
	return result;
}

int Deduction(char s[], int len)
{
	int i;
	int t;
	int acc = 0, bcc = 0;
	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
		return 1;
	for (i = 0; i < len - 1; i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/')
				return 1;
		}
		else if (s[i] == ')')
		{
			if (s[i + 1] == '(')
				return 1;
		}
		else if (s[i] == '(')
		{
			if (s[i + 1] == ')')
				return 1;
		}
	}
	if (s[len - 1] == '+' || s[len - 1] == '-' || s[len - 1] == '*' || s[len - 1] == '/')
		return 1;
	for (i = len - 1; i >= 0; i--)
	{
		if (s[i] == ')')
			bcc++;
		else if (s[i] == '(')
			acc++;
	}
	if (acc != bcc)
	{
		return 1;
	}
	char pei[10001];
	int toppei = -1;
	i = 0;
	while (i < len)
	{
		if (s[i] == '(')
		{
			toppei++;
			pei[toppei] = s[i];
			i++;
		}
		else if (s[i] == ')' && toppei >= 0)
		{
			toppei--;
			i++;
		}
		else if (s[i] == ')' && toppei == -1)
			return 1;
		else
			i++;
	}
	if (toppei != -1)
		return 1;
	return 0;
}

int main()
{
	int result;
	char str[1024];
	while (cin.getline(str, 1024))
	{
		cout << str << endl;
		int cst, len = strlen(str);
		cst = Deduction(str, len);
		if (cst == 1)
		{
			cout << "error" << endl;
			continue;
		}
		stack<int> Num;
		stack<int> Opr;
		Opr.push(6);
		int temp = 0;
		char* ch = str;
		for (int i = 0; i <= len; i++)
		{
			if (*ch == '\0')
			{
				*ch = '#';
			}
			if (GetOperator(*ch) == -1)
			{
				while (GetOperator(*ch) == -1)
				{
					temp = temp * 10 + *ch - '0';
					ch++;
				}
				Num.push(temp);
				temp = 0;
			}
			else if (GetOperator(*ch) != -2)
			{
				char flag = Compare(Opr.top(), GetOperator(*ch));
				if (flag == '>')
				{
					while ((Compare(Opr.top(), GetOperator(*ch))) == '>')
					{
						int m, n;
						n = Num.top();
						Num.pop();
						m = Num.top();
						Num.pop();
						if (n == 0 && Opr.top() == 3)
						{
							cst = 1;
							break;
						}
						int res;
						res = Execute(m, Opr.top(), n);
						Opr.pop();
						Num.push(res);
					}
					if ((Compare(Opr.top(), GetOperator(*ch))) == '=')
					{
						Opr.pop();
						ch++;
					}
					else if ((Compare(Opr.top(), GetOperator(*ch))) == '<')
					{
						Opr.push(GetOperator(*ch));
						ch++;
					}
				}
				else if (flag == '<')
				{
					Opr.push(GetOperator(*ch));
					ch++;
				}
				else if (flag == '=')
				{
					Opr.pop();
					ch++;
				}
			}
			else
				ch++;
		}
		if (cst == 1)
		{
			cout << "error" << endl;
			continue;
		}
		result = Num.top();
		cout << result << endl;
	}
	return 0;
}