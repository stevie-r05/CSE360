// Created by Stevie Robinson

// The User.cpp is the C++ file that implements the User class functionality. Using User.h as a general outline for its functionality, the User
// class prepares the global user object that will hold a user's login information throughout the lifetime of the program.

// Created on 6 April 2012.

#pragma once
#include "stdafx.h"
#include "User.h"

using namespace std;

namespace CSE360Project
{
	User::User(int uID)
	{
		userID = uID;
		userName = db->users->getUsername(uID);
		firstName = db->users->getFirstname(uID);
		lastName = db->users->getLastname(uID);
		userRole = db->users->getUserRole(uID);
		// See about using getUserData instead
	}


}