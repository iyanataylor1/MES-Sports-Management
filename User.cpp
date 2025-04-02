//user class implementation
//Travis Callam

#include "User.h"

#include <iostream>
#include <string>
using namespace std;

//default constructor
User::User()
{
	userName = "";
	password = "";
}

//primary constructor
User::User(string un, string p)
{
	userName = un;
	password = p;
}

//mutators
void User::SetUserName(string un)
{
	userName = un;
}

void User::SetPassword(string p)
{
	password = p;
}

//accessors
string User::GetUserName()
{
	return userName;
}

string User::GetPassword()
{
	return password;
}

//create account
//edit account
//search
//delete account 
//show
//show all
//all the above are implemented in the child classes

//remove main after adding driver
/*
int main(){
	return 0;
}
*/


