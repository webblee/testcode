# include <stdio.h>

void main()
{
	/* ������һ���޷����ַ��ͱ������˱���ֻ�������洢�޷����� */
	unsigned char result;
    
	int a, b, c, d;
	a = 2;
	b = 4;
	c = 6;
	d = 8;

	/* �Ա������С���λ�롱���� */
	result = a & c;
	printf("result = %d\n", result);

	/* �Ա������С���λ�򡱲��� */
	result = b | d;
	printf("result = %d\n", result);

	/* �Ա������С���λ��򡱲��� */
	result = a ^ d;
	printf("result = %d\n", result);

	/* �Ա������С�ȡ�������� */
	result = ~a;
	printf("result = %d\n", result);
}