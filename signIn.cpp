#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "signIn.h"
void signIn() {
	int chose = 0;
	printf("1:��ʦ�˵�¼\n");
	printf("2:ѧ���˵�¼\n");
	scanf_s("%d", &chose);
	if (chose == 1) {
		printf("����������˻�:");
		char account[20];
		scanf_s("%s", account, 20);
		printf("�������������:");
		char passport[20];
		scanf_s("%s", passport, 20);
		if (teacherConnect(account, passport)) {
			printf("��¼�ɹ�");
			Sleep(1000);
			system("cls");
		}
		else {
			printf("��¼ʧ�ܣ���������˺Ż������д�������������");
		}



	}
	if (chose == 2) {
		printf("����������˻�:");
		char account[20];
		scanf_s("%s", account, 20);
		printf("�������������:");
		char passport[20];
		scanf_s("%s", passport, 20);
		if (studentConnect(account, passport)) {
			printf("��¼�ɹ�");
			Sleep(1000);
			system("cls");

		}
		else {
			printf("��¼ʧ�ܣ���������˺Ż������д�������������");
		}
	}
	if (chose != 1 && chose != 2) {
		printf("��������ȷ������");
	}
}