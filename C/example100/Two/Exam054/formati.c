# include <stdio.h>

void main()
{
	int i, j, k;
	char str[80];
	char *p;
	
	/* ����������ֱ���ʮ���ơ��˽��ƺ�ʮ�����ƶ������ */
	scanf("%d %o %x", &i, &j, &k);  
	printf("%d %d %d\n", i, j, k);  /* �쿴����ʵ����������� */
	
	printf("Enter a string: ");
	scanf("%s", str);
	printf("Here is your string: %s\n", str);

	printf("Enter an address: ");
	scanf("%p", &p);
	printf("Value at location %p is %c.\n", p, *p);
}