#include <stdio.h>
#include "signIn.h"
#include "mysqlConfige.h"
bool teacherConnect(const char* Account ,const char* passport) {
	MYSQL* connect = mysqlConnect();
	char mysql[256] = { 0 };
	sprintf_s(mysql,"select count(*) from teacher_account where �˺� = '%s' and ���� = '%s'",
		Account,passport);
	if (mysql_query(connect, mysql)) {
		fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
	}
	MYSQL_RES* result = mysql_use_result(connect);
	MYSQL_ROW row;
	int count;
	if (row = mysql_fetch_row(result)) {
		count = atoi(row[0]);
	}
	return count;
}