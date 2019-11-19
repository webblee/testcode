#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
float  * datafield;
int  vectornum;
int  vectorsize;
struct  GROUP
{
	float  * center;
	float  D;
	float  variance;
	int  groupsize;
	int  flag;//����������鵥Ԫ�Ƿ�ռ��
};
struct  GROUP  group[100];
int  maxindex;//�������
int  groupnum;
struct  CCD//��¼���������ĵľ���
{
	float  dst;
	int  g1 , g2;//������
}ccd  ,  * ccdhead;
float  Dst;

void  write (int i , int j , float data);//
float  data (int i , int j);//
float  * vector (int  i);//

void  initiate ();//
void  input ();//
void  allocate ();//��ģʽ�������������ľ���
void  converge ();//
void  diverge ();//
void  renum ();//���·�������
void  showresult ();

float  distance (float  * x , float  * y);
void  split (int i , int j);//
void  insert (int i , int j , float D);

int  K;//Ԥ�ڵľ���������Ŀ
int  Nmin;//ÿһ���������ٵ�������Ŀ���������ڴ����Ͳ���Ϊһ�������ľ���
float  Ds;//һ������������������ֲ��ı�׼��
float  Dm;//������������֮�����С���룬��С�ڴ���������������кϲ�
int  L;//���ڴ˵��������п��Ժϲ��ľ������ĵ�������
int  I;//��������Ĵ������

