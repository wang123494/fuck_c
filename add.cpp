//��Ҫmysql�����ļ�
//��Ҫprintf�ļ�
#include "mysqlConfige.h"
#include "add.h"

//��ָ�� ��������->������ .
void getBM(Student* stu) {
	printf("���������ѧ��:");
	scanf_s("%s", stu->id, 11);
	printf("�������������:");
	scanf_s("%s", stu->name, 40);
	printf("����������Ա�:");
	scanf_s("%s", stu->gender, 4);
	printf("�����������ѧ�ɼ�:");
	scanf_s("%lf", &stu->scoreOfMath);
}

void addRow(Student stu) {
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    getBM(&stu);
    sprintf_s(mysql, "insert into student (ѧ��,����, �Ա�,��ѧ�ɼ�) values('%s','%s','%s',%lf)",
        stu.id, stu.name, stu.gender, stu.scoreOfMath);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}


