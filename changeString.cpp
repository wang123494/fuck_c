#include "update.h"
#include "mysqlConfige.h"
#include "judge.h"
void changeString(const char* s0, char* s1, char* s2) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "update student set %s = '%s' where ���� = '%s'"
        , s0, s1, s2);

    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
void changeString(const char* s0, char* s1, char* s2, char* s3) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "update student set %s = '%s' where ���� = '%s' and ѧ�� = '%s'"
        , s0, s1, s2, s3);

    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
void changeNumber(const char* s0) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    printf("������������ĵ��˵�����:");
    char name[40];
    scanf_s("%s", name, 40);

    if (isDuplicate(name)) {
        char id[11] = { NULL };
        printf("��⵽���ظ����������������Ӧѧ��:");
        scanf_s("%s", id, 11);
        double number;
        printf("����������ĺ�ĳɼ�:");
        scanf_s("%lf", &number);
        sprintf_s(mysql, "update student set %s = %lf where ���� = '%s' and ѧ�� = '%s'"
            , s0, number, name, id);
    }
    else {
        double number;
        printf("����������ĺ�ĳɼ�:");
        scanf_s("%lf", &number);
        sprintf_s(mysql, "update student set %s = %lf where ���� = '%s'"
            , s0, number, name);
    }
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
