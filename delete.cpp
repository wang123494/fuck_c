#include "delete.h"
#include "mysqlConfige.h"

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