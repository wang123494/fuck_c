#include <stdio.h>
#include <windows.h>
#include <mysql.h>
#include "head.h"
#include "update.h"
#include "select.h"
#include "signIn.h"
int main(void) {

	Student stu;
	//getBM(&stu);
	//add(stu);
	system("cls");

	signIn();

	system("color f0");
	return 0;
}