# include <stdio.h>
# include <string.h>

void main()
{
	struct student
	{
		long num;
		char name[30];
		char sex[10];
		float score;
	};
	struct student stu;
	struct student *p;
	p = &stu;
	stu.num = 97032;
	strcpy(stu.name, "С��");
	strcpy(stu.sex, "��");
	stu.score = 98.5;

	printf("ѧ��: %ld\n����: %s\n�Ա�: %s\n����: %4.2f\n",
		    stu.num, stu.name, stu.sex, stu.score);
	printf("\n");
	printf("ѧ��: %ld\n����: %s\n�Ա�: %s\n����: %4.2f\n",
		    (*p).num, (*p).name, (*p).sex, (*p).score);
}