#include "select.h"
#include "windows.h"
#include <stdio.h>
void select() {
	int sign = 1;
	do {
		system("color f0");
		printf("\n\n");
		printf("\t\t\t你想选择查询什么内容?\n");
		printf("\t\t\t-1.返回上一级\n");
		printf("\t\t\t0.全部\n");
		printf("\t\t\t1.姓名\n");
		printf("\t\t\t2.数学成绩\n");
		printf("\t\t\t3.英语成绩\n");
		printf("\t\t\t4.体育成绩\n");
		printf("\t\t\t5.c语言成绩\n");
		unsigned int number;
		scanf_s("%d", &number);
		switch (number) {
		case -1:
			sign = 0;
			break;
		case 0:
			system("cls");
			showData();
			break;
		case 1:
			system("cls");
			showColumn("姓名");
			break;
		case 2:
			system("cls");
			showColumn("姓名,性别,数学成绩");

			break;
		case 3:
			system("cls");
			showColumn("姓名,性别,英语成绩");
			break;
		case 4:
			system("cls");
			showColumn("姓名,性别,体育成绩");
			break;
		case 5:
			system("cls");
			showColumn("姓名,性别,c语言成绩");
			break;
			
			
		default:printf("您的输入有误.");
			break;
		}
	} while (sign);
	
}