void  main ()
{
	int  i;
	initiate ();//�������ݣ���ʼ����������,�����趨Ĭ��ֵ
	for (i = 1 ; ; i++)
	{
		input ();//��ʾ���޸Ĳ���
		allocate ();//��ɵ�2-6��
		if (i == I)
		{
			Dm = 0;
			converge ();
			break;
		}
		if (groupnum <= K / 2)  diverge ();
		else 
		{
			if ((groupnum >= K * 2) | ( i % 2 == 0))
				converge ();
			else 
				diverge ();
		}		
		renum ();		
	}
	showresult ();
	free (datafield);
	free (ccdhead);
	for (i = 0 ; i < 100 ; i++)
		free (group[i].center);
}
void  initiate ()
{
	int  i , j , size;
	FILE  * df;
	char  s[10];
	float  d;
	K = 2;
	Nmin = 1;
	Ds = 1;
	Dm = 4;
	L = 1;
	I = 5;
	maxindex = groupnum = 1;
	if ((df = fopen("data.txt" , "r")) == NULL)
	{
		printf ("Cannot open file\n");
		exit (1);
	}
	fscanf (df , "%5d" , &vectornum);
	fscanf (df , "%5d" , &vectorsize);
	size = vectornum * (vectorsize + 1);
	datafield = (float *) malloc (size * sizeof (float));
	for (i = 0 ; i < vectornum ; i++)
	{
		for (j = 0 ; j < vectorsize ; j++)
		{
			fscanf (df , "%10f" , &d);
			write (i , j + 1 , d);
		}
		write (i , 0 , -1);
	}
	fscanf (df , "%10s" , s);
	if (strcmp (s , "end") != 0)
	{
		printf ("\n�����ʼ��ʧ�ܣ�");
		exit (1);
	}
	fclose (df);
	for (i = 0 ; i < 100 ; i++)
	{
		group[i].flag = 0;
		group[i].center = (float *) malloc ((vectorsize) * sizeof (float));
		group[i].groupsize = 0;
		group[i].variance = 0;
		group[i].D = 0;
	}
	for (i = 0 ; i < groupnum ; i++)
	{
		for (j = 0 ; j < vectorsize ; j++)
		{
			* (group[i].center + j) = data(i , j + 1);///////////////////////////////////////////
		}
		group[i].flag = 1;
	}
}
void  input ()
{
	char  choice;
	printf ("\n\n���õĲ���ȡֵ:\n");
	printf ("K = %d\n,Nmin=%d\n,Ds=%f\n,Dm=%f\n,L=%d\n,I=%d\n",K,Nmin,Ds,Dm,L,I);
	showresult();
	printf ("�Ƿ���Ҫ�����޸ģ�(Y/N)\n");
	scanf("%s" , & choice);
	choice = toupper (choice);
	if (choice == 'Y')
	{
		printf ("\n������Ԥ�ڵľ���������Ŀ:");
		scanf ("%d" , &K);
		printf ("\n������ÿһ������������������:");
		scanf ("%d" , &Nmin);
		printf ("\n������һ������������������ֲ��ı�׼��:");
		scanf ("%f" , &Ds);
		printf("\n����������������֮�����С����:");
		scanf ("%f" , &Dm);
		printf ("\n������һ�ε��������п��Ժϲ��ľ������ĵ������Ŀ:");
		scanf ("%d" , &L);
		printf ("\n����������������:");
		scanf ("%d" , &I);
	}
}
void  allocate ()
{
	int  i , j , k , num , index;
	float  D , D1 , sum;
	for (i = 0 ; i < 100 ; i++)//Ϊ����������ֵ����
	{
		group[i].D = 0;
		group[i].groupsize = 0;
		group[i].variance = 0;
	}
	for (i=0 ; i < vectornum ; i++)//��������䵽��������
	{
		D = distance (group[0].center , vector (i));
		k = 0;
		for (j = 1 ; j < groupnum ; j++)
		{
			D1 = distance (group[j].center , vector (i));
			if (D > D1)
			{
				k = j;
				D = D1;
			}
		}
		write (i , 0 , (float) k);		
		group[k].groupsize++;
	}
	num = groupnum;
	for (i = 0 ; i < num ; i++)//����������������С�ڹ涨ֵʱ��������
	{
		if (group[i].groupsize < Nmin)
		{
			group[i].flag = 0;
			group[i].groupsize = 0;
			for (j = 0 ; j < vectornum ; j++)
			{
				if (data (j , 0) == i)
				{
					write (j , 0 , -1.0);
				}
			}
			groupnum--;
		}
	}	
	for (i = 0 ; i < 100 ; i++)//Ϊ����������ֵ����
	{
		for (j = 0 ; j < vectorsize ; j++)
			* (group[i].center + j) = 0;
	}
	for (i = 0 ; i < vectornum ; i++)//�����µľ�������
	{
		index = (int) data (i , 0);
		if (index != -1)
		{
			sum = (float) group[index].groupsize;
			for (j = 0 ; j < vectorsize ; j++)
			{
				* (group[index].center + j) = * (group[index].center + j) + data(i , j + 1) / sum;
			}
		}
	}
	for (i = 0 ; i < vectornum ; i++)//��������㵽�������ľ���
	{
		index = (int) data (i , 0);
		if (index != -1)
		{
			sum = (float) group[index].groupsize;
			D = distance (group[index].center , vector (i));
			group[index].D = group[index].D + D / sum;
		}
	}
	Dst = 0;
	for (i = 0 ; i < maxindex ; i++)
	{
		if (group[i].flag != 0)
			Dst = Dst + group[i].D;
	}	
	Dst = Dst / groupnum;
}
void  diverge ()
{
	float  newvar , oldvar , center;
	int  i , j , k , l , flag;
	flag = 0;
	for (i = 0 ; i < maxindex ; i++)
	{
		if (group[i].flag != 0)
		{
			oldvar = 0;//��׼��
			for (j = 0 , l = 0 ; j < vectorsize ; j++)
			{//����ͬһ�������и�������Ӧ�ı�׼���е����ֵ		
				newvar = 0;
				center = * (group[i].center + j);
				for (k = 0 ; k < vectornum ; k++)
				{
					if (data (k , 0) == i)
						newvar = newvar +(center - data(k , j+1))*(center - data(k , j+1));
				}
				if (newvar > oldvar)
				{
					oldvar = newvar;
					l = j;
				}
			}
			group[i].variance = (float) sqrt( oldvar / group[i].groupsize);
			if (group[i].variance > Ds)
			{
				if ((groupnum <= K/2) | ((group[i].D > Dst) & (group[i].groupsize > 2 * (Nmin + 1))))
				{
					split (i , l);
					flag = 1;	
				}
			}
		}
	}
	if (flag == 0)
		converge ();
}
void  split (int i , int j)
{
	int  k , l;
	k = maxindex;
	group[k].flag = 1;
	for (l = 0 ; l < vectorsize ; l++)
	{
		* (group[k].center + l) = (* (group[i].center + l));
	}
	* (group[k].center + j) = (* (group[k].center + j) + group[i].variance);
	* (group[i].center + j) = (* (group[i].center + j) - group[i].variance);			
	maxindex++;
	groupnum++;
}
void  converge ()
{	
	int  i , j , k , h , l;
	float  D , c1 , c2 , n1 , n2;
	ccdhead = (struct CCD *) malloc (sizeof (ccd) * L);
	for (i = 0 , k = 0 ; i < maxindex - 1 ; i++)
	{
		if (group[i].flag != 0)
		{
			for (j = i + 1 ; j < maxindex ; j++)
			{
				if (group[j].flag != 0)
				{
					D = distance (group[i].center , group[j].center);
					if (D < Dm)
					{
						if (k < L)
						{
							(ccdhead + k)->dst = D;
							(ccdhead + k)->g1 = i;
							(ccdhead + k)->g2 = j;
							k++;
						}
						else
						{
							insert (i,j,D);							
						}
						break;
					}
				}
			}
		}
	}		
	for (h = 0 ; h < k ;h++)
	{
		i = (ccdhead + h)->g1;
		j = (ccdhead + h)->g2;
		n1 = (float) group[i].groupsize;
		n2 = (float) group[j].groupsize;
		for (l = 0 ; l < vectorsize ; l++)
		{
			c1 = (* (group[i].center + l));
			c2 = (* (group[j].center + l));
			* (group[i].center + l) = (n1 * c1 + n2 * c2) / (n1 + n2);
		}
		group[i].groupsize = (int) (n1 + n2);
		for (l = 0 ; l < vectornum ; l++)
			if (data(l , 0) == j)
				write (l , 0 , (float) i);
		group[j].flag = 0;
		group[j].groupsize = 0;
		groupnum--;
	}
}
void  insert (int i , int j , float D)
{
	int  h , l;
	for (h = 0 ; h < L ; h++)
	{
		if (D < (ccdhead + h)->dst)
		{
			for (l = L - 1 ; l > h ; l--)
			{
				(ccdhead + l)->dst = (ccdhead + l - 1)->dst;
				(ccdhead + l)->g1 = (ccdhead + l - 1)->g1;
				(ccdhead + l)->g2 = (ccdhead + l - 1)->g2;
			}
			(ccdhead + h)->dst = D;
			(ccdhead + h)->g1 = i;
			(ccdhead + h)->g2 = j;
		}
	}
}

