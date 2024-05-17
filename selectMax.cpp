#include <stdio.h>
#include <windows.h>
#include "select.h"
void selectMax(){
	int sign = 1;
	do {
		double scoreOfMath = 0;
		double scoreOfEnglish = 0;
		double scoreOfPE = 0;
		double scoreOfCProgramming = 0;
		system("color f0");
		printf("\n\n");
		printf("\t\t\t你想选择查询什么内容?\n");
		printf("\t\t\t-1.返回上一级\n");
		printf("\t\t\t1.数学成绩\n");
		printf("\t\t\t2.英语成绩\n");
		printf("\t\t\t3.体育成绩\n");
		printf("\t\t\t4.c语言成绩\n");
		unsigned int number;
		scanf_s("%d", &number);
		switch (number) {
		case -1:
			sign = 0;
			break;
		case 1:
			system("cls");
			scoreOfMath =getMax("数学成绩");
			printf("数学成绩最大值为%lf",scoreOfMath);
			break;
		case 2:
			system("cls");
			scoreOfEnglish = getMax("英语成绩");
			printf("数学成绩最大值为%lf", scoreOfEnglish);
			break;
		case 3:
			system("cls");
			scoreOfPE = getMax("体育成绩");
			printf("体育成绩最大值为%lf", scoreOfPE);
			break;
		case 4:
			system("cls");
			scoreOfCProgramming = getMax("c语言成绩");
			printf("c语言成绩最大值为%lf", scoreOfCProgramming);

			break;
		default:printf("您的输入有误.");
			break;
		}
	} while (sign);

}
