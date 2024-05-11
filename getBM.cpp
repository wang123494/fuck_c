//得到基本的信息
#include "head.h"
//用指针 在这里用->而不是 .
void getBM(Student* stu) {
		printf("请输入你的学号:");
		scanf_s("%s",stu->id,11);
		printf("请输入你的姓名:");
		scanf_s("%s", stu->name, 40);
		printf("请输入你的性别:");
		scanf_s("%s", stu->gender, 4);
		printf("请输入你的数学成绩:");
		scanf_s("%lf", &stu->scoreOfMath);
}