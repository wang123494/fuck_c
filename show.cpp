#include "select.h"
#include "mysqlConfige.h"
#include "judge.h"
void showData() {
    MYSQL* connect = mysqlConnect();
    //sql语句
    const char* mysql = "select * from student";


    if (connect == NULL) {
        printf("error what the fuck");
    }
    //执行sql语句
    //这里有问题
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error: %s \n", mysql_error(connect));
    }
    //  MYSQL_RES* result = mysql_use_result(connect);

   //执行sql语句后，必须获取结果集并且清理
   //获取结果集
    //store会将结果调用过来，读取数据
    MYSQL_RES* result = mysql_use_result(connect);
    //use不会将结果调用过来,只会显示，不实际读取
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //显示标题
    //法1:获取表字段
    unsigned long num_fields = mysql_num_fields(result);
    for (int i = 0; i < num_fields; i++) {
        //取字段
        MYSQL_FIELD* field = mysql_fetch_field_direct(result, i);
        printf("%-13s ", field->name);
    }
    printf("\n");

    ////法2:
    //MYSQL_FIELD* field = 0;
    //while (field = mysql_fetch_field(result)) {
    //    printf("key: %s\n", field->name);
    //}

    MYSQL_ROW row;
    //取行
    while (row = mysql_fetch_row(result)) {
        //取列
        for (int i = 0; i < num_fields; i++) {
            //打印第一行的所有列
            printf("%-13s ", row[i]);
        }
        printf("\n");
    }

    //清理mysql
    mysql_free_result(result);
    mysql_close(connect);

}
void showColumn(const char* s0) {
    //链接
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "select 学号, %s from student"
        , s0);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }

    //取结果集
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //取列
    unsigned long num_fields = mysql_num_fields(result);
    for (int i = 0; i < num_fields; i++) {
        //取字段
        MYSQL_FIELD* field = mysql_fetch_field_direct(result, i);
        printf("%-13s", field->name);
    }
    printf("\n");

    MYSQL_ROW row;
    while (row = mysql_fetch_row(result)) {
        for (int i = 0; i < num_fields; i++) {
            printf("%-13s", row[i]);
        }
        printf("\n");
    }
    mysql_free_result(result);
    mysql_close(connect);

}
void showRow(const char* name) {
    //链接
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    if (isDuplicate(name)) {
        printf("检测到输入的有重复，请输入学号确认是哪个学生");
        char name1[40] = { 0 };
        scanf_s("%s", name1, 40);
        sprintf_s(mysql, "select * from student where 姓名 = '%s' ,学号 = '%s'",
            name, name1);
    }
    if (!isDuplicate(name)) {
        sprintf_s(mysql, "select * from student where 姓名 = '%s'",
            name);
    }
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }

    //取结果集
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //取字段
    unsigned long num_fields = mysql_num_fields(result);
    for (int i = 0; i < num_fields; i++) {
        MYSQL_FIELD* field = mysql_fetch_field_direct(result, i);
        printf("%-13s", field->name);
    }
    printf("\n");
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%-13s", row[i]);
        }
    }

}


void sortBy(const char* subject) {
    //链接
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select 姓名,学号,%s from student order by %s desc",
        subject, subject);
    //取结果集
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    unsigned long num_fields = mysql_num_fields(result);
    for (int i = 0; i < num_fields; i++) {
        //取字段
        MYSQL_FIELD* field = mysql_fetch_field_direct(result, i);
        printf("%-14s", field->name);
    }
    printf("\n");
    MYSQL_ROW row;
    unsigned long num_rows = 0;
    while (row = mysql_fetch_row(result)) {
        for (int i = 0; i < num_fields; i++) {
            printf("%-14s", row[i]);

        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(connect);

}
