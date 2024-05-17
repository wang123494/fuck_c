//需要mysql配置文件
//需要printf文件
#include "mysqlConfige.h"
#include "add.h"

//用指针 在这里用->而不是 .
void getBM(Student* stu) {
	printf("请输入学号:");
	scanf_s("%s", stu->id, 11);
	printf("请输入姓名:");
	scanf_s("%s", stu->name, 40);
	printf("请输入性别:");
	scanf_s("%s", stu->gender, 4);
	printf("请输入数学成绩:");
	scanf_s("%lf", &stu->scoreOfMath);
	printf("请输入大学英语成绩");
	scanf_s("%lf", &stu->scoreOfEnglish);
	printf("请输入体育成绩");
	scanf_s("%lf",&stu->scoreOfPE);
	printf("请输入c语言成绩");
	scanf_s("%lf",&stu->scoreOfCProgramming);
}

void addRow() {
	Student stu;
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    getBM(&stu);
    sprintf_s(mysql, "insert into student (学号,姓名, 性别,数学成绩,英语成绩,体育成绩,c语言成绩) values('%s','%s','%s',%lf,%lf,%lf,%lf)",
        stu.id, stu.name, stu.gender, stu.scoreOfMath,stu.scoreOfEnglish,stu.scoreOfPE,stu.scoreOfCProgramming);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}


