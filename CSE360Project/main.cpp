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
#include "User.h"
#include "DB_Courses.h"

using namespace std;
using namespace CSE360Project;

string ConvertDatetoStr(time_t time);

DB *db;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//Set the DB Variable with the new database.
	db = new DB();

	//declare variables used in switch statements
	Course *newCourse;
	User *localUser;
	Quiz *newQuiz;
	string uName;
	string pWord;
	string courseName, question, answer;
	vector<db_enrolled_data> enrolledCourses;
	vector<db_course_data> taughtCourses;
	int cid, qid, studentID;
	vector<db_quiz_data> quizList;
	vector<string>questions;
	vector<string> answers;

	int choice;
	vector<db_user_data > *usrs = new vector<db_user_data >;
	usrs->push_back(*(new db_user_data ));
	usrs->back().uid = 3;
	/*COURSES DEBUG*/

	do {
		system("CLS");
		for(int j = 0;j<5;j++)
			cout<<endl;
		cout << "Welcome to the Just-In-Time Classroom Companion" <<"\n"<< endl;
		cout << "--DEBUG AND TEST MENU--" << endl;
		cout << "1 - Reset and Populate Data" << endl;
		cout << "2 - List Users" << endl;
		cout << "3 - Run the Prototype Program" << endl;
		cout << "0 - Exit" << endl;

		cout << "? ";
		cin >> choice;
		cout << endl;
		if (choice == 1 || choice == 14) {
			if (choice == 1) {
				db->ResetDatabase(true);
			}

			//Create 4 dummy users
			string a;
			for (int j = 0; j < 4; j++) {
				int i = 1;

				db_user_data *user = db->newUserRow();

				switch (j % 4) {
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
				case 3:
					WriteStructValue(user->username,"Stevie\0");
					WriteStructValue(user->password, "stevie_password");
					WriteStructValue(user->lastName, "Robinson");
					WriteStructValue(user->firstName, "Stevie");
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

				for(int i=1;i<4;i++){
					//create quiz and add to each course
					Quiz exampleQuiz(i);

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

					time_t closeDate= time (NULL)+7200;
					exampleQuiz.setCloseDate(closeDate);

					exampleQuiz.setTimeLimit(3000);

					exampleQuiz.saveQuiz();
				}
				//for each course insert 1 or 2 quizzes
				/*for (int j = 0; j < i % 2 + 1; j++) {
				db_quiz_data *quiz_data = db->newQuizRow();
				quiz_data->cid = db->courses->getLastID();
				quiz_data->openDate = time(NULL);
				quiz_data->closeDate = time(NULL) + 7200;
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
				}*/
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
			cout<<"\n"<<"Hit enter to continue";
			cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
			cin.get();
		} else if (choice == 3){//RUN THE PROTOTYPE PROGRAM

			do{	system("CLS");
			for(int j = 0;j<8;j++)
				cout<<endl;
			cout << "Welcome to the Just-In-Time Classroom Companion" << endl;
			cout << "Please choose from the following options:" <<"\n"<< endl;
			cout << "1 - Login" << endl;
			cout << "2 - Register" << endl;
			cout << "3 - Quit" << "\n"<< endl;
			cin >> choice;

			if (choice==1) {//LOGIN MENU
				system("CLS");
				for(int j = 0;j<10;j++)
					cout<<endl;
				cout << "Username: ";
				cin >> uName;
				cout << "Password: ";
				cin >> pWord;

				if (db->users->validateUser(uName,pWord)){//check if login is valid
					int uID = db->users->getUID(uName);
					localUser = new User(uID);

					if(localUser->userRole==0){//if user is a student			

						do{//ENROLLED COURSES MENU
							system("CLS");
							for(int j = 0;j<5;j++)
								cout<<endl;
							cout << "First Name: " << localUser->firstName << endl;
							cout << "Last Name: " << localUser->lastName << endl;
							cout << "User Role: Student"<< "\n"<< endl;
							cout << "Currently Enrolled Courses: "<< "\n" <<endl;
							enrolledCourses = localUser->getEnrolledCourses();
							cout << "Course ID:" <<"   Course Name"<<endl;
							for(int i=0; i < (int) enrolledCourses.size();i++){//print out enrolled courses
								cout <<enrolledCourses[i].cid<<"\t"<<"\t"<<db->courses->getCourseName(enrolledCourses[i].cid) <<endl;
							}
							cout<<"\n";

							cout << "- Enter a course ID to view open and completed quizzes"<<"\n"<< "- Enter \"0\" to go to logout" <<endl;
							cin >> cid;
							if(cid == 0){//logout
								break;
								cout<<"\n";
							}
							cout<<"\n";

							newCourse = localUser->getCourse(cid);//show quizzes in course
							quizList = newCourse->getQuizList();
							do{//QUIZ MENU
								system("CLS");
								for(int i = 0;i<8;i++)
									cout<<endl;
								cout << "Quiz ID"<<"\t"<<"Open Date"<<"\t"<<"\t"<<"\t"<<"Closed Date"<<"\t"<<"\t"<<"\t"<<"Grade"<< endl;
								for(int i=0; i < (int) quizList.size();i++){//print out quizzes courses
									if(db->scores->getUserQuizScore(localUser->userID, quizList[i].qid)==-1){
										cout <<quizList[i].qid<<"\t"<<ConvertDatetoStr(quizList[i].openDate)<<"\t"<<ConvertDatetoStr(quizList[i].closeDate)<<"\t"<<"0"<<"\t";
									}else{
										cout <<quizList[i].qid<<"\t"<<ConvertDatetoStr(quizList[i].openDate)<<"\t"<<ConvertDatetoStr(quizList[i].closeDate)<<"\t"<<db->scores->getUserQuizScore(localUser->userID, quizList[i].qid)<<"\t";
									}
								}
								cout<<"\n";									
								cout << "- Enter a quiz ID to view/take a quiz for this course"<<"\n"<< "- Enter \"0\" to go to the previous menu: " <<endl;
								cin >> qid;
								if(qid == 0){//logout
									break;
									cout<<"\n";
								}
								newQuiz = newCourse->getQuiz(qid,uID,cid);
								time_t currentTime =time(NULL);
								//cout<<"newQuiz->openDate = "<<newQuiz->openDate<<" currentTime = "<<currentTime<<"\n"<<"newQuiz->closeDate = "<<newQuiz->closeDate<<" currentTime = "<<currentTime<<"\n"<<"db->scores->getUserQuizScore(localUser->userID,qid) = "<<db->scores->getUserQuizScore(localUser->userID,qid)<<" == 0"; 
								//system ("PAUSE");
								if(newQuiz->openDate <= currentTime && newQuiz->closeDate >= currentTime && db->scores->getUserQuizScore(localUser->userID,qid)==-1){//if the quiz is open and there is no score then show take quiz ui
									//create question data struct vector array for questions
									vector<db_question_data> displayQuestions = newQuiz->getQuestions();
									//create dynamic array to hold answers
									int *answers = new int[displayQuestions.size()];
									string temp;

									//display questions sequencially on the screen
									for (int i = 0; i < (int) displayQuestions.size(); i++) {
										system("CLS");
										for(int j = 0;j<8;j++)
											cout<<endl;
										cout <<"Question "<< i+1 <<". "<<displayQuestions[i].question <<"\n"<< endl;
										cout <<"A"<<". "<<displayQuestions[i].answer1 << endl;
										cout <<"B"<<". "<<displayQuestions[i].answer2 << endl;
										cout <<"C"<<". "<<displayQuestions[i].answer3 << endl;
										cout <<"D"<<". "<<displayQuestions[i].answer4 << endl;
										cout <<"\n"<<"\n"<<"Please enter the correct answer: ";

										//make sure the correct characters/strings are used by the quiz taker 
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

										cout <<"\n"<<"\n";
									}//end foor loop

									//submit and grade quiz
									newQuiz->submitAnswers(answers);

									//get grade
									system("CLS");
									//cout<<"\n"<<"\n"<<"The grade for this quiz is: " << db->scores->getUserQuizScore(localUser->userID,qid) <<"\n"<<"\n"<<endl;
								}else if(db->scores->getUserQuizScore(localUser->userID,qid)!=-1){//else if its closed or there is a score show detailed answers and questions
									system("CLS");
									//create question data struct vector array for questions
									vector<db_question_data> displayQuestions = newQuiz->getQuestions();
									//get user quiz answers
									vector<db_answered_data> quizAnswers = db->answered->getUsersQuizAnswers(localUser->userID, newQuiz->quizID);
									//display questions sequencially on the screen
									for (int i = 0; i < (int) displayQuestions.size(); i++) {

										cout <<"Question "<< i+1 <<". "<<displayQuestions[i].question <<"\n"<< endl;
										cout <<"A"<<". "<<displayQuestions[i].answer1 << endl;
										cout <<"B"<<". "<<displayQuestions[i].answer2 << endl;
										cout <<"C"<<". "<<displayQuestions[i].answer3 << endl;
										cout <<"D"<<". "<<displayQuestions[i].answer4 << endl;
										cout <<"\n"<<"Correct Answer: "<< displayQuestions[i].correct_answer<<" Your Answer: "<<quizAnswers[i].answer<<"\n"<< endl;
									}
									//system ("PAUSE");
									cout<<"Hit enter to continue";
									cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
									cin.get();
								}//end else

							} while(true);//QUIZ MENU
						} while(true);//ENROLLED COURSES MENU

					}else{//else if user is a teacher
						do{//TAUGHT COURSES MENU
							system("CLS");
							for(int j = 0;j<5;j++)
								cout<<endl;
							cout << "First Name: " << localUser->firstName << endl;
							cout << "Last Name: " << localUser->lastName << endl;
							cout << "User Role: Teacher"<< "\n"<< endl;
							cout << "Currently Taught Courses: "<< "\n" <<endl;
							taughtCourses = localUser->getTaughtCourses();
							cout << "Course ID:" <<"   Course Name"<<endl;
							for(int i=0; i < (int) taughtCourses.size();i++){//print out enrolled courses
								cout <<taughtCourses[i].cid<<"\t"<<"\t"<<db->courses->getCourseName(taughtCourses[i].cid) <<endl;
							}
							cout<<"\n";

							cout << "- Enter \"1\" to view/edit course content."<<endl;
							cout<<"- Enter \"2\" to create a course."<<endl;
							cout<<"- Enter \"3\" to delete a course."<<endl;
							cout<<"- Enter \"0\" to logout." <<endl;
							cin >> choice;
							if(choice == 0){//logout
								break;
								cout<<"\n";
							}else if(choice == 3){
								cout << "Please enter the course ID to delete"<<endl;
								cin>>cid;
								localUser->deleteCourse(cid);//delete course by calling delet method in user 
							}else if(choice == 2){//create a course
								do{
									system("CLS");
									for(int j = 0;j<8;j++)
										cout<<endl;
									cout << "Please enter the course name"<<endl;
									cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
									getline (cin,courseName);
									newCourse = localUser->createCourse(courseName);//create course through user object retunr course

									do{
										system("CLS");
										for(int j = 0;j<7;j++)
											cout<<endl;
										cout << "Enroll students menu for course: "<<courseName<<"\n"<<"\n"<<endl;	
										cout << "- Enter \"-1\" when done"<<endl;
										cout << "- Enter \"-2\" to see a list of current users"<<"\n"<<"\n"<<endl;									
										cout << "Please enter a student ID to add student to course:"<<endl;
										cin>>studentID;
										if(studentID == -1){
											break;
										}else if(studentID == -2){
											system("CLS");
											for(int j = 0;j<8;j++)
												cout<<endl;
											db->users->outputAllData();
											cout<<"Hit enter to return to enroll menu";
											cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
											cin.get();
										} else{
											if(db->users->getUsername(studentID).compare("none")==0){//confirm the ID matches a users
												cout<<"User does not exist"<<endl;
												cout<<"Hit enter continue";
												cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
												cin.get();
											}else {
												db->enrolled->Insert(studentID,newCourse->courseID);
												cout<<"User added successfully"<<endl;
											}
										}
									}while(true);
									break;
								}while(true);
							}else{//view/edit course content teacher
								cout << "Please enter the course ID to view/edit the course"<<endl;
								cin>>cid;
								do{
									system("CLS");
									newCourse = localUser->getCourse(cid);//instantiate existing course
									for(int j = 0;j<8;j++)
										cout<<endl;
									cout << "Edit menu for course: "<<newCourse->getName()<<"\n"<<"\n"<<endl;	
									cout << "- Enter \"1\" to add students to the course"<<endl;
									cout << "- Enter \"2\" to delete students from the course"<<endl;
									cout << "- Enter \"3\" to view/edit quizzes for the course"<<endl;
									cout << "- Enter \"4\" to view roster/gradebook for the course"<<endl;
									cout << "- Enter \"0\" to go back to the previous menu"<<endl;
									cin>>choice;

									if(choice == 0)//go to previous menu
										break;

									if(choice == 1){//menu to add students to course
										do{
											system("CLS");
											for(int j = 0;j<7;j++)
												cout<<endl;

											cout << "Enroll students menu for course: "<<courseName<<"\n"<<"\n"<<endl;	
											cout << "- Enter \"1\" to add a student"<<endl;
											cout << "- Enter \"2\" to see a list of current students"<<endl;
											cout << "- Enter \"0\" to go to previous menu"<<"\n"<<"\n"<<endl;									
											cin>>choice;

											if(choice == 0){
												break;
											}else if(choice == 2){
												system("CLS");
												for(int j = 0;j<8;j++)
													cout<<endl;
												vector<db_enrolled_data> enrolledStudents = newCourse->getStudents();
												cout << "Current students enrolled in course: "<<courseName<<"\n"<<"\n"<<endl;
												cout<<"Student ID#"<<"\t"<<"Username"<<endl;

												for(int i=0; i < (int) enrolledStudents.size();i++){//list quizzes for each student in course			
													cout <<enrolledStudents[i].uid<<"\t"<<"\t"<<db->users->getUsername(enrolledStudents[i].uid)<<endl;
												}//end forloop

												cout<<"\n"<<"Hit enter to return to enroll menu";
												cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
												cin.get();

											}else if(choice == 1) {
												cout<<"Please enter student ID to add"<<endl;
												cin>>studentID;
												if(db->users->getUsername(studentID).compare("none")==0){//confirm the ID matches a users
													cout<<"User does not exist"<<endl;
													cout<<"Hit enter continue";
													cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
													cin.get();
												}else{
													db->enrolled->Insert(studentID,newCourse->courseID);
													cout<<"User added successfully"<<endl;
												}
											}
										}while(true);//end do-loop to add students
									}//end if menu to add students to course

									if(choice == 2){//menu to delete students from the course
										do{
											system("CLS");
											for(int j = 0;j<7;j++)
												cout<<endl;

											cout << "Delete students menu for course: "<<courseName<<"\n"<<"\n"<<endl;	
											cout << "- Enter \"1\" to delete a student"<<endl;
											cout << "- Enter \"2\" to see a list of current users"<<endl;
											cout << "- Enter \"0\" to go to previous menu"<<"\n"<<"\n"<<endl;									
											cin>>choice;									

											if(choice == 0){
												break;
											}else if(choice == 2){
												system("CLS");
												for(int j = 0;j<8;j++)
													cout<<endl;
												vector<db_enrolled_data> enrolledStudents = newCourse->getStudents();
												cout << "Current students enrolled in course: "<<courseName<<"\n"<<"\n"<<endl;
												cout<<"Student ID#"<<"\t"<<"Username"<<endl;

												for(int i=0; i < (int) enrolledStudents.size();i++){//list quizzes for each student in course			
													cout <<enrolledStudents[i].uid<<"\t"<<"\t"<<db->users->getUsername(enrolledStudents[i].uid)<<endl;
												}//end forloop

												cout<<"\n"<<"Hit enter to return to enroll menu";
												cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
												cin.get();
											} else{
												cout << "Please enter a student ID to delete student from course:"<<endl;
												cin>>studentID;
												if(db->users->getUsername(studentID).compare("none")==0){//confirm the ID matches a users
													cout<<"User does not exist"<<endl;
													cout<<"Hit enter continue";
													cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
													cin.get();
												}else {
													db->enrolled->Unenroll(studentID,newCourse->courseID);
													cout<<"User deleted successfully"<<endl;
												}
											}
										}while(true);
									}// end menu to delete students from the course

									if(choice == 3){//menu to view/edit quizzes for the course for teacher

										do{//QUIZ MENU
											system("CLS");
											for(int i = 0;i<8;i++)
												cout<<endl;

											quizList = newCourse->getQuizList();//get quizzes for course
											cout << "Quiz list for "<<newCourse->getName()<<"\n"<< endl;
											cout << "Quiz ID"<<"\t"<<"Open Date"<<"\t"<<"\t"<<"\t"<<"Closed Date"<< endl;

											for(int i=0; i < (int) quizList.size();i++){//list quizzes for course			
												cout <<quizList[i].qid<<"\t"<<ConvertDatetoStr(quizList[i].openDate)<<"\t"<<ConvertDatetoStr(quizList[i].closeDate)<<endl;
											}

											cout<<"\n";									
											cout << "- Enter \"1\" to create a quiz for this course"<<endl;
											cout << "- Enter \"2\" to delete a quiz for this course"<<endl;
											cout << "- Enter \"3\" to view a quiz for this course"<<endl;
											cout<< "- Enter \"0\" to go to the previous menu: " <<endl;
											cin >> choice;

											if(choice == 0){//logout
												break;
												cout<<"\n";
											}else if(choice == 1){//create quiz menu
												newQuiz = newCourse->creatQuiz();
												vector<string>questions;
												vector<string> answers;
												system("CLS");
												for(int j = 0;j<8;j++)
													cout<<endl;
												cout << "Creat a quiz menu for course: "<<newCourse->getName()<<"\n"<<"\n"<<endl;
												cout << "Please enter open date for quiz"<<endl;
												time_t rawtime, openTime, closeTime;
												struct tm * timeinfo;
												int year, month ,day, minutes, numQuestions;

												/* prompt user for date */
												printf ("Enter year: "); scanf ("%d",&year);
												printf ("Enter month: "); scanf ("%d",&month);
												printf ("Enter day: "); scanf ("%d",&day);

												/* get current timeinfo and modify it to the user's choice */
												time ( &rawtime );
												timeinfo = localtime ( &rawtime );
												timeinfo->tm_year = year - 1900;
												timeinfo->tm_mon = month - 1;
												timeinfo->tm_mday = day;

												/* call mktime: timeinfo->tm_wday will be set */
												openTime = mktime ( timeinfo );
												newQuiz->setOpenDate(openTime);

												cout <<"\n"<< "Please enter close date for quiz"<<endl;
												/* prompt user for date */
												printf ("Enter year: "); scanf ("%d",&year);
												printf ("Enter month: "); scanf ("%d",&month);
												printf ("Enter day: "); scanf ("%d",&day);

												/* get current timeinfo and modify it to the user's choice */
												time ( &rawtime );
												timeinfo = localtime ( &rawtime );
												timeinfo->tm_year = year - 1900;
												timeinfo->tm_mon = month - 1;
												timeinfo->tm_mday = day;

												/* call mktime: timeinfo->tm_wday will be set */
												closeTime = mktime ( timeinfo );
												newQuiz->setCloseDate(closeTime);

												cout <<"\n"<< "Please enter time limit for quiz (in minutes)"<<endl;
												scanf ("%d",&minutes);
												newQuiz->setTimeLimit(minutes);

												cout <<"\n"<< "Please enter number of questions"<<endl;
												scanf ("%d",&numQuestions);
												cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
												for(int k=0;k<numQuestions;k++){
													system("CLS");
													for(int j = 0;j<8;j++)
														cout<<endl;
													cout << "Creat a quiz menu for course: "<<newCourse->getName()<<"\n"<<"\n"<<endl;	

													cout << "Please enter question:"<<endl;
													//question="";
													string question;

													getline (cin,question);
													questions.push_back(question);
													//answer ="";
													for(int i=1;i<6;i++){//get answers
														string answer;
														if(i<5){
															cout <<"\n"<< "Please enter answer choice "<<i<<endl;
															//cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
															getline (cin,answer);
															answers.push_back(answer);
														}else{
															cout <<"\n"<< "Please enter correct choice "<<i<<endl;
															//cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
															getline (cin,answer);
															answers.push_back(answer);
														}
														//answer="";
													}

												}//end for loop enter questions and answers

												//send string vector array to quiz object where it will store and package the questions 
												newQuiz->setQuestions(questions);
												//set answers in quiz object
												newQuiz->setAnswers(answers);
												//save quiz
												newQuiz->saveQuiz();

												//clear vector containor
												questions.clear();
												answers.clear();
											}else if(choice == 2){//delete a quiz menu
												cout<<"\n";									
												cout << "Please enter quiz ID to delete:"<<endl;
												cin>>qid;
												newCourse->deleteQuiz(qid);
											}else if(choice == 3){//to view a quiz menu
												cout<<"\n";									
												cout << "Please enter quiz ID to show:"<<endl;
												cin>>qid;
												newQuiz = newCourse->getQuiz(qid,localUser->userID,newCourse->courseID);
												system("CLS");
												//create question data struct vector array for questions
												vector<db_question_data> displayQuestions = newQuiz->getQuestions();
												//display questions sequencially on the screen
												for (int i = 0; i < (int) displayQuestions.size(); i++) {

													cout <<"Question "<< i+1 <<". "<<displayQuestions[i].question <<"\n"<< endl;
													cout <<"A"<<". "<<displayQuestions[i].answer1 << endl;
													cout <<"B"<<". "<<displayQuestions[i].answer2 << endl;
													cout <<"C"<<". "<<displayQuestions[i].answer3 << endl;
													cout <<"D"<<". "<<displayQuestions[i].answer4 << endl;
													cout <<"\n"<<"Correct Answer: "<< displayQuestions[i].correct_answer<< endl;
												}
												cout<<"Hit enter to continue";
												cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
												cin.get();
											}//end if-else to view a quiz

										}while(true);//end while for quiz menu teacher

									}//end menu to view/edit quizzes for the course

									if(choice == 4){//teacher/course content menu/view gradebook option
										vector<db_enrolled_data> enrolledStudents = newCourse->getStudents();
										vector<db_quiz_data> courseQuizList = newCourse->getQuizList();
										cout<<"Student ID#\tQ1(%)\tQ1(%)\tQ2(%)\tQ3(%)\tQ4(%)\tQ5(%)\tQ6(%)"<<"\n"<<endl;

										for(int i=0; i < (int) enrolledStudents.size();i++){//list quizzes for each student in course and grades			
											cout <<enrolledStudents[i].uid<<"\t"<<"\t";
											for(int j=0; j < (int) courseQuizList.size();j++){
												if(db->scores->getUserQuizScore(enrolledStudents[i].uid, courseQuizList[j].qid) ==-1){
													cout<<"0"<<"\t";
												}else{
													cout<<db->scores->getUserQuizScore(enrolledStudents[i].uid, courseQuizList[j].qid)<<"\t";
												}
											}
											cout<<"\n"<<"\n";
										}//end forloop 

										cout<<"Hit enter to continue";
										cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
										cin.get();
									}//end if for(choice == 4)teacher/course content menu/view gradebook option

								}while(true);//end do loop view/edit course content teacher menu
							}
							cout<<"\n";
						}while(true);//end first do-while loop
					}//end else


				}else{//if login is not valid
					cout << "Login Failed. Check username/password combination." << endl;
				}//end else
			}//LOGIN MENU
			if (choice==2) {//REGISTER

				system("CLS");
				for(int j = 0;j<7;j++)
					cout<<endl;
				string userName, firstName, lastName, passWord, secQ, secA, userRole;
				user_role_t userType;

				cout << "REGISTRATION"<<"\n"<<"\n"<<endl;	
				cout << "Please enter your first name"<<endl;
				cin>>firstName;
				cout << "Please enter your last name"<<endl;
				cin>>lastName;
				cout << "Please enter a username"<<endl;
				cin>>userName;
				cout << "Please enter a password"<<endl;
				cin>>passWord;
				cout << "Please enter a security question"<<endl;
				cin.ignore();//flushout any left over "/n" so the prompt will stop at getline.
				getline (cin,secQ);
				cout << "Please enter a security answer"<<endl;
				getline (cin,secA);
				cout << "Please enter account type (student or teacher)"<<endl;
				cin>>userRole;
				if(userRole.compare("student")==0){
					userType =student;
				}else{
					userType =teacher;
				}

				db_user_data *user = db->newUserRow();
				WriteStructValue(user->username,userName);
				WriteStructValue(user->password, passWord);
				WriteStructValue(user->lastName, lastName);
				WriteStructValue(user->firstName, firstName);
				user->userRole = userType;
				db->users->Insert(user);
			}

			}while(choice!=3);//end do-while 


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


string ConvertDatetoStr(time_t time){

	string DateStr;
	struct tm * timeinfo;

	timeinfo = localtime ( &time );
	DateStr=asctime (timeinfo);
	DateStr.erase (DateStr.size()-1,1);
	return DateStr;
}