//����
void select();


void showData();
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
char* getName(const char* id);


//ͨ���ɼ�����
//@param �ɼ�
void sortBy(const char* subject); 

void ranking(const char* name, const char* subject);