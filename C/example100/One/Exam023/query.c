/* ѧ���ɼ���ѯϵͳ */
# include <stdio.h>
# include <stdlib.h>

void main( )
{
	int select;
	int i, j;
	int score[5][7];
	int average = 0;
	int sum = 0;
    do{
		printf("��������4��ܣ�\n");
		printf(" 1. ����ѧ�Ų�ѯѧ���ɼ�\n");
		printf(" 2. ���ݿ��Ժ�ͳ�Ƴɼ�\n") ;
		printf(" 3. ���ݿ��Ժź�ѧ�Ų�ѯ�ɼ�\n");
		printf(" 4. �ɼ�¼��\n");
		printf(" 0. �˳�\n");
		printf(" ������ѡ��(0 - 4): ");
		scanf("%d", &select);
		switch(select)
		{
		case 0:
			printf("OK\n");
			exit(0);
			break;
		case 1:
			printf("����ѧ�ţ�");
			scanf("%d\n", &i);
			for(j=1; j<7; j++)
			{
				printf("��%d�Ƴɼ���%d\n", j, score[i][j]);
				sum += score[i][j];
			}
			average = sum/6;
			printf("ѧ����ƽ���ɼ���%d\n", average);
			break;
		case 2:
			printf("���뿼�Ժţ�");
			scanf("%d\n", &j);
			for(i=1; i<5; i++)
			{
				printf("��%d��ѧ�����Ƴɼ���%d\n", i, score[i][j]);
				sum += score[i][j];
			}
			average = sum/4;
			printf("����ƽ���ɼ���%d\n", average);
			break;
		case 3:
			printf("����ѧ�źͿ��Ժţ�");
			scanf("%d %d\n", &i, &j);
			printf("��%d��ѧ���ĵ�%d�ƿ��Գɼ���%d\n", i, j, score[i][j]);
			break;
		case 4:
			printf("������ɼ�\n");
			for(i=1; i<5; i++)
				for(j=1; j<7; j++)
					scanf("%d\n", &score[i][j]);
			break;
		default:
			break;
		}
	}while(1);
}