#pragma once

typedef struct  Student {
    char name[40];
    // char id[11];
    char gender[4];
    //��д�����ųɼ�����
    //��ѧ�ɼ� 
  //  double scoreOfMath;
    //computer science �ɼ�
   // double scoreOfCS;
    //Ӣ��ɼ�
   // double scoreOfEnglish;

}Student;
#include <stdio.h>
#include <mysql.h>
void mysqlConnect();

