#include<stdio.h>
#include <Windows.h>
#include "CRUD.h"
void teacherChoice() {
	int sign = 1;
	do {
		printf("\n\n\n");
		printf("�����Բ�ѯ���뿴������\n");
		printf("\t\t\t1:�鿴�ɼ�\n");
		printf("\t\t\t2:�鿴ĳ�����ֵ\n");
		printf("\t\t\t3:�鿴ĳ�Ƶ�ƽ����\n");
		printf("\t\t\t4:�鿴ĳ�Ƶ���Сֵ\n");
		printf("\t\t\t5:����\n");
		printf("\t\t\t6:ɾ��ĳ��\n");
		printf("\t\t\t7:�������� \n");
		printf("\t\t\t");
		printf("0:�˳�\n");

		int number;
		scanf_s("%d", &number);
		switch (number)
		{
		case 1: {
			system("cls");
			select();
			break;
		}
		case 2: {
			system("cls");
			selectMax();
			break;
		}
		case 3: {
			system("cls");
			selectAver();
			break;
		}
		case 4: {
			system("cls");
			selectMin();
			break;
		}
		case 5: {
			system("cls");
			update();
			break;
		}
		case 6: {
			system("cls");
			deleteRow();
			break;
		}
		case 7: {
			system("cls");
			addRow();
			break;
		}
		case 0:{
				  sign = 0;
				  exit(0);
				  break;
		}
		default:
			printf("�������");
			break;
		
		}
	} while (sign);

}