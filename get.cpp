#include "update.h"
#include "mysqlConfige.h"


double getMax(const char* subject) {
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select max(%s) from student",
        subject);
    //ȡ�����
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    MYSQL_ROW row;
    unsigned long num_rows = 0;

    if ((row = mysql_fetch_row(result)) != NULL) {
        num_rows = atof(row[0]);
    }
    mysql_free_result(result);
    mysql_close(connect);
    return num_rows;




}
double getAverage(const char* subject) {
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select avg(%s) from student",
        subject);
    //ȡ�����
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    MYSQL_ROW row;
    unsigned long num_rows = 0;

    if ((row = mysql_fetch_row(result)) != NULL) {
        num_rows = atof(row[0]);
    }
    mysql_free_result(result);
    mysql_close(connect);
    return num_rows;




}
double getMin(const char* subject) {
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select min(%s) from student",
        subject);
    //ȡ�����
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    MYSQL_ROW row;
    unsigned long num_rows = 0;

    if ((row = mysql_fetch_row(result)) != NULL) {
        num_rows = atof(row[0]);
    }
    mysql_free_result(result);
    mysql_close(connect);
    return num_rows;




}
char* getName(const char* id) {
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select ���� from student_account where �˺� = '%s'",
            id);
    //ȡ�����
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    MYSQL_ROW row;
    unsigned long num_rows = 0;

    if ((row = mysql_fetch_row(result)) != NULL) {
        printf("����:%s\n",row[0]);
        return row[0];
    }
    
    mysql_free_result(result);
    mysql_close(connect);





}