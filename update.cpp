#include <stdio.h>
#include <string.h>
#include "head.h"
#include "update.h"
void signIn();
bool teacherConnect(const char* account, const char* passport);
void update() {
	system("color f0");
	printf("\t\t\t����ѡ�����ʲô����?\n");
	printf("\t\t\t0.ѧ��\n");
	printf("\t\t\t1.����\n");	
	printf("\t\t\t2.�Ա�\n");
	printf("\t\t\t3.��ѧ�ɼ�\n");

	unsigned int number;
	scanf_s("%d", &number);
	switch (number) {
	case 0: 
		system("cls");
		updateId();
		break;
	case 1 : 
		system("cls");
		updateName();
		break;
	case 2:
		system("cls");
		updateGender();
		break;
	case 3:
		system("cls");
		changeNumber("��ѧ�ɼ�");
		break;
	}
	

}



void updateId() {
	char id[11] = {NULL};
	char name[40];
	printf("����������ĵ�����:");
	scanf_s("%s",name,40);
	printf("������ĺ��ѧ��");
	scanf_s("%s",id,11);
	changeString("ѧ��",id,name);
}
void updateName() {
	char preName[40] = {NULL};
	char afterName[40] = {NULL};
	do {
		//��ʼ��
		memset(preName, NULL, 40);
		memset(afterName, NULL, 40);
		printf("����������ĵ�����:");
		scanf_s("%s", preName, 40);
		printf("��������ĺ������:");
		scanf_s("%s", afterName, 40);
		if (!strcmp(preName, afterName)) printf("�������\n"); 

	} while (!strcmp(preName, afterName));

	if (isDuplicate(preName)) {
		char id[11] = {NULL};
		printf("���ظ����������������Ӧѧ��:");
		scanf_s("%s",id,11);
		changeString("����", afterName, preName, id);
	}
	else {
		changeString("����", afterName, preName);
	}
	//��������ظ�������ѧ���޸�
	//�ļ�����


}
void updateGender() {
	char name[40];
	printf("�������˭���Ա�?\n");
	scanf_s("%s", name, 40);

	char Gender[4] = "��";

	printf("���뽫�����Ա�ĳ�ʲô?\n");
	int sign = 1;
	while (sign) {
		if (strcmp(Gender, "��") == 0 || strcmp(Gender, "Ů") == 0) {
			printf("��������ĺ���Ա�:");
			scanf_s("%s", Gender, 4);
			sign = 0;
		}
		else {
			printf("��������ȷ������");
		}
	}
	if (isDuplicate(name)) {
		char id[11] = { NULL };
		printf("���ظ����������������Ӧѧ��:");
		scanf_s("%s", id, 11);
		changeString("�Ա�", Gender, name,id);
	}
	if(!isDuplicate(name))
	changeString("�Ա�", Gender, name);
}




