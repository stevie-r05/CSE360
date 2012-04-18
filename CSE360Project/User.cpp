// Created by Stevie Robinson

// The User.cpp is the C++ file that implements the User class functionality. Using User.h as a general outline for its functionality, the User
// class prepares the global user object that will hold a user's login information throughout the lifetime of the program.

// Created on 6 April 2012.

#include "stdafx.h"
#include "User.h"
#include "core_header.h"

using namespace std;

namespace CSE360Project {

	User::User()
	{
		userID = 0;
	}
	User::User(int uID)
	{
		db_user_data userData = db->users->getUserData(uID);
		userID = userData.uid;
		username = userData.username;
		firstName = userData.firstName;
		lastName = userData.lastName;
		securityQ = userData.securityQuestion; 
		securityA = userData.securityAnswer;
		password = userData.password;
		userRole = userData.userRole;

		if(userRole == 0){//if its a student load enrolled courses
		enrolledCourses = db->enrolled->getEnrolledCourses(uID); 
		}else{//if teacher load taught courses
			taughtCourses = db->courses->getTaughtCourses(uID);
		}
		
	}

	void User::setUserID(int uID)
	{
		userID = uID;
	}

	int User::getUserID()
	{
		return userID;
	}

	void User::setUsername(string username)
	{
		this->username = username;
	}

	string User::getUsername()
	{
		return username;
	}

	void User::setPassword(string password)
	{
		this->password = password;
	}

	string User::getPassword()
	{
		return password;
	}

	void User::setLastName(string lastName)
	{
		this->lastName = lastName;
	}

	string User::getLastName()
	{
		return lastName;
	}

	void User::setFirstName(string firstName)
	{
		this->firstName = firstName;
	}

	string User::getFirstName()
	{
		return firstName;
	}

	void User::setSecurityQ(string securityQ)
	{
		this->securityQ = securityQ;
	}

	string User::getSecurityQ()
	{
		return securityQ;
	}

	void User::setSecurityA(string securityA)
	{
		this->securityA = securityA;
	}

	string User::getSecurityA()
	{
		return securityA;
	}

	void User::setUserRole(user_role_t userRole)
	{
		this->userRole = userRole;
	}

	user_role_t User::getUserRole()
	{
		return userRole;
	}

	// vector<db_course_data> User::getCourses() - Again, not sure if need to remove or not.

	// NOTE: Needs the Course constructor to be modified to create an existing Course from the DB_Courses.
	
	Course User::getCourse(int courseID)
	{
		Course course = Course::Course(courseID);
		return course;
	}

	// Adds courseID to userCourses in User object, as well as DB_Enrolled. Need to check if userCourses is going to be kept.
	void User::addCourseID(int courseID)
	{
		//enrolledCourses.push_back(courseID);
		//db->enrolled->Insert(userID, courseID);
	}

	// I'm assuming that what this does is saves the user to the database.
	bool User::saveUser()
	{
		// Check bool?
		db_user_data toInsert;
		toInsert.uid = userID;
		WriteStructValue(toInsert.username,username);
		WriteStructValue(toInsert.password,password);
		WriteStructValue(toInsert.lastName,lastName);
		WriteStructValue(toInsert.firstName,firstName);
		WriteStructValue(toInsert.securityQuestion,securityQ);
		WriteStructValue(toInsert.securityAnswer,securityA);
		toInsert.userRole = userRole;

		db->users->Update(toInsert);
		return true;

		// ADD: Check in UI for username existing
	}

	bool User::login(string username, string password)
	{
		// Move login function to Login UI?//I agree - D.N.
		return true;
	}

	User::~User() {

	}
}