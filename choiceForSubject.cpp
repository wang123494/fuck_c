#include "signIn.h"
#include "select.h"
#include <stdio.h>
void subjectChoice(const char* name) {
	printf("1-��ѧ�ɼ�����\n");
	printf("2-Ӣ��ɼ�����\n");
	printf("3-�����ɼ�����\n");
	printf("4-c���Գɼ�����\n");
	printf("������ѡ������鿴�ĳɼ�:");
	int choice = 0;
	scanf_s("%d",&choice);
	switch (choice)
	{
	case 1: {
		ranking(name, "��ѧ�ɼ�");
		break;
	}
	case 2: {
		ranking(name, "Ӣ��ɼ�");
		break;
	}
	case 3: {
		ranking(name, "�����ɼ�");
		break;

	}
	case 4:
		ranking(name,"c���Գɼ�");
		break;


	default:
		printf("��������ȷ������");
		break;
	}
}