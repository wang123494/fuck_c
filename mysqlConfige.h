
#ifndef MYSQLCONFIGE_H
#define MYSQLCONFIGE_H

// �˴����� student.h ������
#include <mysql.h>
#include <stdio.h>

#define N 256
typedef struct Student {
    char id[11];
    char name[40];
    char gender[4];
    double scoreOfMath;
} Student;



MYSQL* mysqlConnect();


#endif /* MYSQLCONFIGE_H */

