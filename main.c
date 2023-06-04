#pragma warning(disable : 6031)
#include <stdio.h>

char c_Array[3][3];
int n_Array[3][3] = { 0 };

int showArray() {
	printf("\n■■■■■■■■■■■■■■■■■■\n");
	for (int i = 0; i < 3; i++)
	{
		printf("■\n");
		printf("■\n");
		printf("■");
		for (int j = 0; j < 3; j++)
		{
			printf("%8c", c_Array[i][j]);
		}
		printf("        ■\n■\n■\n■\n");
	}
	printf("■■■■■■■■■■■■■■■■■■\n\n\n\n\n\n\n\n");

	/*
	■■■■■■■■■■■■■■■■■■■
	■			■			■		    ■
	■			■			■		    ■
	■			■			■		    ■
	■			■			■		    ■
	■■■■■■■■■■■■■■■■■■■
	■			■			■		    ■
	■			■			■		    ■
	■			■			■		    ■
	■			■			■		    ■
	■■■■■■■■■■■■■■■■■■■
	■			■			■		    ■
	■			■			■		    ■
	■			■			■		    ■
	■			■			■		    ■
	■■■■■■■■■■■■■■■■■■■
	*/

}

void initArray() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c_Array[i][j] = '_';
		}
	}
}

int checkLine(char t) {
	int c = 0, l = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (c_Array[j][i] == t)
			{
				c++;
				if (c >= 3) {
					printf("%c 승!!", t);
					return 0;
				}
			}
			if (c_Array[i][j] == t)
			{
				l++;
				if (l >= 3) {
					printf("%c 승!!", t);
					return 0;
				}
			}
		}
	}

	c = 0, l = 0;
	for (int i = 0; i < 3; i++)
	{
		if (c_Array[i][i] == t)
		{
			c++;
			if (c >= 3) {
				printf("%c 승!!", t);
				return 0;
			}
		}

		if (c_Array[2 - i][i] == t)
		{
			l++;
			if (l >= 3) {
				printf("%c 승!!", t);
				return 0;
			}
		}
	}

	return 0;
}

void InputPos(int n) {
	int x, y;
	scanf("%d %d", &y, &x);
	x = 3 - x;
	y--;

	if (n_Array[x][y] == 0)
	{
		n_Array[x][y] = 1;
		if (n % 2 == 0)
		{
			c_Array[x][y] = 'X';
		}
		else
		{
			c_Array[x][y] = 'Y';
		}
	}
	else
	{
		printf("거기 이미 있음\n\n\n");
		InputPos(n);
	}
}

int main() {
	initArray();

	for (int i = 1; i <= 9; i++)
	{
		showArray();
		InputPos(i);
		checkLine('X');
		checkLine('Y');
	}

	return 0;
}