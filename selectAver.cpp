#include <stdio.h>
#include <windows.h>
#include "select.h"
void selectAver() {
	int sign = 1;
	do {
		double scoreOfMath = 0;
		double scoreOfEnglish = 0;
		double scoreOfPE = 0;
		double scoreOfCProgramming = 0;
		system("color f0");
		printf("\n\n");
		printf("\t\t\t����ѡ���ѯʲô����?\n");
		printf("\t\t\t-1.������һ��\n");
		printf("\t\t\t1.��ѧ�ɼ�\n");
		printf("\t\t\t2.Ӣ��ɼ�\n");
		printf("\t\t\t3.�����ɼ�\n");
		printf("\t\t\t4.c���Գɼ�\n");
		unsigned int number;
		scanf_s("%d", &number);
		switch (number) {
		case -1:
			sign = 0;
			break;
		case 1:
			system("cls");
			scoreOfMath = getAverage("��ѧ�ɼ�");
			printf("��ѧ�ɼ�ƽ��ֵΪ%lf", scoreOfMath);
			break;
		case 2:
			system("cls");
			scoreOfEnglish = getAverage("Ӣ��ɼ�");
			printf("��ѧ�ɼ�ƽ��ֵΪ%lf", scoreOfEnglish);
			break;
		case 3:
			system("cls");
			scoreOfPE = getAverage("�����ɼ�");
			printf("�����ɼ�ƽ��ֵΪ%lf", scoreOfPE);
			break;
		case 4:
			system("cls");
			scoreOfCProgramming = getAverage("c���Գɼ�");
			printf("c���Գɼ�ƽ��ֵΪ%lf", scoreOfCProgramming);

			break;
		default:printf("������������.");
			break;
		}
	} while (sign);

}