#include "signIn.h"
#include "select.h"
#include <stdio.h>
void subjectChoice(const char* name) {
	printf("1-��ѧ�ɼ�����\n");
	printf("2-Ӣ��ɼ�����\n");
	printf("������ѡ������鿴�ĳɼ�:");
	int choice = 0;
	scanf_s("%d",&choice);
	switch (choice)
	{
	case 1: {
		ranking(name, "��ѧ�ɼ�");
	}
	case 2: {
		ranking(name, "Ӣ��ɼ�");
	}

	default:
		printf("��������ȷ������");
		break;
	}
}