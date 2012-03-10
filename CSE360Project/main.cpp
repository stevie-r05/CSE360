// CSE360Project.cpp : main project file.

#include "stdafx.h"
#include "main_form.h"
#include "timingClass.h"
#include "DB_Users.h"

using namespace std;
using namespace CSE360Project;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	DB_Users *db = new DB_Users();
	
	db->outputAllUsers();
	
	//write test user
	
	db_users_data *user = new db_users_data;
	user->username = "dnewton";
	user->password = "david_password";
	user->lastName = "Newton";
	user->firstName = "David";
	user->securityQuestion = "Hey there?";
	user->securityAnswer = "Hi.";
	user->userRole = teacher;

	db->Insert(user);

	db->Write();

	db->outputAllUsers();

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	// Create the main window and run it
	Application::Run(gcnew main_form());
	return 0;
}
