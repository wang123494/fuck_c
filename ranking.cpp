#include "select.h"
#include "mysqlConfige.h"
#include "judge.h"
void ranking(const char* name ,const char* subject) {
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
        sprintf_s(mysql, "select ѧ��,����,%s,(select count(*) + 1 from student s2 where s2.%s > s1.%s) as %s���� from student s1 where ���� = '%s' ",
            subject,subject,subject,subject,name
        );
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