#include <stdio.h>
#include "head.h"
#include <mysql.h>
const char* host = "127.0.0.1";
const char* userName = "root";
const char* passport = "wang0703";
const char* databaseName = "studentsManager";
const int localHost = 3306;
void mysqlConnect() {
    //����mysql
    MYSQL* connect = mysql_init(NULL);

    //�����ַ�����
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK"); //��ȷ���������ַ�  connect

    //����mysql,���ӳ����ӡ������Ϣ
    if (!mysql_real_connect(connect, host, userName, passport, databaseName, localHost, NULL, 0)) {
        fprintf(stderr, "failed to connect to database: Error: %s", mysql_error(connect));
    }
    Student stu = { "demo","��" };
    char mysql[1024];
    sprintf_s(mysql, "insert into student (name, gender) values('%s','%s')",
        stu.name, stu.gender);

    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}