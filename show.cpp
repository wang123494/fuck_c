#include "select.h"
#include "mysqlConfige.h"
#include "judge.h"
void showData() {
    MYSQL* connect = mysqlConnect();
    //sql���
    const char* mysql = "select * from student";


    if (connect == NULL) {
        printf("error what the fuck");
    }
    //ִ��sql���
    //����������
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error: %s \n", mysql_error(connect));
    }
    //  MYSQL_RES* result = mysql_use_result(connect);

   //ִ��sql���󣬱����ȡ�������������
   //��ȡ�����
    //store�Ὣ������ù�������ȡ����
    MYSQL_RES* result = mysql_use_result(connect);
    //use���Ὣ������ù���,ֻ����ʾ����ʵ�ʶ�ȡ
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //��ʾ����
    //��1:��ȡ���ֶ�
    unsigned long num_fields = mysql_num_fields(result);
    for (int i = 0; i < num_fields; i++) {
        //ȡ�ֶ�
        MYSQL_FIELD* field = mysql_fetch_field_direct(result, i);
        printf("%-13s ", field->name);
    }
    printf("\n");

    ////��2:
    //MYSQL_FIELD* field = 0;
    //while (field = mysql_fetch_field(result)) {
    //    printf("key: %s\n", field->name);
    //}

    MYSQL_ROW row;
    //ȡ��
    while (row = mysql_fetch_row(result)) {
        //ȡ��
        for (int i = 0; i < num_fields; i++) {
            //��ӡ��һ�е�������
            printf("%-13s ", row[i]);
        }
        printf("\n");
    }

    //����mysql
    mysql_free_result(result);
    mysql_close(connect);

}
void showColumn(const char* s0) {
    //����
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "select ѧ��, %s from student"
        , s0);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }

    //ȡ�����
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //ȡ��
    unsigned long num_fields = mysql_num_fields(result);
    for (int i = 0; i < num_fields; i++) {
        //ȡ�ֶ�
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
    //����
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    if (isDuplicate(name)) {
        printf("��⵽��������ظ���������ѧ��ȷ�����ĸ�ѧ��");
        char name1[40] = { 0 };
        scanf_s("%s", name1, 40);
        sprintf_s(mysql, "select * from student where ���� = '%s' ,ѧ�� = '%s'",
            name, name1);
    }
    if (!isDuplicate(name)) {
        sprintf_s(mysql, "select * from student where ���� = '%s'",
            name);
    }
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }

    //ȡ�����
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //ȡ�ֶ�
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
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select ����,ѧ��,%s from student order by %s desc",
        subject, subject);
    //ȡ�����
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
        //ȡ�ֶ�
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
