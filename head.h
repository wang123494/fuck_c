#pragma once

typedef struct  Student {
    char name[40];
    // char id[11];
    char gender[4];
    //先写着三门成绩试试
    //数学成绩 
  //  double scoreOfMath;
    //computer science 成绩
   // double scoreOfCS;
    //英语成绩
   // double scoreOfEnglish;

}Student;
#include <stdio.h>
#include <mysql.h>
void mysqlConnect();

