#include "mysqlConfige.h"


const char* HOST = "127.0.0.1";
const char* USERNAME = "root";
const char* PASSPORT  = "wang0703";
const char* DATABASENAME = "studentsManager";

MYSQL* mysqlConnect() {
    MYSQL* connect = mysql_init(NULL);
    unsigned int PORT = 3306; // 更改变量名为更清晰的名字

    // 设置字符编码
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK");

    // 链接 MySQL，链接出错打印错误信息
    if (!mysql_real_connect(connect, HOST, USERNAME, PASSPORT, DATABASENAME, PORT, NULL, 0)) {
        fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(connect)); // 添加换行符
        return NULL;
    }
   

    return connect;
}
