#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

const int maxsize = 256;
typedef int Elemtype;

//定义表达式求值运算中需要的操作符
char ops[7] = { '+', '-', '*', '/', '(', ')', '#' };

//定义运算符优先级表
char cmp[7][7] = {
	{'>', '>', '<', '<', '<', '>', '>'}, 
	{'>', '>', '<', '<', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'<', '<', '<', '<', '<', '=', '$'},
	{'>', '>', '>', '>', '$', '>', '>'},
	{'<', '<', '<', '<', '<', '$', '='} };

//获取当前的操作符
int GetOperator(char ch) {
	int i;
	if (ch >= '0' && ch <= '9')
		return -1;
	else
		for (i = 0; i < 7; i++) {
			if (ch == ops[i]) {
				return i;
				break;
			}
		}
	if (i == 7)
		return -2;
}

//比较两个操作符运算优先级的大小
char Compare(int m, int n) {
	char priority = cmp[m][n];
	if (priority == '$') {
		return '\0';
	}
	else
		return priority;
}

//执行操作，得到二元运算结果
int Execute(int a, int op, int b) {
	int result;
	switch (op) {
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

//输入表达式判断是否合法
int Deduction(char s[], int len) {
	int i;
	int t;
	int acc = 0, bcc = 0;
	
	//第一个字符是运算符，不合法，返回1
	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
		return 1;

	for (i = 0; i < len - 1; i++) {
		//连续两个字符是运算符，不合法
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/')
				return 1;
		}
		//出现两个括号中间无连接，不合法
		else if (s[i] == ')') {
			if (s[i + 1] == '(')
				return 1;
		}
		//括号内部无任何表达式，不合法
		else if (s[i] == '(')
		{
			if (s[i + 1] == ')')
				return 1;
		}
	}

	//表达式最后一个字符为一个符号，不合法
	if (s[len - 1] == '+' || s[len - 1] == '-' || s[len - 1] == '*' || s[len - 1] == '/')
		return 1;

	//判断表达式括号是否匹配
	stack<int> brackets;
	for(int i=0; s[i] != '\0'; i++) {
		if (s[i] == '(')
			brackets.push(1);
		else if (s[i] == ')' && !brackets.empty())
			brackets.pop();
		else if (s[i] == ')' && brackets.empty())
			return 1;
	}
	if (!brackets.empty())
		return 1;

	//无不合法现象，返回0，表示合法
	return 0;
}

int main()
{
	int result;	//代表计算出的结果
	char str[1024];
	while (cin.getline(str, 1024)) {
		if (!strcmp("End", str))
			break;

		cout << str << " = ";
		int cst, len = strlen(str);

		//判断表达式是否合法
		cst = Deduction(str, len);
		if (cst == 1) {
			cout << "error" << endl;
			continue;
		}

		//初始化操作数栈和操作符栈
		stack<int> Num;
		stack<int> Opr;
		Opr.push(6);

		//temp存放临时结果
		int temp = 0;
		char* ch = str;
		for (int i = 0; i <= len; i++)
		{
			//为字符串终结标志
			if (*ch == '\0') {
				*ch = '#';
			}
			//代表当前字符为一数字
			if (GetOperator(*ch) == -1)
			{
				while (GetOperator(*ch) == -1) {
					temp = temp * 10 + *ch - '0';
					ch++;
				}
				Num.push(temp);
				temp = 0;
			}
			//代表当前字符为操作符
			else if (GetOperator(*ch) != -2)
			{
				//比较当前操作符与栈顶操作符的优先级大小
				char flag = Compare(Opr.top(), GetOperator(*ch));
				//栈顶操作符优先级大
				if (flag == '>') {
					//将当前优先级大的运算全部计算完，简化栈结构
					while ((Compare(Opr.top(), GetOperator(*ch))) == '>') {
						int m, n;
						n = Num.top();
						Num.pop();
						m = Num.top();
						Num.pop();
						//除数为0时不合法
						if (n == 0 && Opr.top() == 3) {
							cst = 1;
							break;
						}
						//执行生成结果
						int res;
						res = Execute(m, Opr.top(), n);
						Opr.pop();
						Num.push(res);
					}
					//简化后栈顶符号与当前操作符优先级相等，说明为一括号匹配，左括号出栈
					if ((Compare(Opr.top(), GetOperator(*ch))) == '=') {
						Opr.pop();
						ch++;
					}
					//当前操作符优先级大，当前操作符入栈
					else if ((Compare(Opr.top(), GetOperator(*ch))) == '<') {
						Opr.push(GetOperator(*ch));
						ch++;
					}
				}
				//栈顶操作符优先级较小，将当前操作符入栈
				else if (flag == '<') {
					Opr.push(GetOperator(*ch));
					ch++;
				}
				//两者优先级相等，说明为括号匹配，将左括号出栈
				else if (flag == '=') {
					Opr.pop();
					ch++;
				}
			}
			//既不为数字也不为字符串
			else {
				//为空格，到下一字符串
				if (*ch == ' ')
					ch++;
				else {
					cst = 1;
					break;
				}
			}
		}

		if (cst == 1) {
			cout << "error" << endl;
			continue;
		}
		result = Num.top();
		cout << result << endl;
	}
	return 0;
}