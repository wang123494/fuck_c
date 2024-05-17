//搜索
void select();


void showData();
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
char* getName(const char* id);


//通过成绩排名
//@param 成绩
void sortBy(const char* subject); 

void ranking(const char* name, const char* subject);