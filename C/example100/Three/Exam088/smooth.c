#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

Smooth(double *,double *,double *,int,int,
	   double *,double *,double *);
void main()
{
	int i,n,m;
	double *x,*y,*a,dt1,dt2,dt3,b;
	n = 20;
	m = 6;
	b = 0;
	/*�ֱ�Ϊx,y,a��������ռ�*/
	x = (double *)calloc(n,sizeof(double));
	if(x == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit (0);
	}
	y = (double *)calloc(n,sizeof(double));
	if(y == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit (0);
	}
	a = (double *)calloc(n,sizeof(double));
	if(a == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit (0);
	}
	for(i=1;i<=n;i++)
	{
		x[i-1]=b+(i-1)*0.1;
		/*ÿ��0.1ȡһ���㣬��������ȡn����*/
		y[i-1]=x[i-1]-exp(-x[i-1]);
		/*����x[i-1]���Ӧ��yֵ��Ϊ�����ֵ֪*/
	}
	Smooth(x,y,a,n,m,&dt1,&dt2,&dt3);			/*������Ϻ���*/
	for(i=1;i<=m;i++)
		printf("a[%d] = %.10f\n",(i-1),a[i-1]);
	printf("��϶���ʽ�����ݵ�ƫ���ƽ����Ϊ��\n");
	printf("%.10e\n",dt1);
	printf("��϶���ʽ�����ݵ�ƫ��ľ���ֵ֮��Ϊ��\n");
	printf("%.10e\n",dt2);
	printf("��϶���ʽ�����ݵ�ƫ��ľ���ֵ���ֵΪ��\n");
	printf("%.10e\n",dt3);
	free(x);								/*�ͷŴ洢�ռ�*/
	free(y);								/*�ͷŴ洢�ռ�*/
	free(a);								/*�ͷŴ洢�ռ�*/
}

	Smooth(x,y,a,n,m,dt1,dt2,dt3 )
		double *x;				/*ʵ��һά���飬�����������Žڵ��xiֵ*/
		double *y;				/*ʵ��һά���飬�����������Žڵ��yiֵ*/
		double *a;				/*˫����ʵ��һά���飬����Ϊm������mһ1����϶���ʽ��m��ϵ��*/
		int n;					/*���ͱ���������������������ݵ�ĸ���*/
		int m;					/*���ͱ����������������϶���ʽ������*/
		double *dt1;			/*ʵ�ͱ����������������϶���ʽ�����ݵ�ƫ���ƽ����*/
		double *dt2;			/*ʵ�ͱ����������������϶���ʽ�����ݵ�ƫ��ľ���ֵ֮��*/
		double *dt3;			/*ʵ�ͱ����������������϶���ʽ�����ݵ�ƫ��ľ���ֵ���ֵ*/
	{
		int i,j,k;
		double *s,*t,*b,z,d1,p,c,d2,g,q,dt;
		/*�ֱ�Ϊs,t,b��������ռ�*/
		s = (double *)calloc(n,sizeof(double));
		if(s == NULL)
		{
			printf("�ڴ����ʧ��\n");
			exit (0);
		}
		t = (double *)calloc(n,sizeof(double));
		if(t == NULL)
		{
			printf("�ڴ����ʧ��\n");
			exit (0);
		}
		b = (double *)calloc(n,sizeof(double));
		if(b == NULL)
		{
			printf("�ڴ����ʧ��\n");
			exit (0);
		}
		z = 0;
		for(i=1;i<=n;i++)
			z=z+x[i-1]/n;			/*zΪ����x��ƽ��ֵ*/
		b[0]=1;
		d1=n;
		p=0;
		c=0;
		for(i=1;i<=n;i++)
		{
			p=p+x[i-1]-z;
			c=c+y[i-1];
		}
		c=c/d1;
		p=p/d1;
		a[0]=c*b[0];
		if(m>1)
		{
			t[1]=1;
			t[0]=-p;
			d2=0;
			c=0;
			g=0;
			for(i=1;i<=n;i++)
			{
				q=x[i-1]-z-p;
				d2=d2+q*q;
				c=y[i-1]*q+c;
				g=(x[i-1]-z)*q*q+g;
			}
			c=c/d2;
			p=g/d2;
			q=d2/d1;
			d1=d2;
			a[1]=c*t[1];
			a[0]=c*t[0]+a[0];
		}
		for(j=3;j<=m;j++)
		{
			s[j-1]=t[j-2];
			s[j-2]=-p*t[j-2]+t[j-3];
			if(j>=4)
				for(k=j-2;k>=2;k--)
					s[k-1]=-p*t[k-1]+t[k-2]-q*b[k-1];
				s[0]=-p*t[0]-q*b[0];
				d2=0;
				c=0;
				g=0;
				for(i=1;i<=n;i++)
				{
					q=s[j-1];
					for(k=j-1;k>=1;k--)
						q=q*(x[i-1]-z)+s[k-1];
					d2=d2+q*q;
					c=y[i-1]*q+c;
					g=(x[i-1]-z)*q*q+g;
				}
				c=c/d2;
				p=g/d2;
				q=d2/d1;
				d1=d2;
				a[j-1]=c*s[j-1];
				t[j-1]=s[j-1];
				for(k=j-1;k>=1;k--)
				{
					a[k-1]=c*s[k-1]+a[k-1];
					b[k-1]=t[k-1];
					t[k-1]=s[k-1];
				}
		}
		*dt1=0;
		*dt2=0;
		*dt3=0;
		for(i=1;i<=n;i++)
		{
			q=a[m-1];
			for(k=m-1;k>=1;k--)
				q=q*(x[i-1]-z)+a[k-1];
			dt=q-y[i-1];
			if(fabs(dt)>*dt3)
				*dt3=fabs(dt);
			*dt1=*dt1+dt*dt;
			*dt2=*dt2+fabs(dt);
		}
		/*�ͷŴ洢�ռ�*/
		free(s);
		free(t);
		free(b);
		return(1);
	}
