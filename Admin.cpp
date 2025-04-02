//admin definition
//Iyana Taylor

#include "User.h"
#include "Association.h"
#include "Club.h"
#include "Athlete.h"
#include "Sponsor.h"
#include "Coach.h"
#include "Admin.h"

#include <iostream>
#include <string>
using namespace std;

Admin::Admin()
: association(NULL), club(NULL), coach(NULL), athlete(NULL), sponsor(NULL)
{}

Admin::Admin(Association* a, Club* c, Coach* co, Athlete* ath, Sponsor* sp)
: association(a), club(c), coach(co), athlete(ath), sponsor(sp)
{}

//---------------------------------------------------------------------------------------------------------------------------------management
//--------------------------------------------------------------association
void Admin::AddOrEditAssociation() //create acc and edit
{
    int choice;
    
    cout << "\n1. Create new association account\n";
    cout << "2. Edit existing association account\n";
    
    // Get user choice
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    
    if(association != NULL) { // Check if association is not NULL
        if(choice == 1){
            association->CreateAccount();
        }
        else if(choice == 2)
        {
            association->EditAccount();
        }
        else
        {
            cout << "\n\nInvalid choice, either 1 to create or 2 to edit.\n\n"; // Added missing semicolon
        }
    } else {
        cout << "\n\nAssociation pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::ViewAssociation() //display
{
    if(association != NULL) { // Check if association is not NULL
		association->Show();
    } else {
        cout << "\n\nAssociation pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::DeleteAssociation() //delete acc
{
	if(association != NULL) { // Check if association is not NULL
		association->DeleteAccount();
    } else {
        cout << "\n\nAssociation pointer is NULL. Cannot perform operation.\n\n";
    }
}

//add or delete from association's list of clubs		
void Admin::AddOrRemoveClubFromAsso()
{
    int choice;
    
    cout << "\n1. Add club to association\n";
    cout << "2. Remove club from association\n\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(association != NULL) { // Check if association is not NULL
        if(choice == 1){
            try {
                association->AddClub();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else if(choice == 2)
        {
            try {
                association->RemoveClub();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else
        {
            cout << "\n\nInvalid choice, enter 1 to add or 2 to remove.\n\n";
        }
    } else {
        std::cout << "\n\nAssociation pointer is NULL. Cannot perform operation.\n\n";
    }
}
		
		
//--------------------------------------------------------------club
void Admin::AddOrEditClub() //create acc and edit
{
	int choice;
    
    cout << "\n1. Create new club account\n";
    cout << "2. Edit existing club account\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(club != NULL) { // Check if club is not NULL
        if(choice == 1){
            club->CreateAccount();
        }
        else if(choice == 2)
        {
            club->EditAccount();
        }
        else
        {
            cout << "\n\nInvalid choice, either 1 to create or 2 to edit.\n\n"; // Added missing semicolon
        }
    } else {
        cout << "\n\nClub pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::ViewClub() //display
{
	if(club != NULL) { // Check if club is not NULL
		club->Show();
    } else {
        cout << "\n\nClub pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::DeleteClub() //delete acc
{
	if(club != NULL) { // Check if club is not NULL
		club->DeleteAccount();
    } else {
        cout << "\n\nClub pointer is NULL. Cannot perform operation.\n\n";
    }
}

//add or delete from club's list of athletes
void Admin::AddOrRemoveAthleteFromClub()
{
    int choice;
    
    cout << "\n1. Add athlete to club\n";
    cout << "2. Remove athlete from club\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(club != NULL) { // Check if club is not NULL
        if(choice == 1){
            try {
                club->AddAthlete();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else if(choice == 2)
        {
            try {
                club->RemoveAthlete();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else
        {
            cout << "\n\nInvalid choice, enter 1 to add or 2 to remove.\n\n";
        }
    } else {
        std::cout << "\n\nClub pointer is NULL. Cannot perform operation.\n\n";
    }
}
		
//add or delete from clubs's list of coaches
void Admin::AddOrRemoveCoachFromClub()
{
    int choice;
    
    cout << "\n1. Add coach to club\n";
    cout << "2. Remove coach from club\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(club != NULL) { // Check if club is not NULL
        if(choice == 1){
            try {
                club->AddCoach();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else if(choice == 2)
        {
            try {
                club->RemoveCoach();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else
        {
            cout << "\n\nInvalid choice, enter 1 to add or 2 to remove.\n\n";
        }
    } else {
        std::cout << "\n\nClub pointer is NULL. Cannot perform operation.\n\n";
    }
}
		
//----------------------------------------------------------athlete
void Admin::AddOrEditAthlete() //create acc and edit
{
	int choice;
    
    cout << "\n1. Create new athlete account\n";
    cout << "2. Edit existing athlete account\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(athlete != NULL) { // Check if athlete is not NULL
        if(choice == 1){
            athlete->CreateAccount();
        }
        else if(choice == 2)
        {
            athlete->EditAccount();
        }
        else
        {
            cout << "\n\nInvalid choice, either 1 to create or 2 to edit.\n\n"; // Added missing semicolon
        }
    } else {
        cout << "\n\nAthlete pointer is NULL. Cannot perform operation.\n\n";
    }
}
void Admin::ViewAthlete() //display
{
	if(athlete != NULL) { // Check if athlete is not NULL
		athlete->Show();
    } else {
        cout << "\n\nAthlete pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::DeleteAthlete() //delete acc
{
	if(athlete != NULL) { // Check if athlete is not NULL
		athlete->DeleteAccount();
    } else {
        cout << "\n\nAthlete pointer is NULL. Cannot perform operation.\n\n";
    }
}

//add or delete from athlete's list of sponsors
void Admin::AddOrDeleteSponsorFromAthlete()
{
    int choice;
    
    cout << "\n1. Add sponsor to athlete\n";
    cout << "2. Remove sponsor from athlete\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(club != NULL) { // Check if club is not NULL
        if(choice == 1){
            try {
                athlete->AddSponsor();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else if(choice == 2)
        {
            try {
                athlete->RemoveSponsor();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else
        {
            cout << "\n\nInvalid choice, enter 1 to add or 2 to remove.\n\n";
        }
    } else {
        std::cout << "\n\nAthlete pointer is NULL. Cannot perform operation.\n\n";
    }
}
		
//add or delete from athlete's list of coaches
void Admin::AddOrDeleteCoachFromAthlete()
{
    int choice;
    
    cout << "\n1. Add coach to athlete\n";
    cout << "2. Remove coach from athlete\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(club != NULL) { // Check if club is not NULL
        if(choice == 1){
            try {
                athlete->AddCoach();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else if(choice == 2)
        {
            try {
                athlete->RemoveCoach();
            } catch(const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << '\n';
            }
        }
        else
        {
            cout << "\n\nInvalid choice, enter 1 to add or 2 to remove.\n\n";
        }
    } else {
        std::cout << "\n\nAthlete pointer is NULL. Cannot perform operation.\n\n";
    }
}
		
//------------------------------------------------------coach
void Admin::AddOrEditCoach() //create acc and edit
{
	int choice;
    
    cout << "\n1. Create new coach account\n";
    cout << "2. Edit existing coach account\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(coach != NULL) { // Check if coach is not NULL
        if(choice == 1){
            coach->CreateAccount();
        }
        else if(choice == 2)
        {
            coach->EditAccount();
        }
        else
        {
            cout << "\n\nInvalid choice, either 1 to create or 2 to edit.\n\n"; // Added missing semicolon
        }
    } else {
        cout << "\n\nCoach pointer is NULL. Cannot perform operation.\n\n";
    }
}
void Admin::ViewCoach() //display
{
	if(coach != NULL) { // Check if coach is not NULL
		coach->Show();
    } else {
        cout << "\n\nCoach pointer is NULL. Cannot perform operation.\n\n";
    }
}
void Admin::DeleteCoach() //delete acc
{
	if(coach != NULL) { // Check if coach is not NULL
		coach->DeleteAccount();
    } else {
        cout << "\n\nCoach pointer is NULL. Cannot perform operation.\n\n";
    }
}
		
//---------------------------------------------------sponsor
void Admin::AddOrEditSponsor() //create acc and edit
{
	int choice;
    
    cout << "\n1. Create new sponsor account\n";
    cout << "2. Edit existing sponsor account\n";
    
    // Get user choice
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    if(sponsor != NULL) { // Check if sponsor is not NULL
        if(choice == 1){
            sponsor->CreateAccount();
        }
        else if(choice == 2)
        {
            sponsor->EditAccount();
        }
        else
        {
            cout << "\n\nInvalid choice, either 1 to create or 2 to edit.\n\n"; // Added missing semicolon
        }
    } else {
        cout << "\n\nSponsor pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::ViewSponsor() //display
{
	if(sponsor != NULL) { // Check if sponsor is not NULL
		sponsor->Show();
    } else {
        cout << "\n\nSponsor pointer is NULL. Cannot perform operation.\n\n";
    }
}

void Admin::DeleteSponsor() //delete acc
{
	if(sponsor != NULL) { // Check if sponsor is not NULL
		sponsor->DeleteAccount();
    } else {
        cout << "\n\nSponsor pointer is NULL. Cannot perform operation.\n\n";
    }
}

//--------------------------------------------------------------------------------------------------------------------------reports
//all records
void Admin::AllAssociationsReport()
{
    if (association != NULL) {
        association->ShowAll();
    } else {
        cerr << "\n\nError: Association pointer is null." << endl;
    }
}

void Admin::AllClubsReport()
{
    if (club != NULL) {
        club->ShowAll();
    } else {
        cerr << "\n\nError: Club pointer is null." << endl;
    }
}

void Admin::AllAthletesReport()
{
    if (athlete != NULL) {
        athlete->ShowAll();
    } else {
        cerr << "\n\nError: Athlete pointer is null." << endl;
    }
}

void Admin::AllCoachesReport()
{
    if (coach != NULL) {
        coach->ShowAll();
    } else {
        cerr << "\n\nError: Coach pointer is null." << endl;
    }
}

void Admin::AllSponsorsReport()
{
    if (sponsor != NULL) {
        sponsor->ShowAll();
    } else {
        cerr << "\n\nError: Sponsor pointer is null." << endl;
    }
}
		
//--------------------------------------------------------in/ not ==in reports
//association's list of clubs

void Admin::ClubsInAnAssociationReport()
{
	if(association != NULL){
		association->GetClubsWithAssociation();
	}else {
		cerr << "\n\nError: Association pointer is null." << endl;
	}
	
}

void Admin::ClubsNotInAnAssociationReport()
{
	if(association != NULL){
		association->GetClubsWithoutAssociation();
	} else{
		cerr << "\n\nError: Association pointer is null." << endl;
	}
	
}

//club's list of athletes and coaches
void Admin::AthletesInAClubReport()
{
	if(club != NULL){
		club->GetAthletesWithClub();
	} else {
		cerr << "\n\nError: Club pointer is null." << endl;
	}
	
}

void Admin::AthletesNotInAClubReport()
{
	if(club != NULL){
		club->GetAthletesWithoutClub();
	}else{
		cerr << "\n\nError: Club pointer is null." << endl;
	}
	
}

void Admin::CoachesInAClubReport()
{
	if(club != NULL){
		club->GetCoachesWithClub();
	}else {
		cerr << "\n\nError: Club pointer is null." << endl;
	}
	
}

void Admin::CoachesNotInAClubReport()
{
	if(club != NULL){
		club->GetCoachesWithoutClub();
	}else {
		cerr << "\n\nError: Club pointer is null." << endl;
	}
}
		
//athlete's list of sponsors and coaches
void Admin::AthletesWithASponsorReport()
{
	if(athlete != NULL){
		athlete->GetSponsorsWithAthlete();
	}else {
		cerr << "\n\nError: Athlete pointer is null." << endl;
	}	
}

void Admin::AthletesWithoutASponsorReport()
{
	if(athlete != NULL){
		athlete->GetSponsorsWithoutAthlete();
	}else {
		cerr << "\n\nError: Athlete pointer is null." << endl;
	}	
}

void Admin::AthletesWithACoachReport()
{
	if(athlete != NULL){
		athlete->GetCoachesWithAthlete();
	}else {
		cerr << "\n\nError: Athlete pointer is null." << endl;
	}
}

void Admin::AthletesWthoutACoachReport()
{
	if(athlete != NULL){
		athlete->GetCoachesWithoutAthlete();
	}else {
		cerr << "\n\nError: Athlete pointer is null." << endl;
	}
}

//-----------------------------------------------------------------------------------------------------------------------search and display
void Admin::SearchAssociation()
{
	if(association != NULL){
		association->Search();
	} else{
		cerr << "\n\nError: Association pointer is null." << endl;
	}	
}

void Admin::SearchClub()
{
	if(club != NULL){
		club->Search();
	} else{
		cerr << "\n\nError: Club pointer is null." << endl;
	}	
}
void Admin::SearchAthlete()
{ 
	if(athlete != NULL){
		athlete->Search();
	} else{
		cerr << "\n\nError: Athlete pointer is null." << endl;
	}	
}

void Admin::SearchCoach()
{
	if(coach != NULL){
		coach->Search();
	} else{
		cerr << "\n\nError: Coach pointer is null." << endl;
	}
}
void Admin::SearchSponsor()
{
	if(sponsor != NULL){
		sponsor->Search();
	} else{
		cerr << "\n\nError: Sponsor pointer is null." << endl;
	}
}
		
		
