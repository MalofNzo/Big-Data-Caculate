#include<iostream>
#include<stdio.h>
using namespace std;
char* bigplus(char*a, char*b, char*result);
char* bigplusUnsigned(char*a, char*b,char*result);
char* bigmin(char*a, char*b, char*result);
char* bigmul(char*a, char*b, char*result);
char* mulbig(char* A, char* B);
void reverseOrder(char* str, int p, int q)
{
	char temp;
	while (p < q)
	{
		temp = str[p];
		str[p] = str[q];
		str[q] = temp;
		p++;
		q--;
	}
}

int main() {
	char a[100], b[100];
	char result[100];
	memset(result, '\0', 100);
	scanf("%s",&a);
	scanf("%s", &b);
	bigplus(a, b,result);
	printf("加法结果		%s", result);
	memset(result, '\0', 100);
	putchar('\n');
	bigmin(a, b, result);
	printf("减法结果		%s", result);
	memset(result, '\0', 100);
	putchar('\n');
	char*res=mulbig(a, b);
	printf("乘法结果		%s", res);
	putchar('\n');
	system("pause");
	return 0;
}

int max(int a, int b){
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

char* Reverse(char* s)
{
	char* p = s;
	char* q = s;
	while (*q)
		++q;
	q--;
	while (q > p)
	{
		char t = *p;
		*p++ = *q;
		*q-- = t;
	}
	return s;
}

char* bigplusUnsigned(char*a, char*b,char*result) {
	int n1 = strlen(a);
	int n2 = strlen(b);
	char *bigone;
	char *shortone;
	if (n1 >= n2) {
		bigone = a;
		shortone = b;
	}
	else {
		bigone = b;
		shortone = a;
	}
	int temp, c_in = 0;
	for (int i = max(n1, n2),j = min(n1,n2),k=0;i!=0; i--) {
		temp = 0;
		if (j != 0) {
			temp = ((int)bigone[i - 1])-48 + ((int)shortone[j - 1])-48;
			j--;
		}
		else {
			temp = ((int)bigone[i - 1]) - 48;
		}
		temp += c_in;
		if (temp >= 10) {
			c_in = 1;
			temp -= 10;
		}
		else {
			c_in = 0;
		}
		temp += 48;
		*(result+k++) = (char)temp;
	}
	if (c_in == 1)
		strcat(result,"1");
	Reverse(result);
	return result;
}

char* bigplus(char*a, char*b, char*result) {
	enum{pp,pm,mm};
	int flag;
	if (((a[0] == '-')&&(b[0] != '-')) || ((a[0] != '-')&&(b[0] == '-')))
		flag = pm;
	else if ((a[0] == '-')&&(b[0] == '-'))
		flag = mm;
	else
		flag = pp;
	switch (flag)
	{
	case pp:
	{
		bigplusUnsigned(a, b, result);
	}
	break;
	case pm: {
		///test :a = +,b = -
		int np, nm, n1, n2;
		int signal = 0;
		char *bigone, *shortone, *p1, *m1;
		if (a[0] == '-') {
			m1 = a;
			p1 = b;
		}
		else
		{
			m1 = b;
			p1 = a;
		}
		np = strlen(p1);
		nm = strlen(m1) - 1;
		if (np > nm) {
			bigone = p1;
			shortone = m1;
			shortone++;
			signal = 0;
		}
		else if (np < nm) {
			bigone = m1;
			bigone++;
			shortone = p1;
			signal = 1;
		}
		else
		{
			m1++;
			for (int i = 0; i < np; i++) {
				if (p1[i] > m1[i]) {
					bigone = p1;
					shortone = m1;
					signal = 0;
					break;
				}
				else if (p1[i] < m1[i]) {
					bigone = m1;
					shortone = p1;
					signal = 1;
					break;
				}
				else if (p1[np - 1] == m1[np - 1]) {
					result[0] = '0';
					return result;
				}
			}

		}
		////test end//
		int temp, c_in = 0;
		for (int i = max(np, nm), j = min(np, nm), k = 0; i != 0; i--) {
			temp = 0;
			if (j > 0) {
				if (((int)(bigone[i - 1]) - 48) - c_in >= ((int)(shortone[j - 1]) - 48)) {
					temp = ((int)(bigone[i - 1]) - 48) - ((int)(shortone[j - 1]) - 48) - c_in;
					c_in = 0;
				}
				else if (((int)(bigone[i - 1]) - 48) - c_in< ((int)(shortone[j - 1]) - 48)) {
					if (((int)(bigone[i - 1]) - 48) == 0 && c_in == 1) {
						temp = 9 - ((int)(shortone[j - 1]) - 48);
						c_in = 1;
					}
					else {
						temp = 10 - ((int)(shortone[j - 1]) - 48) + ((int)(bigone[i - 1]) - 48) - c_in;
						c_in = 1;
					}
				}
			}
			else {
				if ((int)(bigone[i - 1]) - 48 == 0 && c_in == 1) {
					temp = 9;
					c_in = 1;
				}
				else {
					temp = (int)(bigone[i - 1]) - 48 - c_in;
					c_in = 0;
				}
			}
			temp += 48;
			j--;
			*(result + k++) = (char)temp;
		}
		int k = strlen(result);
		if (*(result + --k) == '0') {
			for (; *(result + k) == '0'; k--) {
				*(result + k) = '\0';
			}
		}
		if (signal == 1)
			strcat(result, "-");
		Reverse(result);
		return result;
	}
			 break;
	case mm:
		char*f, *g;
		f = a + 1;
		g = b + 1;
		bigplusUnsigned(f, g, result);
		Reverse(result);
		strcat(result, "-");
		Reverse(result);
		break;
	}

}

char* bigmin(char*a, char*b, char*result) {
	char c[100];
	memset(c, '\0', 100);
	strcpy(c, b);
	if (c[0] == '-') {
		Reverse(c);
		c[strlen(c) - 1] = '\0';
		Reverse(c);
	}
	else {
		Reverse(c);
		strcat(c, "-");
		Reverse(c);
	}
	bigplus(a, c, result);
	return result;
}


char* mulbig(char* A, char* B)
{
	int pmflag;
	enum { pp, pm, mm };
	int flag;
	if (strcmp(A, "0") == 0)
		return "0";
	if (strcmp(B, "0") == 0)
		return "0";
	if (((A[0] == '-') && (B[0] != '-')) || ((A[0] != '-') && (B[0] == '-'))) {
		flag = -1;
		if (A[0] == '-')
			A++;
		else
			B++;
	}
	else if ((A[0] == '-') && (B[0] == '-')) {
		A++;
		B++;
		flag = 1;
	}
	else
		flag = 1;
	int m = strlen(A);
	int n = strlen(B);
	char* result = new char[m + n + 1];
	memset(result, '0', m + n);
	result[m + n] = '\0';
	reverseOrder(A, 0, m - 1);
	reverseOrder(B, 0, n - 1);

	int multiFlag; 
	int addFlag;   
	for (int i = 0; i <= n - 1; i++) 
	{
		multiFlag = 0;
		addFlag = 0;
		for (int j = 0; j <= m - 1; j++)
		{
			int temp1 = (A[j] - 48) * (B[i] - 48) + multiFlag;
			multiFlag = temp1 / 10;
			temp1 = temp1 % 10;
			int temp2 = (result[i + j] - 48) + temp1 + addFlag;
			addFlag = temp2 / 10;
			result[i + j] = temp2 % 10 + 48;
		}
		result[i + m] += multiFlag + addFlag;
	}
	reverseOrder(result, 0, m + n - 1); 
	if (result[0] == '0')
		result++;
	if (flag == -1) {
		result--;
		result[0] = '-';
	}
	return result;
}