//��ҪsignIn�ļ�
#include "signIn.h"
//��ʾ������ҳ��
void basicMenu() {
	int choice = 0;
	//�Ƿ�����Ĵ���
	if((choice = signIn()))
	{
		if (choice == STUDEN_CHOICE) {
			studentChoice();
		}
		//ѧ����
		if (choice == TEACHER_CHOICE) {
			teacherChoice();
		}
	}
	//����ѡ����е���
	//��ʦ��
	
	

}
