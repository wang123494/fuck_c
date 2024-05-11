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
    //����mysql
    MYSQL* connect = mysql_init(NULL);

    //�����ַ�����
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK"); //��ȷ���������ַ�  connect

    //����mysql,���ӳ����ӡ������Ϣ
    if (!mysql_real_connect(connect, host, userName, passport, databaseName, localHost, NULL, 0)) {
        fprintf(stderr, "failed to connect to database: Error: %s", mysql_error(connect));
    }
    
    
    return connect;

}



void addRow(Student stu) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    getBM(&stu);
    sprintf_s(mysql, "insert into student (ѧ��,����, �Ա�,��ѧ�ɼ�) values('%s','%s','%s',%lf)",
        stu.id,stu.name, stu.gender,stu.scoreOfMath);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}
void deleteRow() {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    char name[40];
    printf("����������ɾ��������:");
    scanf_s("%s", name, 40);
    sprintf_s(mysql, "delete from student where ���� = '%s'",
        name);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to delete data : Error:%s\n", mysql_error(connect));
    }
}



void showData() {
    MYSQL* connect = mysqlConnect();
       //sql���
    const char* mysql = "select ѧ��, ����, �Ա�, ��ѧ�ɼ� from student";
    
    
    
    //ִ��sql���
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
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
        MYSQL_FIELD * field = mysql_fetch_field_direct(result, i);
        printf("%-13s ",field->name);
    }
    printf("\n");

    ////��2:
    //MYSQL_FIELD* field = 0;
    //while (field = mysql_fetch_field(result)) {
    //    printf("key: %s\n", field->name);
    //}

    MYSQL_ROW row ;
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
    sprintf_s(mysql,"select ѧ��, %s from student"
        ,s0);
    if (mysql_query(connect,mysql)) {
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
        sprintf_s(mysql,"select * from student where ���� = '%s' ,ѧ�� = '%s'",
            name,name1);
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
    sprintf_s(mysql,"update student set %s = '%s' where ���� = '%s'"
    ,s0,s1,s2); 
    
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed to change data : Error:%s\n", mysql_error(connect));
    }
}
void changeString(const char* s0, char* s1, char* s2,char* s3) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    sprintf_s(mysql, "update student set %s = '%s' where ���� = '%s' and ѧ�� = '%s'"
        , s0, s1, s2,s3);

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
            , s0,number,name,id);
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
int isDuplicate(const char* s0) {
    MYSQL* connect = mysqlConnect();
    //sql���
    char mysql[N] = {0};

    sprintf_s(mysql,"SELECT COUNT(*) FROM student WHERE ���� = '%s'",s0);

    //ִ��sql���
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
    MYSQL_RES* result = mysql_use_result(connect);
    //use���Ὣ������ù���,ֻ����ʾ����ʵ�ʶ�ȡ
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
    MYSQL_ROW row;
    unsigned long num_rows = 0;
    if ((row = mysql_fetch_row(result)) != NULL) {
        num_rows = atoi(row[0]); // �� COUNT(*) ֵת��Ϊ�������洢�� num_rows ������
        if (num_rows > 1) return 1;
        else return 0;
    }
    mysql_free_result(result);
    mysql_close(connect);
    return num_rows;

    
}


double getMax(const char* subject) {
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = {0};
    sprintf_s(mysql,"select max(%s) from student",
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


void sortBy(const char* subject) {
    //����
    MYSQL* connect = mysqlConnect();
    char  mysql[N] = { 0 };
    sprintf_s(mysql, "select ����,ѧ��,%s from student order by %s desc",
       subject,subject);
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
            printf("%-14s",row[i]);
                
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(connect);

}


