//��Ҫmysql�����ļ�
//��Ҫprintf�ļ�
#include "mysqlConfige.h"
#include "add.h"

//��ָ�� ��������->������ .
void getBM(Student* stu) {
	printf("������ѧ��:");
	scanf_s("%s", stu->id, 11);
	printf("����������:");
	scanf_s("%s", stu->name, 40);
	printf("�������Ա�:");
	scanf_s("%s", stu->gender, 4);
	printf("��������ѧ�ɼ�:");
	scanf_s("%lf", &stu->scoreOfMath);
	printf("�������ѧӢ��ɼ�");
	scanf_s("%lf", &stu->scoreOfEnglish);
	printf("�����������ɼ�");
	scanf_s("%lf",&stu->scoreOfPE);
	printf("������c���Գɼ�");
	scanf_s("%lf",&stu->scoreOfCProgramming);
}

void addRow() {
	Student stu;
    MYSQL* connect = mysqlConnect();
    char mysql[N];
    getBM(&stu);
    sprintf_s(mysql, "insert into student (ѧ��,����, �Ա�,��ѧ�ɼ�,Ӣ��ɼ�,�����ɼ�,c���Գɼ�) values('%s','%s','%s',%lf,%lf,%lf,%lf)",
        stu.id, stu.name, stu.gender, stu.scoreOfMath,stu.scoreOfEnglish,stu.scoreOfPE,stu.scoreOfCProgramming);
    if (mysql_query(connect, mysql)) {
        fprintf(stderr, "failed  to insert data : Error:%s\n", mysql_error(connect));
    }
}


