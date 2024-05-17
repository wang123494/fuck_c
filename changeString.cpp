#include "update.h"
#include "mysqlConfige.h"
#include "judge.h"
void changeString(const char* s0, char* s1, char* s2) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "update student set %s = '%s' where 姓名 = '%s'"
        , s0, s1, s2);

    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
void changeString(const char* s0, char* s1, char* s2, char* s3) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "update student set %s = '%s' where 姓名 = '%s' and 学号 = '%s'"
        , s0, s1, s2, s3);

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
            , s0, number, name, id);
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
