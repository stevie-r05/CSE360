// CSE360Project.cpp : main project file.
/*THESE TWO MUST BE INCLUDED IN EVERY FILE*/
#include "stdafx.h"
#include "core_header.h"
/*THESE TWO MUST BE INCLUDED IN EVERY FILE*/


#include "main_form.h"
#include "timingClass.h"
#include "DB.h"
#include "DB_Users.h"
#include "DB_Courses.h"
#include "Quiz.h"

using namespace std;
using namespace CSE360Project;

DB *db;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//Set the DB Variable with the new database.
	db = new DB();

	int choice;
	vector<db_user_data > *usrs = new vector<db_user_data >;
	usrs->push_back(*(new db_user_data ));
	usrs->back().uid = 3;
	/*COURSES DEBUG*/

	do {
		cout << "--MENU--" << endl;
		cout << "1 - Populate Data" << endl;
		cout << "2 - List Users" << endl;
		cout << "3 - List Courses (Enrolled/Taught)" << endl;
		cout << "4 - List Enrolled/Taught Courses" << endl;
		cout << "5 - Test User Update" << endl;
		cout << "6 - Print Quiz Data" << endl;
		cout << "7 - Print Quiz Question Data" << endl;
		cout << "8 - Create Example Quiz" << endl;
		cout << "9 - Take and Grade Example Quiz" << endl;
		cout << "10 - Test Course Class" << endl;
		cout << "11 - List Data" << endl;
		cout << "12 - RESET AND POPULATE" << endl;
		cout << "0 - Exit" << endl;
		cout << "ANYTHING ELSE - menu with different commands" << endl;
		cout << "---------POPULATE WITH DUMMY DATA---------" << endl;

		cout << "? ";
		cin >> choice;
		cout << endl;
		if (choice == 1 || choice == 11) {
			if (choice == 12) {
				db->ResetDatabase(true);
			}

			//Create 3 dummy users
			string a;
			for (int j = 0; j < 3; j++) {
				int i = 1;

				db_user_data *user = db->newUserRow();

				switch (j % 3) {
				case 1:
					a = "Hey there how are you all doing on this fine day today?";
					WriteStructValue(user->username,"David\0");
					WriteStructValue(user->password, "david_password");
					WriteStructValue(user->lastName, "Newton");
					WriteStructValue(user->firstName, "David");
					user->userRole = teacher;
					break;
				case 2:
					WriteStructValue(user->username,"Ian\0");
					WriteStructValue(user->password, "ian_password");
					WriteStructValue(user->lastName, "Coast");
					WriteStructValue(user->firstName, "Ian");
					a = "I'm well thanks";
					user->userRole = student;
					break;
				default:
					WriteStructValue(user->username,"TaraM\0");
					WriteStructValue(user->password, "Tara_Password");
					WriteStructValue(user->lastName, "Mendoza");
					WriteStructValue(user->firstName, "Tara");
					a = "Well I'm as happy as a clam";
					user->userRole = student;
				}
				string thisString;
				thisString = user->username;
				cout << thisString << endl;
				WriteStructValue(user->username, thisString);
				WriteStructValue(user->securityQuestion, a);
				WriteStructValue(user->securityAnswer, "Hi.");

				db->users->Insert(user);
			}

			//For the teacher insert 3 courses
			int uid = db->users->getUID("David");

			for (int i = 0; i < 3; i++)
			{
				db_course_data *course = db->newCourseRow();
				course->uid = uid;

				switch (i) {
				case 1:
					a = "CSE 112";
					break;
				case 2:
					a = "CSE 230";
					break;
				default:
					a = "CSE 430";
				}
				WriteStructValue(course->courseName, a);

				db->courses->Insert(course);

				//for each course insert 1 or 2 quizzes
				for (int j = 0; j < i % 2 + 1; j++) {
					db_quiz_data *quiz_data = db->newQuizRow();
					quiz_data->cid = db->courses->getLastID();
					quiz_data->openDate = time(NULL);
					quiz_data->closeDate = time(NULL) + i * 3000;
					quiz_data->timeLimit = 600;

					db->quizzes->Insert(quiz_data);

					//For each quiz Insert 5 questions
					for (int k = 0; k < 5; k++) {
						db_question_data *question = db->newQuestionRow();
						question->qid = db->quizzes->getLastID();
						question->correct_answer = k % 4;
						question->order = (k*3+1) % 4;
						WriteStructValue(question->question, "THIS IS A LONG QUESTION",true);
						WriteStructValue(question->answer1, "answer1");
						WriteStructValue(question->answer2, "answer2");
						WriteStructValue(question->answer3, "answer3");
						WriteStructValue(question->answer4, "answer4");

						db->quizquestions->Insert(question);
					}
				}
			}
			
			uid = db->users->getUID("Ian");

			//Enroll into 2 courses
			for (int i = 0; i < 2; i++) {
				db->enrolled->Insert(uid,i+1);
			}

		} else if (choice == 2) {
			db->users->outputAllData();

			if (db->users->getRecordCount() > 0) {
				cout << "Input uid to display (0 to exit): ";
				int uid;
				cin >> uid;
				if (uid != 0)
					db_user_data user = db->users->getUserData(uid);
			}
		} else if (choice == 3) {
			cout << "cid\tcourse name\ttaught by" << endl;
			vector<db_course_data> courses = db->courses->getAllCourseData();
			for (int i = 0; i < (int) courses.size(); i++) {
				cout << courses[i].cid << "\t" << courses[i].courseName << "\t\t" << db->users->getLastname(courses[i].uid) << endl;
			}

		} else if (choice == 4) {
			int uid;
			db->users->outputAllData();
			cout << "Select a uid: ";
			cin >> uid;

			vector<db_enrolled_data> enrolled = db->enrolled->getEnrolledCourses(uid);
			vector<db_course_data> taught = db->courses->getTaughtCourses(uid);

			cout << "-- Enrolled --" << endl;
			for (int i = 0; i < (int) enrolled.size(); i++) {
				cout << enrolled[i].eid << " - " << db->courses->getCourseName(enrolled[i].cid) << endl;
			}

			cout << "-- Taught -- " << endl;
			for (int i = 0; i < (int) taught.size(); i++) {
				cout << taught[i].cid << " - " << taught[i].courseName << endl;
			}

		} else if (choice == 5) {
			db_user_data user = db->users->getUserData(2);
			db->users->outputAllData();
			
			WriteStructValue(user.firstName, "Ryan");
			WriteStructValue(user.lastName, "Smith");
			db->users->Update(user);
			db->users->outputAllData();
		} else if (choice == 6){
			db->quizzes->outputAllData();
		} else if (choice == 7){
			db->quizquestions->outputAllData();
		} else if (choice == 8){//create example quiz

			//create quiz object input CID = 1  for CSE 430
			Quiz exampleQuiz(1);

			//create questions and store in vector string array
			vector<string>questions;
			string question1 = "What is 2+2?";
			questions.push_back(question1);
			string question2 = "What is 2+3?";
			questions.push_back(question2);
			string question3 = "What is 2+4?";
			questions.push_back(question3);
			string question4 = "What is 2+5?";
			questions.push_back(question4);
			string question5 = "What is 2+6?";
			questions.push_back(question5);

			//send string vector array to quiz object where it will store and package the questions 
			exampleQuiz.setQuestions(questions);

			//create and set answers
			vector<string> answers;
			
			string Answer1a = "4";
			answers.push_back(Answer1a);
			string Answer1b = "2";
			answers.push_back(Answer1b);
			string Answer1c = "3";
			answers.push_back(Answer1c);
			string Answer1d = "6";
			answers.push_back(Answer1d);
			string Answer1correct = "1";
			answers.push_back(Answer1correct);

			string Answer2a = "4";
			answers.push_back(Answer2a);
			string Answer2b = "5";
			answers.push_back(Answer2b);
			string Answer2c = "3";
			answers.push_back(Answer2c);
			string Answer2d = "6";
			answers.push_back(Answer2d);
			string Answer2correct = "2";
			answers.push_back(Answer2correct);

			string Answer3a = "3";
			answers.push_back(Answer3a);
			string Answer3b = "1";
			answers.push_back(Answer3b);
			string Answer3c = "4";
			answers.push_back(Answer3c);
			string Answer3d = "6";
			answers.push_back(Answer3d);
			string Answer3correct = "4";
			answers.push_back(Answer3correct);

			string Answer4a = "6";
			answers.push_back(Answer4a);
			string Answer4b = "8";
			answers.push_back(Answer4b);
			string Answer4c = "7";
			answers.push_back(Answer4c);
			string Answer4d = "5";
			answers.push_back(Answer4d);
			string Answer4correct = "3";
			answers.push_back(Answer4correct);

			string Answer5a = "7";
			answers.push_back(Answer5a);
			string Answer5b = "8";
			answers.push_back(Answer5b);
			string Answer5c = "3";
			answers.push_back(Answer5c);
			string Answer5d = "6";
			answers.push_back(Answer5d);
			string Answer5correct = "2";
			answers.push_back(Answer5correct);

			//set answers in quiz object
			exampleQuiz.setAnswers(answers);

			time_t openDate= time (NULL); 
			exampleQuiz.setOpenDate(openDate);

			time_t closeDate= time (NULL);
			exampleQuiz.setCloseDate(closeDate);

			exampleQuiz.setTimeLimit(30);

			exampleQuiz.saveQuiz();

			//display quizquestions DB and QuizAnswers DB to check if everything was stored properly
			cout << "Displaying Quiz ID:  " << exampleQuiz.quizID << endl;
			vector<db_question_data> displayQuestions = db->quizquestions->getQuestions(exampleQuiz.quizID);
			for (int i = 0; i < (int) displayQuestions.size(); i++) {
				cout <<"question: "<< i+1 <<". "<<displayQuestions[i].question << endl;
				cout <<"A"<<". "<<displayQuestions[i].answer1 << endl;
				cout <<"B"<<". "<<displayQuestions[i].answer2 << endl;
				cout <<"C"<<". "<<displayQuestions[i].answer3 << endl;
				cout <<"D"<<". "<<displayQuestions[i].answer4 << endl;
				cout <<"answer: "<<displayQuestions[i].correct_answer << endl;
			}
			
		} else if (choice == 9) {//take example quiz

			//create new quiz object to store data
			Quiz Quiz(5,3, 1);
			//create question data struct vector array for questions
			vector<db_question_data> displayQuestions = Quiz.getQuestions();
			//create dynamic array to hold answers
			int *answers = new int[displayQuestions.size()];
			string temp;

			//display questions sequencially on the screen
			for (int i = 0; i < (int) displayQuestions.size(); i++) {
		
				cout <<"question: "<< i+1 <<". "<<displayQuestions[i].question << endl;
				cout <<"A"<<". "<<displayQuestions[i].answer1 << endl;
				cout <<"B"<<". "<<displayQuestions[i].answer2 << endl;
				cout <<"C"<<". "<<displayQuestions[i].answer3 << endl;
				cout <<"D"<<". "<<displayQuestions[i].answer4 << endl;
				cout <<"Please enter the correct answer: ";
				
				//make sure the correct characters/strings are used by the quia taker 
				do{
					cin >>temp;
					if(temp == "A" || temp == "B" || temp == "C" || temp == "D"){
					break;
					}
					 cout<<"Incorrect character entered please enter A, B, C, or D: ";
				} while(true);

				//save answer to answer int []
				if(temp == "A")
					answers[i] = 1;
				if(temp == "B")
					answers[i] = 2;
				if(temp == "C")
					answers[i] = 3;
				if(temp == "D")
					answers[i] = 4;
			}//end foor loop

			//submit and grade quiz
			Quiz.submitAnswers(answers);

			//this is not working it keeps retunring a 0.  I have checkedevrything in the quiz class and it all works
			double grade = db->scores->getUserQuizScore(3, 5);
			cout<<"The grade for this quiz is: " << grade << endl;

		} else if (choice == 10) {

			cout << endl;
			cout << "1 - Create a Course" << endl;
			cout << "2 - Load a Course" << endl;
			cout << "3 - Exit to Previous Menu" << endl;
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1:

				break;
			case 2:
				
				break;
			case 3:
				break;
			}

		}else if (choice == 11) {
			
			cout << endl;
			cout << "Select which database you'd like to output." << endl;
			cout << "1 - Answered" << endl;
			cout << "2 - Courses" << endl;
			cout << "3 - Enrolled" << endl;
			cout << "4 - Quiz Questions" << endl;
			cout << "5 - Quizzes" << endl;
			cout << "6 - Scores" << endl;
			cout << "7 - Users" << endl;
			cout << "? " << endl;
			
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1:
				db->answered->outputAllData();
				break;
			case 2:
				db->courses->outputAllData();
				break;
			case 3:
				db->enrolled->outputAllData();
				break;
			case 4:
				db->quizquestions->outputAllData();
				break;
			case 5:
				db->quizzes->outputAllData();
				break;
			case 6:
				db->scores->outputAllData();
				break;
			case 7:
				db->users->outputAllData();
				break;
			}
		}//end else

		/*cout << "---output usesrs---" << endl;
		db->users->outputAllData();
		cout << endl;

		cout << "---output courses---" << endl;
		db->courses->outputAllData();
		cout << endl;
		
		cout << "---output quizzes---" << endl;
		db->quizzes->outputAllData();
		cout << endl;
		
		cout << "---output quizquestions---" << endl;
		db->quizquestions->outputAllData();*/

	} while (choice != 0);

	//db->ResetDatabase(true);   
	delete db;

	/*DB_Users *db = new DB_Users();

	db->outputAllUsers();

	//write test user
	string a;
	for (int j = 0; j < 5; j++) {
	int i = 1;
	switch (db->getLastID() % 3) {
	case 1:
	a = "Hey there how are you all doing on this fine day today?";
	break;
	case 2:
	a = "I'm well thanks";
	break;
	default:
	a = "Well I'm as happy as a clam";
	}

	db_user_data *user = new db_user_data ;

	WriteStructValue(user->username,"David");
	WriteStructValue(user->password, "david_password");
	WriteStructValue(user->lastName, "Newton");
	WriteStructValue(user->firstName, "David");
	WriteStructValue(user->securityQuestion, a);
	WriteStructValue(user->securityAnswer, "Hi.");
	user->userRole = teacher;

	db->Insert(user);
	}
	cout << "------------------------------" << endl;
	//db->Write();
	db->outputAllData();

	cout << "-----------DELETE UID 2 & 3-------------------" << endl;
	db->Delete(2);
	db->Delete(3);
	db->outputAllData();*/

	system("pause");



	/*// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	// Create the main window and run it
	Application::Run(gcnew main_form());
	*/
	return 0;
}
