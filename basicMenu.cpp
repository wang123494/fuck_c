//需要signIn文件
#include "signIn.h"
//显示基本的页面
void basicMenu() {
	int choice = 0;
	//非法输入的处理
	if((choice = signIn()))
	{
		if (choice == STUDEN_CHOICE) {
			studentChoice();
		}
		//学生端
		if (choice == TEACHER_CHOICE) {
			teacherChoice();
		}
	}
	//根据选择进行调用
	//教师端
	
	

}
