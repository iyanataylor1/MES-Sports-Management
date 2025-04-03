//user class definition
//Travis Callam

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
	protected:
		string userName, password;
	public:
		//constructors 
		//default constructor
		User();
		
		//primary constructor
		User(string, string); 
		
		//mutators
		void SetUserName(string);
		void SetPassword(string);
		
		//accessors
		string GetUserName();
		string GetPassword();
		
		//create account method - this is to write one record to the file at a time, DO NOT loop it in the class but rather in admin by calling it again after asking the user
		virtual void CreateAccount() = 0;
		
		//edit account method
		virtual void EditAccount() = 0;
		
		virtual void Search() = 0;
		
		//delete account
		virtual void DeleteAccount() = 0;
		
		//show user info - just the attributes in this class (parent - user)
		virtual void Show() = 0;
		virtual void ShowAll() = 0;
		
		virtual ~User() {}
};

#endif 
