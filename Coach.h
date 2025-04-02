//coach definition
//Kaylen Eastwood

#ifndef COACH_H
#define COACH_H

#include "User.h"
//#include "Club.h" - forwardly declare it instead so we don't have circular dependency
class Club;
class Athlete;
class Association;

#include <iostream>
#include <string>
using namespace std;

class Coach : public User{
	private:
		Association* association;
		Club* club;
		Athlete* athl;
		
		string coachTRN, coachFN, coachMN, coachLN, coachDOB, coachGen, coachEmpDate, coachSepDate;
		float commission;
		
	public: 
		//constructors
		
		//default con
		Coach();
		
		//primary con
		Coach(string, string, string, string, string, string, string, string, float);
		
		//mutators
		void SetClub(Club* c);
		void SetAthlete(Athlete* at);
		void SetCoachTRN(string);
		void SetCoachFN(string);
		void SetCoachMN(string);
		void SetCoachLN(string);
		void SetCoachDOB(string);
		void SetCoachGen(string);
		void SetCoachEmpDate(string);
		void SetCoachSepDate(string);
		void SetCommission(float);
		
		//accessors
		Club* GetClub();
		Athlete* GetAthlete();
		string GetCoachTRN();
		string GetCoachFN();
		string GetCoachMN();
		string GetCoachLN();
		string GetCoachDOB();
		string GetCoachGen();
		string GetCoachEmpDate();
		string GetCoachSepDate();
		float GetCommission();
		
		//other methods
		
		//switch club
		void SwitchClub();
		
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
