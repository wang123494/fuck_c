#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "signIn.h"


int signIn() {
	int chose = 0;
	printf("1:��ʦ�˵�¼\n");
	printf("2:ѧ���˵�¼\n");
	scanf_s("%d", &chose);

	if (chose == 1) {
		printf("����������˻�(ѧ��):");
		char account[20];
		scanf_s("%s", account, 20);
		printf("�������������:");
		char passport[20];
		scanf_s("%s", passport, 20);
		int sign = 0;
		do {
			if (teacherConnect(account, passport)) {
				printf("��¼�ɹ�!");
				Sleep(100);
				sign = 0;
				system("cls");
				return 1;
				//������������

			}
			else {
				printf("��¼ʧ�ܣ���������˺Ż������д�������������");
				sign = 1;
			}
		} while (sign);
	}
	if (chose == 2) {
		printf("����������˻�:");
		char account[20];
		scanf_s("%s", account, 20);
		printf("�������������:");
		char passport[20];
		scanf_s("%s", passport, 20);
		int sign = 0;
		do {
			if (studentConnect(account, passport)) {
				printf("��¼�ɹ�");
				Sleep(100);
				sign = 0;
				system("cls");
				return 2;

			}
			else {
				printf("��¼ʧ�ܣ���������˺Ż������д�������������");
				sign = 1;
			}
		} while (sign);
	}
	if (chose != 1 && chose != 2) {
		printf("��������ȷ������");
		return 0;
	}
}