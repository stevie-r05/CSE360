// CSE360Project.cpp : main project file.

#include "stdafx.h"
#include "main_form.h"
#include "timingClass.h"
#include "DB_Users.h"
#include "DB_Courses.h"

using namespace std;
using namespace CSE360Project;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	/*COURSES DEBUG
	DB_Courses *courses = new DB_Courses();
	courses->outputAllCourses();
	
	db_course_data *course = new db_course_data;
	course->courseName = "dnewton";
	course->uid = 1;
	courses->Insert(course);

	courses->outputAllCourses();
	*/

	DB_Users *db = new DB_Users();
	
	db->outputAllUsers();
	
	//write test user
	string a;
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
	cout << "------------------------------" << endl;
	//db->Write();


	db->outputAllUsers();

	

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	// Create the main window and run it
	Application::Run(gcnew main_form());
	return 0;
}
