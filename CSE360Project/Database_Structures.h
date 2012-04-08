#define DATA_ROW_TERMINATE '\n'
#define MAX_TEXT_FIELD_SIZE 255 //EVERY Char is going ot be this size, EXCEPT For Question
#define MAX_MEMO_FIELD_SIZE 16384 //Only Questions inputted by the instructor will be of this size.

//User Roles
enum user_role_t {
	student = 0,
	teacher = 1,
	admin = 99
};

//Users
/*
username password lastName firstName securityQuestion securityAnswer userRole
*/

struct db_user_data {
	int uid; //Key
	char username[MAX_TEXT_FIELD_SIZE];
	char password[MAX_TEXT_FIELD_SIZE];
	char lastName[MAX_TEXT_FIELD_SIZE];
	char firstName[MAX_TEXT_FIELD_SIZE];
	char securityQuestion[MAX_TEXT_FIELD_SIZE];
	char securityAnswer[MAX_TEXT_FIELD_SIZE];
	user_role_t userRole;
};

//Courses
struct db_course_data {
	int cid; //Key
	int uid;
	char courseName[MAX_TEXT_FIELD_SIZE];
};

//Enrolled
struct db_enrolled_data {
	int eid; //Key
	int uid;
	int cid;
}; 

//Quizzes
struct db_quiz_data {
	int qid; //Key
	int cid;
	time_t openDate;
	time_t closeDate;
	int timeLimit;
};

//Quiz Questions
struct db_question_data {
	int question_id; //Key
	int qid;
	char question[MAX_MEMO_FIELD_SIZE];
	char answer1[MAX_TEXT_FIELD_SIZE];
	char answer2[MAX_TEXT_FIELD_SIZE];
	char answer3[MAX_TEXT_FIELD_SIZE];
	char answer4[MAX_TEXT_FIELD_SIZE];
	int correct_answer;
	int order;
	char image_location[MAX_TEXT_FIELD_SIZE];
};

//Answered
struct db_answered_data {
	int aid; //Key
	int uid;
	int qid;
	int question_id;
	int answer;
};

//Scores
struct db_score_data {
	int sid; //Key
	int uid;
	int qid;
	int cid;
	double score;
};