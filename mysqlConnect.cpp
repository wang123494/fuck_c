#include <stdio.h>
#include "head.h"
#include <mysql.h>
const char* host = "127.0.0.1";
const char* userName = "root";
const char* passport = "wang0703";
const char* databaseName = "studentsManager";
const int localHost = 3306;
void mysqlConnect() {
    //链接mysql
    MYSQL* connect = mysql_init(NULL);

    //设置字符编码
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK"); //正确处理中文字符  connect

    //链接mysql,链接出错打印错误信息
    if (!mysql_real_connect(connect, host, userName, passport, databaseName, localHost, NULL, 0)) {
        fprintf(stderr, "failed to connect to database: Error: %s", mysql_error(connect));
    }
    Student stu = { "demo","男" };
    char mysql[1024];
    sprintf_s(mysql, "insert into student (name, gender) values('%s','%s')",
        stu.name, stu.gender);

    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}