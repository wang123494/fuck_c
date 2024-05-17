#include "mysqlConfige.h"


bool studentConnect(const char* Account, const char* passport) {
	MYSQL* connect = mysqlConnect();
	char mysql[256] = { 0 };
	sprintf_s(mysql, "select count(*) from student_account where ’À∫≈ = '%s' and √‹¬Î = '%s'",
		Account, passport);
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


