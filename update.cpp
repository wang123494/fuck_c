#include <stdio.h>
#include <string.h>
#include "head.h"
#include "update.h"
void signIn();
bool teacherConnect(const char* account, const char* passport);
void update() {
	system("color f0");
	printf("\t\t\t你想选择更改什么内容?\n");
	printf("\t\t\t0.学号\n");
	printf("\t\t\t1.姓名\n");	
	printf("\t\t\t2.性别\n");
	printf("\t\t\t3.数学成绩\n");

	unsigned int number;
	scanf_s("%d", &number);
	switch (number) {
	case 0: 
		system("cls");
		updateId();
		break;
	case 1 : 
		system("cls");
		updateName();
		break;
	case 2:
		system("cls");
		updateGender();
		break;
	case 3:
		system("cls");
		changeNumber("数学成绩");
		break;
	}
	

}



void updateId() {
	char id[11] = {NULL};
	char name[40];
	printf("输入你想更改的姓名:");
	scanf_s("%s",name,40);
	printf("输入更改后的学号");
	scanf_s("%s",id,11);
	changeString("学号",id,name);
}
void updateName() {
	char preName[40] = {NULL};
	char afterName[40] = {NULL};
	do {
		//初始化
		memset(preName, NULL, 40);
		memset(afterName, NULL, 40);
		printf("输入你想更改的姓名:");
		scanf_s("%s", preName, 40);
		printf("输入你更改后的姓名:");
		scanf_s("%s", afterName, 40);
		if (!strcmp(preName, afterName)) printf("输入错误\n"); 

	} while (!strcmp(preName, afterName));

	if (isDuplicate(preName)) {
		char id[11] = {NULL};
		printf("有重复的人名，请输入对应学号:");
		scanf_s("%s",id,11);
		changeString("姓名", afterName, preName, id);
	}
	else {
		changeString("姓名", afterName, preName);
	}
	//如果姓名重复就依靠学号修改
	//文件输入


}
void updateGender() {
	char name[40];
	printf("你想更改谁的性别?\n");
	scanf_s("%s", name, 40);

	char Gender[4] = "男";

	printf("你想将他的性别改成什么?\n");
	int sign = 1;
	while (sign) {
		if (strcmp(Gender, "男") == 0 || strcmp(Gender, "女") == 0) {
			printf("输入你更改后的性别:");
			scanf_s("%s", Gender, 4);
			sign = 0;
		}
		else {
			printf("请输入正确的内容");
		}
	}
	if (isDuplicate(name)) {
		char id[11] = { NULL };
		printf("有重复的人名，请输入对应学号:");
		scanf_s("%s", id, 11);
		changeString("性别", Gender, name,id);
	}
	if(!isDuplicate(name))
	changeString("性别", Gender, name);
}




