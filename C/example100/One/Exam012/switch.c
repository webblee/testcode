# include <stdio.h>

void main()
{
	int num;
	/* ���涨��ĸ��������ֱ�����λ��ʮλ����λ��ǧλ����λ��ʮ��λ�Լ�λ�� */
	int indiv, ten, hundred, thousand; 
	int ten_thousand, hundred_thousand, place;

	printf("������һ������(0��999999)��");
	scanf("%d", &num);

	/* �жϱ���num��λ�� */
	if(num > 99999)
		place = 6;
	else if(num > 9999)
		place = 5;
	else if(num > 999)
		place = 4;
	else if(num > 99)
		place = 3;
	else if(num > 9)
		place = 2;
	else
		place = 1;
	printf("place = %d\n", place);
	
	printf("ÿλ����Ϊ��");

	/* ���num�ڸ�λ�ϵ�ֵ */
	hundred_thousand = num/100000;
	ten_thousand = (num - hundred_thousand*100000)/10000;
	thousand = (num - hundred_thousand*100000 - ten_thousand*10000)/1000;
	hundred = (num - hundred_thousand*100000 - ten_thousand*10000 
		      - thousand*1000)/100;
	ten = (num - hundred_thousand*100000 - ten_thousand*10000 
		  - thousand*1000 - hundred*100)/10;
	indiv = num - hundred_thousand*100000 - ten_thousand*10000 
		    - thousand*1000 - hundred*100 - ten*10;

	/* �жϱ���num��λ����������λ��������Ӧ����� */
	switch(place)
	{
	case 1: printf("%d", indiv);
		    printf("\n��������Ϊ��");
			printf("%d\n", indiv);
			break;
    case 2: printf("%d, %d", ten, indiv);
		    printf("\n��������Ϊ��");
			printf("%d%d\n", indiv, ten);
			break;
	case 3: printf("%d, %d, %d", hundred, ten, indiv);
		    printf("\n��������Ϊ��");
			printf("%d%d%d\n", indiv, ten, hundred);
			break;
	case 4: printf("%d, %d, %d, %d", thousand, hundred, ten, indiv);
		    printf("\n��������Ϊ��");
			printf("%d%d%d%d\n", indiv, ten, hundred, thousand);
			break;
	case 5: printf("%d, %d, %d, %d, %d", ten_thousand, thousand, 
				   hundred, ten, indiv);
		    printf("\n��������Ϊ��");
			printf("%d%d%d%d%d\n", indiv, ten, hundred, 
				    thousand, ten_thousand);
			break;
	case 6: printf("%d, %d, %d, %d, %d, %d", hundred_thousand, 
				   ten_thousand, thousand, hundred, ten, indiv);
		    printf("\n��������Ϊ��");
			printf("%d%d%d%d%d%d\n", indiv, ten, hundred, thousand,
				    ten_thousand, hundred_thousand);
			break;
	default: printf("Not find.\n");
		     break;
	}
}