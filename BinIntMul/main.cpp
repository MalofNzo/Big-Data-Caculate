#include<iostream>
#include<stdio.h>
using namespace std;
char* bigplus(char*a, char*b, char*result);
char* bigplusUnsigned(char*a, char*b,char*result);
char* bigmin(char*a, char*b, char*result);
int main() {
	char a[100], b[100];
	char result[100];
	memset(result, '\0', 100);
	scanf("%s",&a);
	scanf("%s", &b);
	char*n= bigplus(a, b,result);
	printf("%s", result);
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
		int n1 = strlen(a), n2 = strlen(b);
		n2--;
		char*bigone, *shortone;
		bigone = a, shortone = b;
		shortone++;
		////test end//
		int temp, c_in = 0;
		for (int i = max(n1, n2), j = min(n1, n2), k = 0; i != 0; i--) {
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
	if (b[0] == '-') {
		Reverse(b);
		b[strlen(b) - 1] = '\0';
		Reverse(b);
	}
	else {
		Reverse(b);
		strcat(b, "-");
		Reverse(b);
	}
	bigplus(a, b, result);
	return result;
}