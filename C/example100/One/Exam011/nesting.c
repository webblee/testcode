# include <stdio.h>

void main()
{
	/* sex������Ѫ�ߵ��Ա�weight������Ѫ�ߵ����أ�cubage������Ѫ�� */
	int sex, weight, cubage;
	printf("�������Ѫ�ߵ��Ա�����أ�");
	scanf("%d,%d", &sex, &weight);

	if(sex >= 0)    /* ������sex����ֵΪ�Ǹ��������ʾΪ���� */
	{
		if(weight >= 120)
		{
            cubage = 200;
			printf("����Ӧ����Ѫ��%d����\n", cubage);
		}
		else
		{
			cubage = 180;
			printf("����Ӧ����Ѫ��%d����\n", cubage);
		}
	}
	else   /* ���򣬱�ʾΪŮ�� */
	{
		if(weight >= 100)
		{
            cubage = 150;
			printf("����Ӧ����Ѫ��%d����\n", cubage);
		}
		else
		{
			cubage = 120;
			printf("����Ӧ����Ѫ��%d����\n", cubage);
		}
	}
}