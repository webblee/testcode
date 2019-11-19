#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

double Func(double);
int BisectRoot(double,double,double,double,double *,int,int *);

void main()
{
	int i,n,m;
	double a,b,h,eps,*x;
	n = 3;						/*���̸��ĸ�����Ԥ��ֵ*/
	x = (double*)calloc(n,sizeof(double));		/*�����ڴ�ռ�*/
	if(x == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	a = -3;								/*������ʼ�˵�*/
	b = 7;								/*������ֹ�˵�*/
	h = 0.1;							/*����*/
	eps = 1.e-8;						/*Ҫ��ﵽ�ľ���*/
	BisectRoot(a,b,h,eps,x,n,&m);		/*���ö��ַ�����*/
	printf("y=sin(x)�ڷ�Χ%2.0f��%2.0f֮��ĸ���%d����\n",a,b,m);
	printf("���Ƿֱ��ǣ�\n");
	for(i = 0;i<n;i++)
	printf("x[%d] = %e\n",i,x[i]);
	free(x);					/*�ͷ��ڴ�ռ�*/
}

double Func(double x)
{
	return(sin(x));
}

int BisectRoot(a,b,h,eps,x,n,m)
double a;			/*ʵ�ͱ������������������������ʼ�˵�*/
double b;			/*ʵ�ͱ������������������������ֹ�˵�*/
double h;			/*������ɨ�跨ȷ����λ��ʱ�Ĳ���*/
double eps;			/*ʵ�ͱ�����������������ƾ��ȵĲ���*/
double *x;			/*ʵ��һά���飬�����������ż���õ�������*/
int n;				/*��������������ڷ��̸��ĸ�����Ԥ��ֵ*/
int *m;				/*���������ʵ����õĸ��ĸ���*/
{
	double z,z0,z1,y,y0,y1;
	*m = 0;
	z = a;
	y = Func(z);
	while(1)		/*����ѭ����ֱ������return����break���*/
	{/*�����ɨ�赽���������Ҷ˵���ߵõ��ĸ��ĸ����ﵽԤ�����ĸ���*/
		if((z>b+h/2)||(*m==n))	
			return(1);
		if(fabs(y)<eps)		/*�����ǰ��z��Ӧ�ĺ���f(z)���㾫��Ҫ��*/
		{
			*m+=1;
			x[*m-1] = z;	/*����ʱ��zֵ��ֵ��x����*/
			z+=h/2;
			y = Func(z);
			continue;		/*��������ѭ����������ѭ������������δִ��
							 �������Ž�����һ���Ƿ�ִ��ѭ�����ж�*/
		}
	
		z1 = z+h;			/*��ɨ����С������Ҷ˵�*/
		y1 = Func(z1);		/*С�����Ҷ˵��Ӧ�ĺ���ֵ*/
		if(fabs(y1)<eps)	/*����Ҷ˵�ǡ��������ľ���Ҫ��*/
		{
			*m+=1;
			x[*m-1] = z1;
			z = z1+h/2;
			y = Func(z);
			continue;
		}
		if(y*y1>0)			/*�����Ӧ���˻������㣬˵����������û�и�*/
		{
			y = y1;			
			z = z1;
			continue;
		}
		while(1)		/*�����whileѭ��ִ�У�˵����ɨ��С����z��z1���и�*/
		{
			if(fabs(z1-z)<eps)		/*������㾫��Ҫ��*/
			{
				*m+=1;
				x[*m-1]=(z1+z)/2;
				z = z1+h/2;
				y = Func(z);
				break;
			}
			z0 = (z1+z)/2;			/*���ַ������ʽ*/
			y0 = Func(z0);
			if(fabs(y0)<eps)
			{
				*m = *m+1;
				x[*m-1] = z0;
				z =z0+h/2;
				y = Func(z);
				break;
			}
			if(y*y0<0)			/*����˻�С���㣬˵������z��z0֮��*/
			{
				z1 = z0;
				y1 = y0;
			}
			else				/*�������z0��z1֮��*/
			{
				z = z0;
				y = y0;
			}
		}
	}
}


