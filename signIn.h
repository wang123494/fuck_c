
#define TEACHER_CHOICE  1
#define STUDEN_CHOICE  2

int signIn();
void subjectChoice(const char* name);

bool teacherConnect(const char* account, const char* passport);
bool studentConnect(const char* account, const char* passport);

void studentChoice();
void teacherChoice();
