#include "mysqlConfige.h"
int  Failed(const char* id) {
	//����
	MYSQL* connect = mysqlConnect();
	char mysql[N];
	//ȡquery
	sprintf_s(mysql, "	select count(*) from student where ѧ�� = '%s' and (��ѧ�ɼ� < 60 or Ӣ��ɼ� < 60 or �����ɼ� < 60 or c���Գɼ�)",
		id);
	if (mysql_query(connect, mysql)) {
		fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
	}
    //ȡ�����
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
