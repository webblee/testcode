# include <setjmp.h>
# include <stdio.h>

jmp_buf ebuf;    /* ������<setjmp.h>�ж��� */
void fun(void);

int main()
{
	int i;

	printf("1 ");
	i = setjmp(ebuf);    /* ��һ�ε���ʱ����ֵΪ�� */
	if(i == 0)
	{
		fun();
		printf("This will not be printed.");
	}
	printf("%d\n", i);

	return 0;
}

void fun(void)
{
	printf("3 ");
	longjmp(ebuf, 5);    /* ��ת��ִ��setjmp()�ĵط�������ʱ����setjmp()����ֵΪ3 */
}