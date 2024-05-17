#include <stdio.h>
#include <windows.h>
#include "select.h"
#include "signIn.h"
#include "judge.h"
void studentChoice() {
	printf("请输入你的学号");
	char id[11];
	scanf_s("%s",id,11);
	int sign = 1;
	char* name = getName(id);
	
	do {
	
		printf("\t\t选择你想进行的内容\n");
		printf("\t\t返回菜单栏\n");
		printf("\t\t1: 查看个人成绩\n");
		printf("\t\t2: 查看班级排名\n");
		printf("\t\t3: 挂科查询\n");
		printf("\t\t: 退出");
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
				printf("抱歉，您有挂科科目\n");
			}
			else {
				printf("恭喜，您并未有挂科科目\n");
			}
			break;
		}
		case -1: {
			sign = 0;
			break;
		}
		default:
			printf("请输入正确的内容");
			break;
		}
	} while (sign)
		;
}