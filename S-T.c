#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	char a[100];
	int N=0,T=0,g=0;
	int i;
	float rt,ch;
	printf("�������Զ���S-T����\n");
	scanf("%s",a);
	N=strlen(a);
	for(i=0;i<10;i++)
	{
		if(a[i]=='T')
		{
			T++;
		}
		if(a[i]!=a[i+1])
		{
			g++;
		}
	}
	rt=(float)T/N;
	ch=(float)(g-1)/N;
	printf("rt=%.2f ch=%.2f\n",rt,ch);
	if(rt<=0.3&&ch<0.4)
	printf("��ѧģʽΪ����ϰ��\n");
	else if(rt>=0.7&&ch<0.4)
	printf("��ѧģʽΪ��������\n");
	else if(rt>0.3&&rt<0.7&&ch>=0.4) 
	printf("��ѧģʽΪ���Ի���\n");
	else if(rt>0.3&&rt<0.7&&ch<0.4)
	printf("��ѧģʽΪ�������\n");
	else
	printf("δ֪����\n"); 
}
