#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "signIn.h"


int signIn() {
	int chose = 0;
	printf("1:教师端登录\n");
	printf("2:学生端登录\n");
	scanf_s("%d", &chose);

	if (chose == 1) {
		printf("请输入你的账户(学号):");
		char account[20];
		scanf_s("%s", account, 20);
		printf("请输入你的密码:");
		char passport[20];
		scanf_s("%s", passport, 20);
		int sign = 0;
		do {
			if (teacherConnect(account, passport)) {
				printf("登录成功!");
				Sleep(100);
				sign = 0;
				system("cls");
				return 1;
				//调用其他函数

			}
			else {
				printf("登录失败，您输入的账号或密码有错误，请重新输入");
				sign = 1;
			}
		} while (sign);
	}
	if (chose == 2) {
		printf("请输入你的账户:");
		char account[20];
		scanf_s("%s", account, 20);
		printf("请输入你的密码:");
		char passport[20];
		scanf_s("%s", passport, 20);
		int sign = 0;
		do {
			if (studentConnect(account, passport)) {
				printf("登录成功");
				Sleep(100);
				sign = 0;
				system("cls");
				return 2;

			}
			else {
				printf("登录失败，您输入的账号或密码有错误，请重新输入");
				sign = 1;
			}
		} while (sign);
	}
	if (chose != 1 && chose != 2) {
		printf("请输入正确的内容");
		return 0;
	}
}