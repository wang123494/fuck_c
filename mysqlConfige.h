
#ifndef MYSQLCONFIGE_H
#define MYSQLCONFIGE_H

// 此处放置 student.h 的内容
#include <mysql.h>
#include <stdio.h>

#define N 512
typedef struct Student {
    char id[11];
    char name[40];
    char gender[4];
    double scoreOfMath;
    double scoreOfEnglish;
    double scoreOfPE;
    double scoreOfCProgramming;

} Student;



MYSQL* mysqlConnect();


#endif /* MYSQLCONFIGE_H */

