//club definition
//Paris Scott

#ifndef CLUB_H
#define CLUB_H

#include "User.h"
#include "Athlete.h"
class Association;
#include "Sponsor.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//update association class to include the composition relationship

class Club : public User{
	private:
		Association* assoc;
		
		int clubCode;
		string clubName, clubColor, clubPresi, clubHeadCoach;
		float clubMemAmnt, clubAssoFee, annualFeeToCoach;
		
		float endorsAmnt; //will take value of sponAmnt and be used to calculate annualfee
		
		vector<Athlete*> athletes;  // List of Athlete pointers for the aggregation relationship [club<>---athlete]
		vector<Coach*> coaches;  // List of Athlete pointers for the aggregation relationship [club<>---coach]
		
	public: 
		//constructors
		
		//default constructor
		Club();
		
		//primary constructor
		Club(int, string, string, string, string, float, float, float);
		
		//mutators
		void SetAssociation(Association* as);
		void SetClubCode(int);
		void SetClubName(string);
		void SetClubColor(string);
		void SetClubPresi(string);
		void SetClubHeadCoach(string);
		void SetClubMemAmnt(float);
		void SetClubAssoFee(float);
		void SetAnnualFeeToCoach(float);
		
		//accessors
		Association* GetAssociation();
		int GetClubCode();
		string GetClubName();
		string GetClubColor();
		string GetClubPresi();
		string GetClubHeadCoach();
		float GetClubMemAmnt();
		float GetClubAssoFee();
		float GetAnnualFeeToCoach();
		
		//methods to manipulate and set endorsement variable to sponsor amount value
		void SetEndorsAmnt(Sponsor &spon);
		float GetEndorsAmnt();
		
		//calculate/ pay methods 
		void PayClubAssoFee();
		void PayAnnualFeeToCoach();
		
		//account manipulation
		void CreateAccount();
		void EditAccount();
		void Search();
		void DeleteAccount();
		
		//display 
		void Show();
		void ShowAll();
		
		//add and delete athlete to/from club's athlete list
		void AddAthlete();
        void RemoveAthlete();	
        
        std::vector<Athlete*> GetAthletesWithClub();
        std::vector<Athlete*> GetAthletesWithoutClub();
        
        //add and delete coach to/from club's coach list
		void AddCoach();
        void RemoveCoach();
        
        std::vector<Coach*> GetCoachesWithClub();
        std::vector<Coach*> GetCoachesWithoutClub();
        
        
        //find athlete by trn (used in add and remove athlete - admin)
        Athlete* findAthleteByTRN(string);
        
        //find coach by trn (used in add and remove coach - admin)
        Coach* findCoachByTRN(string);
};

#endif


