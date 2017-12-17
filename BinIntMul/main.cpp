#include<iostream>
#include<stdio.h>
using namespace std;
char* bigplus(char*a, char*b,char*result);
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


char* bigplus(char*a, char*b,char*result) {
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
	int temp, cin = 0;
	for (int i = max(n1, n2),j = min(n1,n2),k=0;i!=0; i--) {
		temp = 0;
		if (j != 0) {
			temp = ((int)bigone[i - 1])-48 + ((int)shortone[j - 1])-48;
			j--;
		}
		else {
			temp = ((int)bigone[i - 1]) - 48;
		}
		temp += cin;
		if (temp >= 10) {
			cin = 1;
			temp -= 10;
		}
		temp += 48;
		*(result+k++) = (char)temp;
	}
	if (cin == 1)
		strcat(result,"1");
	Reverse(result);
	return result;
}

char* bigmin(char*a, char*b, char*result) {

	return result;
}