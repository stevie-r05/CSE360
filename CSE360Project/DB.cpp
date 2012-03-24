#include "stdafx.h"
#include "DB.h"
#include "DB_Core.h"
#include "DB_Answered.h"
#include "DB_Courses.h"
#include "DB_Enrolled.h"
#include "DB_QuizQuestions.h"
#include "DB_Quizzes.h"
#include "DB_Scores.h"
#include "DB_Users.h"

namespace CSE360Project {

	DB::DB() {
		answered = new DB_Answered();
		courses = new DB_Courses();
		enrolled = new DB_Enrolled();
		quizquestions = new DB_QuizQuestions();
		quizzes = new DB_Quizzes();
		scores = new DB_Scores();
		users = new DB_Users();
	}

	void DB::DeleteUser(int uid) {
		//Delete taught courses
		vector<db_course_data> taughtCourses = courses->getTaughtCourses(uid);
		for (int i = 0; i < (int) taughtCourses.size(); i++) {
			this->DeleteCourse(taughtCourses[i].cid);
		}

		//Delete user
		users->Delete(uid);

	}

	void DB::DeleteCourse(int cid) {
		//Delete associated quizzes
		vector<db_quiz_data> courseQuizzes = quizzes->getCourseQuizzes(cid);
		for (int i = 0; i < (int) courseQuizzes.size(); i++) {
			this->DeleteQuiz(courseQuizzes[i].qid);
		}

		//Delete enrolled
		enrolled->DeleteCourse(cid);


		courses->Delete(cid);
	}

	void DB::DeleteQuiz(int qid) {
		//Delete quiz questions
		quizquestions->DeleteQuiz(qid);

		//Delete answered questions
		answered->DeleteQuiz(qid);

		//Delete scores
		scores->DeleteQuiz(qid);

		//Delete quizes
		quizzes->Delete(qid);
	}

	db_answered_data *DB::newAnsweredRow() {
		db_answered_data *answer = new db_answered_data;
		answer->uid = 0;
		answer->qid = 0;
		answer->question_id = 0;
		answer->answer = 0;

		return answer;
	}

	db_course_data *DB::newCourseRow() {
		db_course_data *course = new db_course_data;

		course->uid = 0;
		WriteStructValue(course->courseName, "");

		return course;
	}

	db_enrolled_data *DB::newEnrolledRow() {
		db_enrolled_data *enrolled = new db_enrolled_data;
		enrolled->cid = 0;
		enrolled->uid = 0;

		return enrolled;
	}

	db_question_data *DB::newQuestionRow() {
		db_question_data *question = new db_question_data;

		WriteStructValue(question->question,"",true);
		WriteStructValue(question->answer1,"");
		WriteStructValue(question->answer2,"");
		WriteStructValue(question->answer3,"");
		WriteStructValue(question->answer4,"");
		WriteStructValue(question->image_location,"");
		question->qid = 0;
		question->correct_answer = 0;
		question->order = 0;

		return question;
	}

	db_quiz_data *DB::newQuizRow() {
		db_quiz_data *quiz = new db_quiz_data;
		quiz->cid = 0;
		quiz->openDate = time(NULL);
		quiz->closeDate = time(NULL);
		quiz->timeLimit = 600; //10 minutes
		return quiz;
	}

	db_score_data *DB::newScoreRow() {
		db_score_data *score = new db_score_data;
		score->uid = 0;
		score->qid = 0;
		score->cid = 0;
		score->score = 0.0;

		return score;
	}

	db_users_data *DB::newUserRow() {
		db_users_data *user = new db_users_data;
		
		WriteStructValue(user->username,"");
		WriteStructValue(user->password,"");
		WriteStructValue(user->lastName,"");
		WriteStructValue(user->firstName,"");
		WriteStructValue(user->securityQuestion,"");
		WriteStructValue(user->securityAnswer,"");
		user->userRole = student;
		
		return user;
	}


	void DB::ResetDatabase(bool confirmed) {
		answered->ResetDatabase(confirmed);
		courses->ResetDatabase(confirmed);
		enrolled->ResetDatabase(confirmed);
		quizquestions->ResetDatabase(confirmed);
		quizzes->ResetDatabase(confirmed);
		scores->ResetDatabase(confirmed);
		users->ResetDatabase(confirmed);
	}


	DB::~DB() {

		delete answered;
		delete courses;
		delete enrolled;
		delete quizquestions;
		delete quizzes;
		delete scores;
		delete users;
	}
}