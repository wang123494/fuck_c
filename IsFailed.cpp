#include "mysqlConfige.h"
int  Failed(const char* id) {
	//链接
	MYSQL* connect = mysqlConnect();
	char mysql[N];
	//取query
	sprintf_s(mysql, "	select count(*) from student where 学号 = '%s' and (数学成绩 < 60 or 英语成绩 < 60 or 体育成绩 < 60 or c语言成绩)",
		id);
	if (mysql_query(connect, mysql)) {
		fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
	}
    //取结果集
    MYSQL_RES* result = mysql_use_result(connect);
    if (!result) {
        printf("mysql_use_result failed : Error %s\n", mysql_error(connect));
    }
    //get field
   
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(result))) {
        return atoi(row[0]);
    }

    mysql_free_result(result);
    mysql_close(connect);
}
