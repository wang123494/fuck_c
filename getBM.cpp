//�õ���������Ϣ
#include "head.h"
//��ָ�� ��������->������ .
void getBM(Student* stu) {
		printf("���������ѧ��:");
		scanf_s("%s",stu->id,11);
		printf("�������������:");
		scanf_s("%s", stu->name, 40);
		printf("����������Ա�:");
		scanf_s("%s", stu->gender, 4);
		printf("�����������ѧ�ɼ�:");
		scanf_s("%lf", &stu->scoreOfMath);
}