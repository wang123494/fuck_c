#include <stdio.h>
#include <mysql.h>
typedef struct  Student {
    char id[11] = {0};
    char name[40];
    // char id[11];
    char gender[4];
    //��д�����ųɼ�����
    //��ѧ�ɼ� 
    double scoreOfMath;
    //computer science �ɼ�
   // double scoreOfCS;
    //Ӣ��ɼ�
   // double scoreOfEnglish;

}Student;
// �й� MYSQL �ĺ���
//��ȡ������Ϣ
void getBM(Student* stu);
//�������ݿ�
MYSQL* mysqlConnect();
//ȡ�����
//������Ҫ����

void showData();
void addRow(Student stu);
void deleteRow();

/*
* s0Ϊ���ĸ�����
* s1Ϊ��֮ǰ������
* s2Ϊ��֮�������
*/
void changeString(const char* s0,char* s1 ,char* s2);
//s3Ϊ�����
void changeString(const char* s0, char* s1, char* s2,char* s3);

/*
* s0Ϊ���ĸ�����
* 
*/
void changeNumber(const char* s0);



/*
*@param ����
   @return
   ���ڵ���1����0
*  ����ж��ֵ����1
*/
int isDuplicate(const char* s0);

//��Ҫչʾ��һ��
void showColumn(const char* s0);
//��������չʾҪ����һ��
void showRow(const char* name);

/*
*@param ѧ��
* @return ��Ӧ��ֵ
*/
double getMax(const char* subject);
double getMin(const char* subject);
double getAverage(const char* subject);


//ͨ���ɼ�����
//@param �ɼ�
void sortBy(const char* subject);

int passATest(const char* subject ,const char* name);


