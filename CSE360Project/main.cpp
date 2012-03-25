// CSE360Project.cpp : main project file.

#include "stdafx.h"
#include "main_form.h"
#include "timingClass.h"
#include "DB.h"
#include "DB_Users.h"
#include "DB_Courses.h"

using namespace std;
using namespace CSE360Project;


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	int choice;
	vector<db_users_data> *usrs = new vector<db_users_data>;
	usrs->push_back(*(new db_users_data));
	usrs->back().uid = 3;
	/*COURSES DEBUG*/
	DB *db = new DB();

	do {
		cout << "--MENU--" << endl;
		cout << "1 - Populate Data" << endl;
		cout << "2 - List Users" << endl;
		cout << "3 - List Courses (Enrolled/Taught)" << endl;
		cout << "4 - List Enrolled/Taught Courses" << endl;
		cout << "5 - Test User Update" << endl;
		cout << "9 - RESET AND POPULATE" << endl;
		cout << "0 - Exit" << endl;
		cout << "ANYTHING ELSE - menu with different commands" << endl;
		cout << "---------POPULATE WITH DUMMY DATA---------" << endl;

		cout << "? ";
		cin >> choice;
		cout << endl;
		if (choice == 1 || choice == 9) {
			if (choice == 9) {
				db->ResetDatabase(true);
			}

			//Create 3 dummy users
			string a;
			for (int j = 0; j < 3; j++) {
				int i = 1;

				db_users_data *user = db->newUserRow();

				switch (j % 3) {
				case 1:
					a = "Hey there how are you all doing on this fine day today?";
					WriteStructValue(user->username,"David");
					WriteStructValue(user->password, "david_password");
					WriteStructValue(user->lastName, "Newton");
					WriteStructValue(user->firstName, "David");
					user->userRole = teacher;
					break;
				case 2:
					WriteStructValue(user->username,"Ian");
					WriteStructValue(user->password, "ian_password");
					WriteStructValue(user->lastName, "Coast");
					WriteStructValue(user->firstName, "Ian");
					a = "I'm well thanks";
					user->userRole = student;
					break;
				default:
					WriteStructValue(user->username,"TaraM");
					WriteStructValue(user->password, "Tara_Password");
					WriteStructValue(user->lastName, "Mendoza");
					WriteStructValue(user->firstName, "Tara");
					a = "Well I'm as happy as a clam";
					user->userRole = student;
				}

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
					quiz_data->closeDate = time(NULL) + j * 3000;
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
					db_users_data user = db->users->getUserData(uid);
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
			db_users_data user = db->users->getUserData(2);
			db->users->outputAllData();
			
			WriteStructValue(user.firstName, "Ryan");
			WriteStructValue(user.lastName, "Smith");
			db->users->Update(user);
			db->users->outputAllData();
		}


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

	db_users_data *user = new db_users_data;

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



	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	// Create the main window and run it
	Application::Run(gcnew main_form());
	return 0;
}
