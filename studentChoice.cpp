#include <stdio.h>
#include <windows.h>
#include "select.h"
#include "signIn.h"
void studentChoice() {
	printf("���������ѧ��");
	char id[11];
	scanf_s("%s",id,11);
	char* name = getName(id);
	printf("\t\tѡ��������е�����\n");
	printf("\t\t1: �鿴���˳ɼ�\n");
	printf("\t\t2: �鿴�༶����\n");
	printf("\t\t3: �鿴ĳ������\n");
	printf("\t\t4: ��ѧ���ѯ\n");
	printf("\t\tQ: �˳�");
	int choice = 0;
	do {
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0: {
			system("cls");
			printf("\t\tѡ��������е�����\n");
			printf("\t\t���ز˵���\n");
			printf("\t\t1: �鿴���˳ɼ�\n");
			printf("\t\t2: �鿴�༶����\n");
			printf("\t\t3: �鿴ĳ������\n");
			printf("\t\t4: ��ѧ���ѯ\n");
			printf("\t\tQ: �˳�");
		}
		case 1: {
			system("cls");
			showRow(name);
			printf("\n\n");
			break;
		}
		case 2: {
			system("cls");
			subjectChoice(name);
			
		}
		case 'Q': {
			choice = 0;
			break;
		}
		default:
			
			printf("��������ȷ������");
			break;
		}
	} while (choice)
		;
}