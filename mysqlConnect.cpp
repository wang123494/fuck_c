#include <stdio.h>
#include <mysql.h>
#include "head.h"
#include <string.h>
const int N = 256;


extern const char* host = "127.0.0.1";
const char* userName = "root";
const char* passport = "wang0703";
const char* databaseName = "studentsManager";
const int localHost = 3306;


MYSQL* mysqlConnect() {
    //链接mysql
    MYSQL* connect = mysql_init(NULL);

    //设置字符编码
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK"); //正确处理中文字符  connect

    //链接mysql,链接出错打印错误信息
    if (!mysql_real_connect(connect, host, userName, passport, databaseName, localHost, NULL, 0)) {
        fprintf(stderr, "failed to connect to database: Error: %s", mysql_error(connect));
    }
    
    
    return connect;

}



void addRow(Student stu) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    getBM(&stu);
    sprintf_s(mysql, "insert into student (学号,姓名, 性别,数学成绩) values('%s','%s','%s',%lf)",
        stu.id,stu.name, stu.gender,stu.scoreOfMath);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}
void deleteRow() {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    char name[40];
    printf("请输入你想删除的名字:");
    scanf_s("%s", name, 40);
    sprintf_s(mysql, "delete from student where 姓名 = '%s'",
        name);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to delete data : Error:%s\n", mysql_error(connect));
    }
}



void showData() {
    MYSQL* connect = mysqlConnect();
       //sql语句
    const char* mysql = "select 学号, 姓名, 性别, 数学成绩 from student";
    
    
    
    //执行sql语句
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
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
        MYSQL_FIELD * field = mysql_fetch_field_direct(result, i);
        printf("%-13s ",field->name);
    }
    printf("\n");

    ////法2:
    //MYSQL_FIELD* field = 0;
    //while (field = mysql_fetch_field(result)) {
    //    printf("key: %s\n", field->name);
    //}

    MYSQL_ROW row ;
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
    sprintf_s(mysql,"select 学号, %s from student"
        ,s0);
    if (mysql_query(connect,mysql)) {
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
        sprintf_s(mysql,"select * from student where 姓名 = '%s' ,学号 = '%s'",
            name,name1);
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
        MYSQL_FIELD* field = mysql_fetch_field_direct(result ,i);
        printf("%-13s",field -> name);
    }
    printf("\n");
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%-13s", row[i]);
        }
    }
   
}



void changeString(const char* s0 ,char* s1,char* s2) {
    MYSQL* connect= mysqlConnect();
    char mysql[N]; 
    sprintf_s(mysql,"update student set %s = '%s' where 姓名 = '%s'"
    ,s0,s1,s2); 
    
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
void changeString(const char* s0, char* s1, char* s2,char* s3) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "update student set %s = '%s' where 姓名 = '%s' and 学号 = '%s'"
        , s0, s1, s2,s3);

    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}


void changeNumber(const char* s0) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    printf("请输入你想更改的人的名字:");
    char name[40];
    scanf_s("%s", name, 40);
    
    if (isDuplicate(name)) {
        char id[11] = { NULL };
        printf("检测到有重复的姓名，请输入对应学号:");
        scanf_s("%s", id, 11);
        double number;
        printf("请输入你更改后的成绩:");
        scanf_s("%lf", &number);
        sprintf_s(mysql, "update student set %s = %lf where 姓名 = '%s' and 学号 = '%s'"
            , s0,number,name,id);
    }
    else {
        double number;
        printf("请输入你更改后的成绩:");
        scanf_s("%lf", &number);
        sprintf_s(mysql, "update student set %s = %lf where 姓名 = '%s'"
            , s0, number, name);
    }
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
int isDuplicate(const char* s0) {
    MYSQL* connect = mysqlConnect();
    //sql语句
    char mysql[N] = {0};

    sprintf_s(mysql,"SELECT COUNT(*) FROM student WHERE 姓名 = '%s'",s0);

    //执行sql语句
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    //use不会将结果调用过来,只会显示，不实际读取
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    MYSQL_ROW row;
    unsigned long num_rows = 0;
    if ((row = mysql_fetch_row(result)) != NULL) {
        num_rows = atoi(row[0]); // 将 COUNT(*) 值转换为整数并存储到 num_rows 变量中
        if (num_rows > 1) return 1;
        else return 0;
    }
    mysql_free_result(result);
    mysql_close(connect);
    return num_rows;

    
}


double getMax(const char* subject) {
    //链接
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = {0};
    sprintf_s(mysql,"select max(%s) from student",
        subject);
    //取结果集
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
    //链接
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select avg(%s) from student",
        subject);
    //取结果集
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
    //链接
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select min(%s) from student",
        subject);
    //取结果集
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


void sortBy(const char* subject) {
    //链接
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select 姓名,学号,%s from student order by %s desc",
       subject,subject);
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
            printf("%-14s",row[i]);
                
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(connect);

}


