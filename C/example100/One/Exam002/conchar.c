# include <stdio.h>

void main()
{
	/* ���з�'\n'������������� */
	printf("How are you?\n");
	printf("I am fine.\n\n");

	/* ���������'\t'��ʹ������һ������� */
	printf("How are you?\t");
	printf("I am fine.\n\n");

	/* �˸��'\b'��ʹ��ǰ�����λ����һ�񣬼��������ʼλ������һλ */
	printf(" How are you?\n");
	printf(" \bI am fine.\n\n");

	/* �س���'\r'��ʹ��ǰ���λ�ûص����п�ͷ */
	printf("                I am fine.");
	printf("\rHow are you?\n\n");

	/* ���ת���ַ��Ļ������ */
	printf("note:\n  a s\ti\b\bk\rp\n");
}