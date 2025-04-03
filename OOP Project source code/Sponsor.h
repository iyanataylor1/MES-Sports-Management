//sponsor definition
//Travis Callam

#ifndef SPONSOR_H
#define SPONSOR_H

#include "User.h" 
class Athlete;
class Club;

#include <iostream>
#include <string>
using namespace std;

class Sponsor : public User{
	private: 
		string sponName;
		float sponAmnt; //replace endorseAmnt with sponAmnt in club and athlete
		
		Club* club;
		Athlete* athlete;
	public:
		//constructors
		
		//default con
		Sponsor();
		
		//primary con
		Sponsor(string, float);
		
		//mutators
		void SetAthlete(Athlete* at);
		void SetSponName(string);
		void SetSponAmnt(float);
		
		//accessors
		Athlete* GetAthlete();
		string GetSponName();
		float GetSponAmnt();
		
		//other methods
		
		//switch athlete
		void SwitchAthlete();
		
		//account manipulation
		void CreateAccount();
		void EditAccount();
		void Search();
		void DeleteAccount();
		
		//display
		void Show();
		void ShowAll();
};

#endif
