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

	for(i=1;i<N-1;i++)//每个学生的得分
	{
		D[i][M-1]=0;
		for(j=1;j<M-1;j++)
		{
			D[i][M-1]+=D[i][j];
		}
	}
	for(j=1;j<M-1;j++)//每个问题的正答人数
	{
		D[N-1][j]=0;
		for(i=1;i<N-1;i++)
		{
			D[N-1][j]+=D[i][j];
		}
	}

	//计算平均得分
	for(i=1;i<N-1;i++)
	{
		sums+=D[i][M-1];
	}
	avgs=sums/(N-2);
	printf("平均得分为%0.2f\n",avgs);

	//计算平均正答数
	for(j=1;j<M-1;j++)
	{
		sump+=D[N-1][j];
	}
	avgp=sump/(M-2);
	printf("平均正答数为%0.2f\n\n",avgp);

	//输出未变换的表
	printf("未变换的表为:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%2d  ",D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//输出变换后的表
	printf("变换后的表为:\n");
	for(j=1;j<M-2;j++)//行
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

	for(i=1;i<N-2;i++)//列
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

	//计算学生注意系数
	for(i=1;i<N-1;i++)
	{
		double suml=0,sumr=0,counts=0;
		k=D[i][M-1];
		for(j=1;j<=k;j++)
		{
			counts+=D[N-1][j];//S曲线左侧所有问题的正答人数之和
			if(D[i][j]==0)
				suml+=D[N-1][j];//S曲线左侧为0的问题的正答人数之和
		}
		if(k==M-2)//这一行全为1
		{
			if(counts-D[i][M-1]*avgp==0)
			{
				printf("排名第%-2d的学生S%-2d的注意系数C.S%-2d为0.00\n",i,D[i][0],D[i][0]);
				continue;
			}
			printf("排名第%-2d的学生S%-2d的注意系数C.S%-2d为%0.2f\n",i,D[i][0],D[i][0],(suml-sumr)/(counts-D[i][M-1]*avgp));
			continue;
		}
		for(j=k+1;j<=M-2;j++)
		{
			if(D[i][j]==1)
				sumr+=D[N-1][j];//s曲线右侧为1的问题的正答人数之和
		}
		printf("排名第%-2d的学生S%-2d的注意系数C.S%-2d为%0.2f\n",i,D[i][0],D[i][0],(suml-sumr)/(counts-D[i][M-1]*avgp));
	}
	printf("\n");

	//计算题目注意系数
	for(j=1;j<M-1;j++)
	{
		double sumu=0,sumd=0,countp=0;
		k=D[N-1][j];
		for(i=1;i<=k;i++)
		{
			countp+=D[i][M-1];//P曲线上所有学生的得分之和
			if(D[i][j]==0)
				sumu+=D[i][M-1];//P曲线上方回答为0的学生得分之和
		}
		if(k==N-2)//这一列全为1
		{
			if(countp-D[N-1][j]*avgs==0)
			{
				printf("第%-2d个问题的注意系数C.P%-2d为0.00\n",D[0][j],D[0][j]);
				continue;
			}
			printf("第%-2d个问题的注意系数C.P%-2d为%0.2f\n",D[0][j],D[0][j],(sumu-sumd)/(countp-D[N-1][j]*avgs));
			continue;
		}
		for(i=k+1;i<=N-2;i++)//P曲线下方回答为1的学生得分之和
		{
			if(D[i][j]==1)
				sumd+=D[i][M-1];
		}

		printf("第%-2d个问题的注意系数C.P%-2d为%0.2f\n",D[0][j],D[0][j],(sumu-sumd)/(countp-D[N-1][j]*avgs));
	}
	printf("\n");

	//计算差异系数
	for(i=1;i<N-1;i++)
	{
		for(j=1;j<M-1;j++)
		{
			ki[i]=D[i][M-1],kj[j]=D[N-1][j];
			if(ki[i]==j&&kj[j]==i-1)//最后一个在P曲线之下S曲线之上的元素所必须满足的条件
			{
				if(i>x&&j>y) x=i,y=j;//记录“临界点”的“横纵坐标”
			}
		}
	}
//	printf("%d,%d\n",x,y);
	for(i=1;i<x;i++)
		s+=D[i][M-1];//8+8+7+7+6+6+6+6
	for(j=y+1;j<M-1;j++)
		p+=D[N-1][j];//8+5+5
	Su=((x-1)*(M-2)-s)-((x-1)*(M-2-y)-p);//(9*8-s)-(9*2-p)“临界点”以上面积
	s=0,p=0;
    printf("%0.0f\n",Su);
	for(i=x;i<N-1;i++)
		s+=D[i][M-1];//5+4+3+2
	for(j=1;j<=y;j++)
		p+=D[N-1][j];//12+11+10+9+8
	Sd=((N-2)*y-p)-((N-x-1)*y-s);//(12*6-p)-(3*6-s)“临界点”以下面积
    printf("%0.0f\n",Sd);

	d=(Su+Sd)/((M-2)*(N-2));//求差异量公式
	printf("差异量D=%0.2f\n",d);

	for(j=1;j<M-1;j++)
	{
		Pr+=D[N-1][j];
	}
	e=Pr/((M-2)*(N-2));//求正答率

	Dd=(0.7*d)/(e*(1-e));//求差异系数公式
	printf("差异系数D*=%0.2f\n\n",Dd);
}
