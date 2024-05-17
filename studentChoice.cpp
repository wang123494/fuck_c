#include <stdio.h>
#include <windows.h>
#include "select.h"
#include "signIn.h"
void studentChoice() {
	printf("请输入你的学号");
	char id[11];
	scanf_s("%s",id,11);
	char* name = getName(id);
	printf("\t\t选择你想进行的内容\n");
	printf("\t\t1: 查看个人成绩\n");
	printf("\t\t2: 查看班级排名\n");
	printf("\t\t3: 查看某科排名\n");
	printf("\t\t4: 奖学金查询\n");
	printf("\t\tQ: 退出");
	int choice = 0;
	do {
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0: {
			system("cls");
			printf("\t\t选择你想进行的内容\n");
			printf("\t\t返回菜单栏\n");
			printf("\t\t1: 查看个人成绩\n");
			printf("\t\t2: 查看班级排名\n");
			printf("\t\t3: 查看某科排名\n");
			printf("\t\t4: 奖学金查询\n");
			printf("\t\tQ: 退出");
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
			
			printf("请输入正确的内容");
			break;
		}
	} while (choice)
		;
}