#include <stdio.h>
#define N 14
#define M 10

main()
{
	int i,j,temp=0,k,x=0,y=0,ki[N],kj[M];
	double sums=0,avgs=0,sump=0,avgp=0,s=0,p=0,Su,Sd,d,e,Pr=0,Dd;
    int D[N][M]={
    {-1,1,2,3,4,5,6,7,8,-1},
    {1,1,1,1,0,1,1,0,1,-1},
    {2,1,1,1,1,1,1,1,1,-1},
    {3,1,1,1,1,1,0,1,1,-1},
    {4,1,1,1,0,1,1,0,1,-1},
    {5,1,1,1,1,1,1,0,1,-1},
    {6,1,1,1,1,1,1,1,1,-1},
    {7,0,1,0,0,1,1,0,1,-1},
    {8,1,1,0,1,0,1,1,1,-1},
    {9,0,1,0,0,0,0,0,1,-1},
    {10,1,1,1,0,1,1,1,0,-1},
    {11,0,1,0,0,1,0,0,1,-1},
    {12,1,1,1,0,1,0,0,1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

	for(i=1;i<N-1;i++)//ÿ��ѧ���ĵ÷�
	{
		D[i][M-1]=0;
		for(j=1;j<M-1;j++)
		{
			D[i][M-1]+=D[i][j];
		}
	}
	for(j=1;j<M-1;j++)//ÿ���������������
	{
		D[N-1][j]=0;
		for(i=1;i<N-1;i++)
		{
			D[N-1][j]+=D[i][j];
		}
	}

	//����ƽ���÷�
	for(i=1;i<N-1;i++)
	{
		sums+=D[i][M-1];
	}
	avgs=sums/(N-2);
	printf("ƽ���÷�Ϊ%0.2f\n",avgs);

	//����ƽ��������
	for(j=1;j<M-1;j++)
	{
		sump+=D[N-1][j];
	}
	avgp=sump/(M-2);
	printf("ƽ��������Ϊ%0.2f\n\n",avgp);

	//���δ�任�ı�
	printf("δ�任�ı�Ϊ:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%2d  ",D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//����任��ı�
	printf("�任��ı�Ϊ:\n");
	for(j=1;j<M-2;j++)//��
	{
		for(i=1;i<N-2;i++)
		{
			if(D[i][M-1]<D[i+1][M-1])
			{
				for(k=0;k<M;k++)
                                {
					temp=D[i][k];
					D[i][k]=D[i+1][k];
					D[i+1][k]=temp;
				}
			}
		}
	}

	for(i=1;i<N-2;i++)//��
	{
		for(j=1;j<M-2;j++)
		{
			if(D[N-1][j]<D[N-1][j+1])
			{
				for(k=0;k<N;k++)
				{
					temp=D[k][j];
					D[k][j]=D[k][j+1];
					D[k][j+1]=temp;
				}
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%2d  ",D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//����ѧ��ע��ϵ��
	for(i=1;i<N-1;i++)
	{
		double suml=0,sumr=0,counts=0;
		k=D[i][M-1];
		for(j=1;j<=k;j++)
		{
			counts+=D[N-1][j];//S������������������������֮��
			if(D[i][j]==0)
				suml+=D[N-1][j];//S�������Ϊ0���������������֮��
		}
		if(k==M-2)//��һ��ȫΪ1
		{
			if(counts-D[i][M-1]*avgp==0)
			{
				printf("������%-2d��ѧ��S%-2d��ע��ϵ��C.S%-2dΪ0.00\n",i,D[i][0],D[i][0]);
				continue;
			}
			printf("������%-2d��ѧ��S%-2d��ע��ϵ��C.S%-2dΪ%0.2f\n",i,D[i][0],D[i][0],(suml-sumr)/(counts-D[i][M-1]*avgp));
			continue;
		}
		for(j=k+1;j<=M-2;j++)
		{
			if(D[i][j]==1)
				sumr+=D[N-1][j];//s�����Ҳ�Ϊ1���������������֮��
		}
		printf("������%-2d��ѧ��S%-2d��ע��ϵ��C.S%-2dΪ%0.2f\n",i,D[i][0],D[i][0],(suml-sumr)/(counts-D[i][M-1]*avgp));
	}
	printf("\n");

	//������Ŀע��ϵ��
	for(j=1;j<M-1;j++)
	{
		double sumu=0,sumd=0,countp=0;
		k=D[N-1][j];
		for(i=1;i<=k;i++)
		{
			countp+=D[i][M-1];//P����������ѧ���ĵ÷�֮��
			if(D[i][j]==0)
				sumu+=D[i][M-1];//P�����Ϸ��ش�Ϊ0��ѧ���÷�֮��
		}
		if(k==N-2)//��һ��ȫΪ1
		{
			if(countp-D[N-1][j]*avgs==0)
			{
				printf("��%-2d�������ע��ϵ��C.P%-2dΪ0.00\n",D[0][j],D[0][j]);
				continue;
			}
			printf("��%-2d�������ע��ϵ��C.P%-2dΪ%0.2f\n",D[0][j],D[0][j],(sumu-sumd)/(countp-D[N-1][j]*avgs));
			continue;
		}
		for(i=k+1;i<=N-2;i++)//P�����·��ش�Ϊ1��ѧ���÷�֮��
		{
			if(D[i][j]==1)
				sumd+=D[i][M-1];
		}

		printf("��%-2d�������ע��ϵ��C.P%-2dΪ%0.2f\n",D[0][j],D[0][j],(sumu-sumd)/(countp-D[N-1][j]*avgs));
	}
	printf("\n");

	//�������ϵ��
	for(i=1;i<N-1;i++)
	{
		for(j=1;j<M-1;j++)
		{
			ki[i]=D[i][M-1],kj[j]=D[N-1][j];
			if(ki[i]==j&&kj[j]==i-1)//���һ����P����֮��S����֮�ϵ�Ԫ�����������������
			{
				if(i>x&&j>y) x=i,y=j;//��¼���ٽ�㡱�ġ��������ꡱ
			}
		}
	}
//	printf("%d,%d\n",x,y);
	for(i=1;i<x;i++)
		s+=D[i][M-1];//8+8+7+7+6+6+6+6
	for(j=y+1;j<M-1;j++)
		p+=D[N-1][j];//8+5+5
	Su=((x-1)*(M-2)-s)-((x-1)*(M-2-y)-p);//(9*8-s)-(9*2-p)���ٽ�㡱�������
	s=0,p=0;
    printf("%0.0f\n",Su);
	for(i=x;i<N-1;i++)
		s+=D[i][M-1];//5+4+3+2
	for(j=1;j<=y;j++)
		p+=D[N-1][j];//12+11+10+9+8
	Sd=((N-2)*y-p)-((N-x-1)*y-s);//(12*6-p)-(3*6-s)���ٽ�㡱�������
    printf("%0.0f\n",Sd);

	d=(Su+Sd)/((M-2)*(N-2));//���������ʽ
	printf("������D=%0.2f\n",d);

	for(j=1;j<M-1;j++)
	{
		Pr+=D[N-1][j];
	}
	e=Pr/((M-2)*(N-2));//��������

	Dd=(0.7*d)/(e*(1-e));//�����ϵ����ʽ
	printf("����ϵ��D*=%0.2f\n\n",Dd);
}
