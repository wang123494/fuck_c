#include "select.h"
#include "windows.h"
#include <stdio.h>
void select() {
	system("color f0");
	printf("\t\t\t����ѡ���ѯʲô����?\n");
	printf("\t\t\t0.ȫ��\n");
	printf("\t\t\t1.����\n");
	printf("\t\t\t2.��ѧ�ɼ�\n");

	unsigned int number;
	scanf_s("%d", &number);
	switch (number) {
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
		showColumn("����,�Ա�,");
		break;
	}
}




