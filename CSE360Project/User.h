// Created by Stevie Robinson

// User.h is the header file for the User.cpp file, which will is used to hold a user's information locally during program use.
// It will also be integrated into the Teacher and Administrator classes, which inherit from User.

// File created on 3 April 2012.

#pragma once

#include "stdafx.h"
#include "Course.h"

using namespace std;

namespace CSE360Project {

	class User {
	public:
		User(int uID); // Used to initialize a user object from a retrieved uid on login.

		// Methods are straight from the Visio diagram.
		void setUserID(int uID);
		int getUserID();
		void setUserName(string userName);
		string getUserName();
		void setPassword(string password);
		string getPassword();
		void setLastName(string lastName);
		string getLastName();
		void setFirstName(string firstName);
		string getFirstName();
		void setSecurityQ(string securityQ);
		string getSecurityQ();
		void setSecurityA(string securityA);
		string getSecurityA();
		void setUserRole(user_role_t userRole);
		user_role_t getUserRole();
		vector<db_course_data> getCourses(); // We need to check out this method; were we going to get rid of it?
		Course getCourse(int courseID);
		void addCourseID(int courseID);
		bool saveUser();
		bool login(string userName, string password);
		void logout();

		virtual ~User();
	
	protected:

		int userID;
		string userName;
		string password;
		string lastName;
		string firstName;
		string securityQ;
		string securityA;
		user_role_t userRole; // Change in Visio to struct user_role_t? Right now it's a string.
		vector<db_course_data> userCourses; // Need to change in Visio, or decide what to do with it, at least. Will we actually have this?

	}; // end User class

}