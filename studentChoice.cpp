#include <stdio.h>
#include <windows.h>
#include "select.h"
#include "signIn.h"
#include "judge.h"
void studentChoice() {
	printf("���������ѧ��");
	char id[11];
	scanf_s("%s",id,11);
	int sign = 1;
	char* name = getName(id);
	
	do {
	
		printf("\t\tѡ��������е�����\n");
		printf("\t\t���ز˵���\n");
		printf("\t\t1: �鿴���˳ɼ�\n");
		printf("\t\t2: �鿴�༶����\n");
		printf("\t\t3: �ҿƲ�ѯ\n");
		printf("\t\t: �˳�");
		int choice = 0;
		scanf_s("%d", &choice);
		switch (choice)
		{
			
		case 1: {
			system("cls");
			showRow(name);
			printf("\n\n");
			break;
		}
		case 2: {
			system("cls");
			subjectChoice(name);
			break;
		}
		case 3: {
			system("cls");
			if (Failed(id)) {
				printf("��Ǹ�����йҿƿ�Ŀ\n");
			}
			else {
				printf("��ϲ������δ�йҿƿ�Ŀ\n");
			}
			break;
		}
		case -1: {
			sign = 0;
			break;
		}
		default:
			printf("��������ȷ������");
			break;
		}
	} while (sign)
		;
}