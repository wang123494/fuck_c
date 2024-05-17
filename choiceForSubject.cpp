#include "signIn.h"
#include "select.h"
#include <stdio.h>
void subjectChoice(const char* name) {
	printf("1-数学成绩排名\n");
	printf("2-英语成绩排名\n");
	printf("输入以选择你想查看的成绩:");
	int choice = 0;
	scanf_s("%d",&choice);
	switch (choice)
	{
	case 1: {
		ranking(name, "数学成绩");
	}
	case 2: {
		ranking(name, "英语成绩");
	}

	default:
		printf("请输入正确的内容");
		break;
	}
}