# include <stdio.h>
# include <stdlib.h>
# include <time.h>

/* ����ϵͳʱ����Ѱ�������������ǰʮ���������ʾ���� */
int main()
{
	long time1;
	int i, time2;

	/* �����ȷ������ʱ�� */
	time1 = time(NULL);    /* ����ϵͳ�ĵ�ǰ����ʱ�� */
	printf("%ld\n", time1);

	time2 = (unsigned)time1/2;
	printf("%ld\n", time2);

	/* ��ϵͳʱ��Ϊ������Ϊ�������ɵ�α���������������� */
	srand(time2);

	/* ����ʮ��α��������� */
	for(i=0; i<10; i++)
		printf("%d ", rand());
	printf("\n");

	return 0;
}