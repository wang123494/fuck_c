#include "select.h"
#include "windows.h"
#include <stdio.h>
void select() {
	int sign = 1;
	do {
		system("color f0");
		printf("\n\n");
		printf("\t\t\t����ѡ���ѯʲô����?\n");
		printf("\t\t\t-1.������һ��\n");
		printf("\t\t\t0.ȫ��\n");
		printf("\t\t\t1.����\n");
		printf("\t\t\t2.��ѧ�ɼ�\n");
		printf("\t\t\t3.Ӣ��ɼ�\n");
		printf("\t\t\t4.�����ɼ�\n");
		printf("\t\t\t5.c���Գɼ�\n");
		unsigned int number;
		scanf_s("%d", &number);
		switch (number) {
		case -1:
			sign = 0;
			break;
		case 0:
			system("cls");
			showData();
			break;
		case 1:
			system("cls");
			showColumn("����");
			break;
		case 2:
			system("cls");
			showColumn("����,�Ա�,��ѧ�ɼ�");

			break;
		case 3:
			system("cls");
			showColumn("����,�Ա�,Ӣ��ɼ�");
			break;
		case 4:
			system("cls");
			showColumn("����,�Ա�,�����ɼ�");
			break;
		case 5:
			system("cls");
			showColumn("����,�Ա�,c���Գɼ�");
			break;
			
			
		default:printf("������������.");
			break;
		}
	} while (sign);
	
}




