# include <stdio.h>

void main()
{
	unsigned a, b, c, d;
	int n;

	a = 64;
	n = 2;

	/* ��������a����(6-n)λ */
	b = a >> (6-n);
	printf("b = %d\n", b);

	/* ��������a����nλ */
	c = a << n;
	printf("c = %d\n", c);

	/* �Բ�����a���еĻ��λ���� */
	d = (a >> (n-1)) | (a << (n+1));
	printf("d = %d\n", d);
}