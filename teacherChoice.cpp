#include<stdio.h>
#include <Windows.h>
#include "CRUD.h"
void teacherChoice() {
	int sign = 1;
	do {
		printf("\n\n\n");
		printf("输入以查询您想看的内容\n");
		printf("\t\t\t1:查看成绩\n");
		printf("\t\t\t2:查看某科最大值\n");
		printf("\t\t\t3:查看某科的平均分\n");
		printf("\t\t\t4:查看某科的最小值\n");
		printf("\t\t\t5:更改\n");
		printf("\t\t\t6:删除某人\n");
		printf("\t\t\t7:增加内容 \n");
		printf("\t\t\t");
		printf("0:退出\n");

		int number;
		scanf_s("%d", &number);
		switch (number)
		{
		case 1: {
			system("cls");
			select();
			break;
		}
		case 2: {
			system("cls");
			selectMax();
			break;
		}
		case 3: {
			system("cls");
			selectAver();
			break;
		}
		case 4: {
			system("cls");
			selectMin();
			break;
		}
		case 5: {
			system("cls");
			update();
			break;
		}
		case 6: {
			system("cls");
			deleteRow();
			break;
		}
		case 7: {
			system("cls");
			addRow();
			break;
		}
		case 0:{
				  sign = 0;
				  exit(0);
				  break;
		}
		default:
			printf("输入错误");
			break;
		
		}
	} while (sign);

}