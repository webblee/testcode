# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main()
{
	/* �����Ӻ��� */
	int binary(char *ptr[], char *str, int n);    /* ���Һ������� */
	void insert(char *ptr[], char *str, int n, int i);    /* ���뺯������ */

	char *temp, *ptr1[6];
	int i;
	printf("��Ϊ�ַ���ָ�����鸳��ֵ��\n");
	for (i=0; i<5; i++)
	{
		ptr1[i] = (char *)malloc(20);    /* Ϊָ������ַ�� */
		gets(ptr1[i]);    /* �����ַ��� */
	}
	ptr1[5] = (char *)malloc(20);
	printf("\n");

	printf("original string:\n");
	for(i=0; i<5; i++)    /* ���ָ��������ַ��� */
		printf("%s\n", ptr1[i]);

	printf("\ninput search string:\n");
	temp = (char *)malloc(20);
	gets(temp);    /* ���뱻���ַ��� */

	i=binary(ptr1, temp, 5);    /* Ѱ�Ҳ���λ��i */
	printf("i = %d\n", i);

    insert(ptr1, temp, 5, i);    /* �ڲ���λ��i�������ַ��� */
	printf("output strings:\n");

	for(i=0; i<6; i++)    /* ���ָ�������ȫ���ַ��� */
		printf("%s\n", ptr1[i]);
}

int binary(char *ptr[], char *str, int n)
{ 
	/* �۰���Ҳ���λ�� */
	int hig, low, mid;
	low = 0;
	hig = n-1;
	if(strcmp(str,ptr[0]) < 0) 
		return 0;
    /* �������ַ������ַ�������ĵ�0��С�������λ��Ϊ0 */
	if(strcmp(str,ptr[hig]) > 0) 
		return n;
    /* �������ַ������ַ�����������һ������Ӧ�����ַ��������β�� */
    while(low <= hig)
	{
		mid = (low + hig)/2 ;
		if (strcmp(str,ptr[mid]) < 0)
			hig = mid - 1;
		else if(strcmp(str,ptr[mid]) > 0)
			low = mid + 1;
		else 
			return mid;    /* �����ַ������ַ��������ĳ���ַ�����ͬ */
	}
	return low;    /* �����λ�����ַ��������м� */
}

void insert(char *ptr[], char *str, int n, int i)
{
	int j;
	for(j=n; j>i; j--)    /* ������λ��֮����ַ������� */
		strcpy(ptr[j], ptr[j-1]);
	strcpy(ptr[i], str);    /* �������ַ������ֵ�˳������ַ������� */
}