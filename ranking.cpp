#include "select.h"
#include "mysqlConfige.h"
#include "judge.h"
void ranking(const char* name ,const char* subject) {
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
        sprintf_s(mysql, "select 学号,姓名,%s,(select count(*) + 1 from student s2 where s2.%s > s1.%s) as %s排名 from student s1 where 姓名 = '%s' ",
            subject,subject,subject,subject,name
        );
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