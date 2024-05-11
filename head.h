#include <stdio.h>
#include <mysql.h>
typedef struct  Student {
    char id[11] = {0};
    char name[40];
    // char id[11];
    char gender[4];
    //先写着三门成绩试试
    //数学成绩 
    double scoreOfMath;
    //computer science 成绩
   // double scoreOfCS;
    //英语成绩
   // double scoreOfEnglish;

}Student;
// 有关 MYSQL 的函数
//获取基本信息
void getBM(Student* stu);
//链接数据库
MYSQL* mysqlConnect();
//取结果集
//后续需要更改

void showData();
void addRow(Student stu);
void deleteRow();

/*
* s0为改哪个大类
* s1为改之前的内容
* s2为改之后的内容
*/
void changeString(const char* s0,char* s1 ,char* s2);
//s3为输入的
void changeString(const char* s0, char* s1, char* s2,char* s3);

/*
* s0为改哪个大类
* 
*/
void changeNumber(const char* s0);



/*
*@param 姓名
   @return
   少于等于1返回0
*  如果有多个值返回1
*/
int isDuplicate(const char* s0);

//传要展示哪一列
void showColumn(const char* s0);
//传姓名，展示要传那一行
void showRow(const char* name);

/*
*@param 学科
* @return 对应的值
*/
double getMax(const char* subject);
double getMin(const char* subject);
double getAverage(const char* subject);


//通过成绩排名
//@param 成绩
void sortBy(const char* subject);

int passATest(const char* subject ,const char* name);


