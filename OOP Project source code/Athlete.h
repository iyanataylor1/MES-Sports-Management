//athlete definition
//Kaylen Eastwood

#ifndef ATHLETE_H
#define ATHLETE_H

#include "User.h"
//#include "Club.h" - forwardly declare it instead so we don't have circular dependency
class Club;
#include "Sponsor.h"
#include "Coach.h"
#include "Agent.h"
class Association;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

class Athlete : public User{
	private:
		Association* association;
		Club* club;  // Pointer to Club object, implementing aggregation relationship between athlete and club. athlete uses club but its lifetime isn't dependent on it
		
		string athTRN, athFN, athMN, athLN, athGen, athDOB, athNationality;
		float athHeight, athWeight, annualFee;
		
		float endorsAmnt; //will take value of sponAmnt and be used to calculate annualfee
		
		Agent agent;
		
		vector<Sponsor*> sponsors;  // List of sponsor pointers for the aggregation relationship [athl<>---spon]
		vector<Coach*> coaches;  // List of coach pointers for the aggregation relationship [athl<>---coach]
		
	public:
		//constructors
		
		//default constructor
		Athlete();
		
		//primary constructor
		Athlete(string, string, string, string, string, string, string, float, float, float, string, string, string, string, string, string); //the last 6 strings are for agent
		
		//mutators
		void SetClub(Club* c);
		void SetAthTRN(string);
		void SetAthFN(string);
		void SetAthMN(string);
		void SetAthLN(string);
		void SetAthGen(string);
		void SetAthDOB(string);
		void SetAthNationality(string);
		void SetAthHeigtht(float);
		void SetAthWeight(float);
		void SetAnnualFee(float);
		
		//accessors
		Club* GetClub();
		string GetAthTRN();
		string GetAthFN();
		string GetAthMN();
		string GetAthLN();
		string GetAthGen();
		string GetAthDOB();
		string GetAthNationality();
		float GetAthHeigtht();
		float GetAthWeight();
		float GetAnnualFee();
		
		//methods to manipulate and set endorsement variable to sponsor amount value
		void SetEndorsAmnt(Sponsor &spon);
		float GetEndorsAmnt();
		
		//calculate/ pay methods 
		void PayAnnualFee();
		
		//switch club
		void SwitchClub();
		
		//account manipulation
		void CreateAccount();
		void EditAccount();
		void Search();
		void DeleteAccount();
		
		//display athlete
		void Show();
		void ShowAll();	
		
		//add and delete sponsor
		void AddSponsor();
        void RemoveSponsor();
        
        std::vector<Sponsor*> GetSponsorsWithAthlete();
        std::vector<Sponsor*> GetSponsorsWithoutAthlete();
        
		//add and delete coach
		void AddCoach();
        void RemoveCoach();	
        
        std::vector<Coach*> GetCoachesWithAthlete();
        std::vector<Coach*> GetCoachesWithoutAthlete();
        
        
        //find coach by trn (used in add and remove coach - admin)
        Coach* findCoachByTRN(string);
        
        //find sponsor by name 
        Sponsor* findSponsorByName(string);
};

#endif
