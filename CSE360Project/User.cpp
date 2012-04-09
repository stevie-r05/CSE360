// Created by Stevie Robinson

// The User.cpp is the C++ file that implements the User class functionality. Using User.h as a general outline for its functionality, the User
// class prepares the global user object that will hold a user's login information throughout the lifetime of the program.

// Created on 6 April 2012.

#pragma once
#include "stdafx.h"
#include "User.h"
#include "core_header.h"

using namespace std;

namespace CSE360Project {

	
	User::User(int uID)
	{
		userID = uID;
		userName = db->users->getUsername(uID);
		firstName = db->users->getFirstname(uID);
		lastName = db->users->getLastname(uID);
		userRole = db->users->getUserRole(uID);
		// See about using getUserData instead
	}

	void User::setUserID(int uID)
	{
		userID = uID;
	}

	int User::getUserID()
	{
		return userID;
	}

	void User::setUserName(string userName)
	{
		this->userName = userName;
	}

	string User::getUserName()
	{
		return userName;
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

	void User::setSecurityQ(string securityQ);
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

	//vector<db_course_data> User::getCourses() - Again, not sure if need to remove or not.

	/* 
	NOTE: Needs the Course constructor to be modified to create an existing Course from the DB_Courses.
	
	Course User::getCourse(int courseID)
	{
		Course course = Course::Course(courseID);
		return course;
	}
	*/



	User::~User() {
	}
}