#include<stdio.h>
#include<math.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	int a[30], b[30];
	int i;
	double sum1 = 0, sum2 = 0, avg1, avg2, s1 = 0, s2 = 0, s12 = 0, t1, t2, pxy;
	printf("����������A\n");
	for (i = 0; i < 30; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("����������B\n");
	for (i = 0; i < 30; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < 30; i++)
	{
		sum1 += a[i];
		sum2 += b[i];
	}
	avg1 = sum1 / 30;
	avg2 = sum2 / 30;
	for (i = 0; i < 30; i++)
	{
		s1 += (a[i] - avg1) * (a[i] - avg1);
		s2 += (b[i] - avg2) * (b[i] - avg2);
		s12 += (a[i] - avg1) * (b[i] - avg2);
	}
	t1 = sqrt(s1/30);
	t2 = sqrt(s2/30);
	pxy = s12 / (30*t1 * t2);
	printf("��һ���׼��Ϊ��%f", t1);
	printf("�ڶ����׼��Ϊ:%f", t2);
	printf("��ϵϵ��Ϊ:%f", pxy);
}
