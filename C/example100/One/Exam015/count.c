# include <math.h>
# include <stdio.h>    /* ��ѧ������ */

void main()
{
	/* ��s��ʾ����ʽ��ֵ����t��ʾÿһ���ֵ */
	double s, t, x;
	int n;
	printf("please input x: ");
	scanf("%lf", &x);
    /* ����ֵ */
	t = x;
	n = 1;
	s = x;
    /* ���е������� */
	do
	{
		n = n + 2 ;
		t = t * (-x*x)/((float)(n)-1)/(float)(n);
		s = s + t;
	} while (fabs(t)>=1e-8);
	printf("sin(%f) = %lf\n", x, s);
}