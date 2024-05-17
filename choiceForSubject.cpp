#include "signIn.h"
#include "select.h"
#include <stdio.h>
void subjectChoice(const char* name) {
	printf("1-数学成绩排名\n");
	printf("2-英语成绩排名\n");
	printf("3-体育成绩排名\n");
	printf("4-c语言成绩排名\n");
	printf("输入以选择你想查看的成绩:");
	int choice = 0;
	scanf_s("%d",&choice);
	switch (choice)
	{
	case 1: {
		ranking(name, "数学成绩");
		break;
	}
	case 2: {
		ranking(name, "英语成绩");
		break;
	}
	case 3: {
		ranking(name, "体育成绩");
		break;

	}
	case 4:
		ranking(name,"c语言成绩");
		break;


	default:
		printf("请输入正确的内容");
		break;
	}
}