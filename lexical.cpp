#include <iostream>
#include <string>
using namespace std;

//(3) 0  92+data>  0x3f  00  while then do if else data include;
char charac[100];
string token = "";
char ch = '\0';
int result;
int index = 0;
string savechar[] = { "if", "then", "while", "do", "else", "end"};

int scan(){
	if (ch == '\0' || ch == ' ') {
		do {
			ch = charac[index++];
		} while (ch == ' '); //去除空格
	}
	token = "";
	result = 0;
	 //判断为疑似数字类型的字符
	if (ch >= '0' && ch <= '9') {
		if (ch == '0') {//疑似十六或者八进制处理程序
			token = token + ch;
			ch = charac[index++];
			if (ch == 'x' || ch == 'X') {//疑似十六进制处理程序
				token = token + ch;
				ch = charac[index++];
				if (!((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f') || (ch >= 'A'&&ch <= 'F'))) {
					result = 0;
					return 1;
				}
				while ((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f') || (ch >= 'A'&&ch <= 'F')) {
					token = token + ch;
					ch = charac[index++];
				}
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ') {
					result = 16;
				} else if (ch == '.') {
					token = token + ch;
					ch = charac[index++];
					if (!((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f') || (ch >= 'A'&&ch <= 'F'))) {
						result = 0;
						return 1;//****
					}
					while ((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f') || (ch >= 'A'&&ch <= 'F')) {
						token = token + ch;
						ch = charac[index++];
					}

					if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ') {
						result = 16;
					} else {
						result = 0;
						return 1;
					}
				} else {
					result = 0;
					return 1;
				}
			} else if ((ch >= '0' && ch <= '7')) {//疑似八进制处理程序
				token = token + ch;
				ch = charac[index++];

				while ((ch >= '0' && ch <= '7')) {
					token = token + ch;
					ch = charac[index++];
				}

				if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ') {
					result = 8;

				} else if (ch == '.') {
					token = token + ch;
					ch = charac[index++];
					if (!(ch >= '0' && ch <= '7')) {
						result = 0;
						return 1;//****
					}
					
					while ((ch >= '0' && ch <= '7')) {
						token = token + ch;
						ch = charac[index++];
					}
					
					if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ') {
						result = 8;
					} else {
						result = 0;
						return 1;
					}
				} else {
					result = 0;
					return 1;
				}
			} else {//其他情况处理 
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ')
				{
					result = 10;
				}
				else {
					result = 0;
				}
			}
		} else {//疑似十进制数处理
			token = token + ch;
			ch = charac[index++];
			while ((ch >= '0' && ch <= '9')) {
				token = token + ch;
				ch = charac[index++];
			}

			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ') {
				result = 10;
			} else if (ch == '.') {
				ch = charac[index++];
				if (!(ch >= '0' && ch <= '9')) {
					result = 0;
					return 1;//****
				}
				while ((ch >= '0' && ch <= '9')) {
					token = token + ch;
					ch = charac[index++];
				}
				if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == ')' || ch == ' ') {
					result = 10;
				} else {
					result = 0;
					return 1;
				}
			} else {
				result = 0;
				return 1;
			}
		}
	} else if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) { //疑似标识符处理程序
		token = token + ch;
		ch = charac[index++];
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
			token = token + ch;
			ch = charac[index++];
		}

		if (ch == '.' || ch == '_') {
			token = token + ch;
			ch = charac[index++];
			if (!((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))) {
				result = 0;
				return 1;
			}
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
				token = token + ch;
				ch = charac[index++];
			}
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == '(' || ch == ')' || ch == ' ' || ch == ';') {
				result = 7;
				return 0;
			}
		} else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == '(' || ch == ')' || ch == ' ' || ch == ';') {
			
			for (int i = 0; i < (int)(sizeof(savechar) / sizeof(savechar[0])); i++) {
				if (token == savechar[i]) {
					result = 6;
					return 0;
				}
			}
			result = 7;
			return 0;
		}
	} else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '=' || ch == '(' || ch == ')') {//系统保留字符处理程序
		token = token + ch;
		ch = charac[index++];
		result = 6;
		return 0;
	}

	else if (ch == ';')
	{
		result = 5;
		return 0;
	}

	else//其他情况处理程序
	{
		result = 0;
		return 1;
	}
	return 0;
}

// int main(int argc, char const *argv[]) {
// 	/* code */
// 	return 0;
// }

int main(){

	/*
	 * HEX
	 */

	char ch;
	int len = 0;
	cout << "please input code:" << endl;
	do {
		cin.get(ch);
		charac[len++] = ch;
	} while (ch != ';');

	do {
		scan();
		switch (result) {
		case 16:
			cout << "HEX:" << token << endl;
			break;

		case 10:
			cout << "DEC:" << token << endl;
			break;

		case 8:
			cout << "OCT:" << token << endl;
			break;

		case 7:
			cout << "TAG:" << token << endl;
			break;

		case 6:
			cout << "_:" << token << endl;
			break;

		case 5:
			getchar();
			getchar();
			return 0;

		case 0:
			cout << "error" << endl;
			break;
		}
	} while (result != 0);

	getchar();
	getchar();

	return 0;
}
