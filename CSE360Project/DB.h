#pragma once
#include "stdafx.h"
#include "DB_Core.h"
#include "DB_Answered.h"
#include "DB_Courses.h"
#include "DB_Enrolled.h"
#include "DB_QuizQuestions.h"
#include "DB_Quizzes.h"
#include "DB_Scores.h"
#include "DB_Users.h"

namespace CSE360Project {
	class DB {
	public:
		DB();

		DB_Answered *answered;
		DB_Courses *courses;
		DB_Enrolled *enrolled;
		DB_QuizQuestions *quizquestions;
		DB_Quizzes *quizzes;
		DB_Scores *scores;
		DB_Users *users;

		void DeleteUser(int uid);
		void DeleteCourse(int cid);
		void DeleteQuiz(int qid);
		void ResetDatabase(bool confirmed = false);

		db_answered_data *newAnsweredRow();
		db_course_data *newCourseRow();
		db_enrolled_data *newEnrolledRow();
		db_question_data *newQuestionRow();
		db_quiz_data *newQuizRow();
		db_score_data *newScoreRow();
		db_users_data *newUserRow();

		virtual ~DB();

	protected:

	};
}