#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	char a[100];
	int N=0,T=0,g=0;
	int i;
	float rt,ch;
	printf("请输入自定义S-T序列\n");
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
	printf("教学模式为：练习型\n");
	else if(rt>=0.7&&ch<0.4)
	printf("教学模式为：讲授型\n");
	else if(rt>0.3&&rt<0.7&&ch>=0.4) 
	printf("教学模式为：对话型\n");
	else if(rt>0.3&&rt<0.7&&ch<0.4)
	printf("教学模式为：混合型\n");
	else
	printf("未知类型\n"); 
}
