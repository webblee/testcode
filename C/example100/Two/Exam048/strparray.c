# include <stdio.h>

/* ����һ��ȫ�ֵĽṹ�� */
struct student
{
	long num;
	char name[20];
	char sex;
	int age;
};

/* �����ṹ�����鲢����ֵ */
struct student stu[4] = {{97032, "xiao ming", 'M', 20},
                         {97033, "xiao wang", 'M', 20},
						 {97034, "xiao tong", 'M', 21},
                         {97035, "xiao shui", 'F', 18}};

void main()
{
	/* ����һ���ṹ��ָ����� */
	struct student *p;

	printf(" ѧ��     ����     �Ա�     ����\n");
	for(p=stu; p<stu+4; p++)
		printf("%-8ld%-12s%-10c%-3d\n", p->num, p->name, 
		                               p->sex, p->age);
}