void  renum ()
{
	int  i , j , k;
	for (i = 0 ; i < maxindex - 1 ; i++)
	{
		if (group[i].flag == 0)
		{
			for (j = maxindex ; j > i ; j--)
			{
				if (group[j].flag == 1)
				{
					group[i].flag = 1;
					group[j].flag = 0;					
					for (k = 0 ; k < vectorsize ; k++)
					{
						* (group[i].center + k) = (* (group[j].center + k));
						* (group[j].center + k) = 0;
					}
				}
			}
		}
	}
	maxindex = groupnum;
}

void  showresult ()
{
	int  i , j , k , l;
	for (j = 1 , i = 0 ; i < maxindex ; i++)
	{
		if (group[i].flag != 0)
		{
			printf ("��%3d�������������Ϊ:" , j ++);
			for (k = 0 ; k < vectorsize ; k++)
				printf (" %10f " , *(group[i].center + k));
			printf (" \n��������������������Ϊ:\n ");
			for (k = 0 ; k < vectornum ; k++)
			{
				if (data(k , 0) == i)
				{
					for (l = 0 ; l < vectorsize ; l++)
					{
						printf (" %10f " , data(k , l + 1));
					}
					printf (" \n ");
				}
			}
		}
	}
}
float  data (int i , int j)
{
	return  * (datafield + i * (vectorsize + 1) + j);
}
void  write (int i , int j , float data)
{
	* (datafield + i * (vectorsize + 1) + j) = data;
}
float  * vector (int i)
{ 
	return  datafield + i * (vectorsize + 1) + 1;
}
float  distance (float  * x , float  * y)
{
	int  i;
	float  z;
	for (i = 0 , z = 0 ; i < vectorsize ; i++)
		z = z + ((* (x + i)) - (* (y + i))) * ((* (x + i))-(* (y + i)));
	return  (float) sqrt(z);
}