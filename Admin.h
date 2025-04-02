//admin definition
//Iyana Taylor

#ifndef ADMIN_H
#define ADMIN_H

//#include "User.h"
#include "Association.h"
#include "Club.h"
#include "Athlete.h"
#include "Coach.h"
#include "Sponsor.h"

#include <iostream>
#include <string>
using namespace std;

class Admin{
	private:
		//pointers to respective class objects
		//User* user;
		Association* association;
		Club* club;
		Coach* coach;
		Athlete* athlete;
		Sponsor* sponsor;

	public:
		//constructor
		
		//default con
		Admin();
		
		//primary con
    	Admin(Association* a, Club* c, Coach* co, Athlete* ath, Sponsor* sp);
				
		//-------------------------------------------------------------------------------------------------------------------management
		//-------------------------------------------------------------association
		void AddOrEditAssociation(); //create acc and edit
		void ViewAssociation(); //display
		void DeleteAssociation(); //delete acc
		
		//add or delete from association's list of clubs
		void AddOrRemoveClubFromAsso();
		
		//----------------------------------------------------------------club
		void AddOrEditClub(); //create acc and edit
		void ViewClub(); //display
		void DeleteClub(); //delete acc
		
		//add or delete from clubs's list of athletes
		void AddOrRemoveAthleteFromClub();
		
		//add or delete from clubs's list of coaches
		void AddOrRemoveCoachFromClub();
		
		//-------------------------------------------------------------athlete
		void AddOrEditAthlete(); //create acc and edit
		void ViewAthlete(); //display
		void DeleteAthlete(); //delete acc
		
		//add or delete from athlete's list of sponsors
		void AddOrDeleteSponsorFromAthlete();
		
		//add or delete from athlete's list of coaches
		void AddOrDeleteCoachFromAthlete();
		
		//-------------------------------------------------------------coach
		void AddOrEditCoach(); //create acc and edit
		void ViewCoach(); //display
		void DeleteCoach(); //delete acc
		
		//------------------------------------------------------------sponsor
		void AddOrEditSponsor(); //create acc and edit
		void ViewSponsor(); //display
		void DeleteSponsor(); //delete acc
		
		//--------------------------------------------------------------------------------------------------------------------------reports
		//all records
		void AllAssociationsReport();
		void AllClubsReport();
		void AllAthletesReport();
		void AllCoachesReport();
		void AllSponsorsReport();
		
		//--------------------------------------------------------in/ not in reports
		//association's list of clubs
		void ClubsInAnAssociationReport();
		void ClubsNotInAnAssociationReport();
		
		//club's list of athletes and coaches
		void AthletesInAClubReport();
		void AthletesNotInAClubReport();
		void CoachesInAClubReport();
		void CoachesNotInAClubReport();
		
		//athlete's list of sponsors
		void AthletesWithASponsorReport();
		void AthletesWithoutASponsorReport();
		void AthletesWithACoachReport();
		void AthletesWthoutACoachReport();
		
		//-----------------------------------------------------------------------------------------------------------------------search and display
		void SearchAssociation();
		void SearchClub();
		void SearchAthlete();
		void SearchCoach();
		void SearchSponsor();				
};

#endif
