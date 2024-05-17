#include "select.h"
#include "windows.h"
#include <stdio.h>
void select() {
	system("color f0");
	printf("\t\t\t你想选择查询什么内容?\n");
	printf("\t\t\t0.全部\n");
	printf("\t\t\t1.姓名\n");
	printf("\t\t\t2.数学成绩\n");

	unsigned int number;
	scanf_s("%d", &number);
	switch (number) {
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
		showColumn("姓名,性别,");
		break;
	}
}




