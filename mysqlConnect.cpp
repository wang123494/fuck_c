#include "mysqlConfige.h"


const char* HOST = "127.0.0.1";
const char* USERNAME = "root";
const char* PASSPORT  = "wang0703";
const char* DATABASENAME = "studentsManager";

MYSQL* mysqlConnect() {
    MYSQL* connect = mysql_init(NULL);
    unsigned int PORT = 3306; // ���ı�����Ϊ������������

    // �����ַ�����
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK");

    // ���� MySQL�����ӳ����ӡ������Ϣ
    if (!mysql_real_connect(connect, HOST, USERNAME, PASSPORT, DATABASENAME, PORT, NULL, 0)) {
        fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(connect)); // ��ӻ��з�
        return NULL;
    }
   

    return connect;
}
