//需要mysql配置文件
//需要printf文件
#include "mysqlConfige.h"
#include "add.h"

//用指针 在这里用->而不是 .
void getBM(Student* stu) {
	printf("请输入你的学号:");
	scanf_s("%s", stu->id, 11);
	printf("请输入你的姓名:");
	scanf_s("%s", stu->name, 40);
	printf("请输入你的性别:");
	scanf_s("%s", stu->gender, 4);
	printf("请输入你的数学成绩:");
	scanf_s("%lf", &stu->scoreOfMath);
}

void addRow(Student stu) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    getBM(&stu);
    sprintf_s(mysql, "insert into student (学号,姓名, 性别,数学成绩) values('%s','%s','%s',%lf)",
        stu.id, stu.name, stu.gender, stu.scoreOfMath);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}


