#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <stdio.h>
using namespace std;

//打印从1到最大的n位数
//注意点：大数问题

bool Increment(char *number) {
	bool isOverflow = false;  //判断最高位是否还向前进位
	int nTakeOver = 0;		  //进位
	int len = strlen(number); 
	for (int i = len - 1; i >= 0; --i) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == len - 1)
			++nSum;

		if (nSum >= 10) {
			if (i == 0)
				isOverflow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else {
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char *number) {
	bool isBeginning0 = true;
	int len = strlen(number);

	for (int i = 0; i < len; ++i) {
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\n");
}

void PrintMaxNDigits(int n) {
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[]number;
}

int main() {
	int n = 0;
	cin >> n;
	PrintMaxNDigits(n);
	system("pause");
	return 0;
}