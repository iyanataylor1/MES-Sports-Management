//association definition
//Paris Scott

#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include "User.h"
#include "Club.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

class Association : public User
{
	private:
		int assoID, assoClubAm;
		string assoName, assoAddr;
		
		std::vector<Club*> clubs;  // List of Club pointers for aggregation relationship [asso<>---club]
		
	public:
		//constructors
		//default constructor
		Association();
		
		//primary constructor
		Association(int, int, string, string); 
		
		//mutators
		void SetAssoID(int);
		void SetAssoClubAm(int);
		void SetAssoName(string);
		void SetAssoAddr(string);
		
		//accessors
		int GetAssoID();
		int GetAssoClubAm();
		string GetAssoName();
		string GetAssoAddr();

		
		//account manipulation
		void CreateAccount();
		void EditAccount();
		void Search();
		void DeleteAccount();
		
		//display method
		void Show();
		void ShowAll();
		
		//add and delete club from association's club list
		void AddClub();
        void RemoveClub();
        
        std::vector<Club*> GetClubsWithAssociation();
    	std::vector<Club*> GetClubsWithoutAssociation();
        
        //find club by name (used in add and remove club)
        Club* findClubByCode(int);
};

#endif
