# include <stdio.h>

void main()
{
	/* ��������Ķ����Ĭ���У�blue=0 red=1 ... black=4 */
	enum color {blue, red, yellow, purple, black};
	enum color i, j, k, pri;
	int n, loop;
	n = 0;

	for(i=blue; i<=black; i++)  /* i�����һ����ȡǦ�ʵ���ɫ */
		for(j=blue; j<=black; j++)  /* j����ڶ�����ȡǦ�ʵ���ɫ */  
			if(i!=j)  /* ��һ�κ͵ڶ�����ȡǦ����ɫ��ͬ */
			{
				for(k=blue; k<=black; k++)  /* k�����������ȡǦ�ʵ���ɫ */
					if((k!=i)&&(k!=j))  /* ������ȡǦ����ɫ������ͬ */
					{
						n++;  /* �ܵõ����ֲ�ͬ��ɫǦ�ʵĿ���ȡ����1 */
						printf("%-6d", n);
						/* ����ǰi��j��k����Ӧ����ɫ������� */
						for(loop=1; loop<=3; loop++)
						{
							switch(loop)
							{
							case 1: pri = i;
							        break;
							case 2: pri = j;
							        break;
							case 3: pri = k;
							        break;
							default:
								    break;
							}
							switch(pri)
							{
							case blue:   printf("%-10s", "blue");
									     break;
							case red:    printf("%-10s", "red");
									     break;
							case yellow: printf("%-10s", "yellow");
								         break;
							case purple: printf("%-10s", "purple");
								         break;
							case black:  printf("%-10s", "black");
									     break;
							default:
									     break;
							}
						}
						printf("\n");
					}
			}
			printf("total: %5d\n", n);
}