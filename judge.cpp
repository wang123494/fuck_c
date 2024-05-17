#include "judge.h"
#include "mysqlConfige.h"
int isDuplicate(const char* s0) {
    MYSQL* connect = mysqlConnect();
    //sql语句
    char mysql[N] = { 0 };

    sprintf_s(mysql, "SELECT COUNT(*) FROM student WHERE 姓名 = '%s'", s0);

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
