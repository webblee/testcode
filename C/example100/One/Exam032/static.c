/* �����ꡢ�¡��գ���������Ǹ���ĵڼ��� */
# include <stdio.h>

int sum_day(int month, int day);
int leap(int year);

void main()
{
	int year, month, day;
	int days;
	printf("����������(�꣬�£���)��");
	scanf("%d, %d, %d", &year, &month, &day);
	printf("%d��%d��%d��", year, month, day);
	days = sum_day(month, day);    /* ���ú���sum_day() */
	if(leap(year) && month>=3)    /* ���ú���leap() */
		days = days + 1;
	printf("�Ǹ���ĵ�%d��.\n", days);
}

/* ���徲̬�洢����������ֵ */
static int day_tab[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sum_day(int month, int day)    /* �������� */
{
	int i;
	for(i=1; i<month; i++)
		day = day + day_tab[i];
	return day;
}

int leap(int year)
{
	int leap;
	leap = (year%4==0&&year%100!=0)||(year%400==0);
	return leap;
}