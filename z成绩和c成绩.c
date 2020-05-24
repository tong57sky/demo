#include<stdio.h>
#include<math.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	int a[30];
	float z[30], c[30];
	int i, suma = 0, avga = 0;
	double Sa = 0;
	printf("请输入数据：\n");
	for (i = 0; i < 30; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 30; i++)
	{
		suma += a[i];
	}
	avga = suma / 30;
	for (i = 0; i < 30; i++)
	{
		Sa += (avga - a[i]) * (avga - a[i]);
	}
	Sa = sqrt(Sa / 30);
	for (i = 0; i < 30; i++)
	{
		z[i] = (a[i] - avga) / Sa;
	}
	for (i = 0; i < 30; i++)
	{
		c[i] = 100 * z[i] + 500;
	}
	printf("z得分分别为:\n");
	for (i = 0; i < 30; i++)
	{
		printf("%0.2f", z[i]);
		printf(" ");
	}
	printf("\n");
	printf("CEEB得分分别为:\n");
	for (i = 0; i < 30; i++)
	{
		printf("%0.2f", c[i]);
		printf(" ");
	}
}