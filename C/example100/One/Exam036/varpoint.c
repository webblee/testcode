/* ����x��y��z��������������С˳����� */
# include <stdio.h>

void swap(int *pt1, int *pt2);
void exchange(int *q1, int *q2, int *q3);

void main()
{
	int x, y, z;
	int *p1, *p2, *p3;
	printf("����������������");
	scanf("%d, %d, %d", &x, &y, &z);    /* ��������ʱ�Զ��Ÿ��� */
	p1 = &x;
	p2 = &y;
	p3 = &z;
	exchange(p1, p2, p3);
	printf("����С��������������Ϊ��");
	printf("%d, %d, %d\n", x, y, z);
}

void swap(int *pt1, int *pt2)
{
	int p;
	p = *pt1;
	*pt1 = *pt2;
	*pt2 = p;
}

void exchange(int *q1, int *q2, int *q3)
{
	if(*q1 < *q2)
		swap(q1, q2);
	if(*q1 < *q3)
		swap(q1,q3);
	if(*q2 < *q3)
		swap(q2,q3);
}