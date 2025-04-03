//Sports System Driver
//Iyana Taylor & Kaylen Eastwood 

#include "Admin.h"
#include "User.h"
#include "Association.h"
#include "Club.h"
#include "Athlete.h"
#include "Coach.h"
#include "Sponsor.h"
#include "Agent.h"

#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <limits> // Include this to be able to use std::numeric_limits - a template class in C++ that provides numeric limits of arithmetic types. 
using namespace std;

//declare functions called by main
void adminSection();
void userSection();

void manageAssociation();
void manageClub();
void manageCoach();
void manageAthlete();
void manageSponsor();

void association();
void club();
void coach();
void athlete();
void sponsor();

//void mainSectionMenu(); // Function to display the main section menu

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//these were in main as params int argc, char** argv

int main(int argc, char** argv) {
	
	int sectionOp;
	
	do{
		//maybe change this to mainSectionMenu() so we can use it in other places
		cout << "\n======= Welcome to the Ministry of Entertainment and Sports (MES) Sports Management System =======\n" << endl;
		cout << "MAIN MENU - Select section: " << endl;
		cout << "1. Administrator" << endl;
		cout << "2. User" << endl;
		cout << "3. Exit\n" << endl;
		
		cout << "Enter choice: ";
		cin >> sectionOp;
		
		switch(sectionOp){
			case 1: 
				adminSection();
				break;
			case 2: 
				userSection();
				break;
			case 3: 
				cout << "\nExiting program. Goodbye!" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;		
		}
							
	} while(sectionOp !=3);
	
	return 0;
}

void adminSection(){
	int achoice;
	string pin;
	
	cout << "\nYou are in the Admin Section\n";
	cout << "\nEnter Admin PIN: ";
	cin >> pin;
	
	//not going to use the inherited logins anymore 
	if(pin == "admin2024"){
		cout << "\nWelcome Admin!" << endl;
		
		do{
			cout << "Select section: " << endl;
			cout << "1. Manage Association" << endl; //group each method by common name, so if it has anything to do with associations, include it here etc etc
			cout << "2. Manage Club" << endl;
			cout << "3. Manage Coach" << endl;
			cout << "4. Manage Athlete" << endl;
			cout << "5. Manage Sponsor" << endl;
			cout << "6. Exit\n" << endl;
			
			cout << "Enter choice: ";
			cin >> achoice;
			
			switch(achoice){
				case 1:
					manageAssociation();
					break;
				case 2:
					manageClub();
					break;
				case 3:
					manageCoach();
					break;
				case 4:
					manageAthlete();
					break;
				case 5:
					manageSponsor();
					break; //switch statement inside the adminSection() function, you’re missing break; statements for cases 3, 4, and 5. This means that if the Administrator chooses to manage the Coach (option 3), the program will also execute the code for managing the Athlete and Sponsor (options 4 and 5) due to fallthrough
				case 6: 
					cout << "\nExiting Admin Section. Goodbye." << endl;
				/*default:
					cout << "Invalid choice. Please try again." << endl;
					break;*/ //maybe keep this out for now	
			}
				
		} while(achoice != 6);
	} 
	else {
		std::cout << "Incorrect PIN. Access Denied.\n";
		//mainSectionMenu(); //don't think we have to call this, it shows up on its own
	}	
}

void manageAssociation(){
	int machoice;
	/*we’re creating Association, Club, Coach, Athlete, and Sponsor objects and passing them to the Admin constructor. This ensures that the Admin object has valid pointers to these objects.
	Remember to always delete any objects you create with new to avoid memory leaks. This should be done when you’re done using the objects. In this example, we’re deleting the objects after using the Admin object.*/
	
	// Create the objects
	Association* association = new Association();
	Club* club = new Club();
	Coach* coach = new Coach();
	Athlete* athlete = new Athlete();
	Sponsor* sponsor = new Sponsor();
	
	// Create the Admin object and pass the objects as parameters
	Admin* admin = new Admin(association, club, coach, athlete, sponsor);
        
        do {
        	cout << "Select section: " << endl;
        	cout << "1. Add or Edit Association account" << endl;
        	cout << "2. View Association account" << endl;
        	cout << "3. Delete Association" << endl;
        	cout << "4. Add or Remove Club from Association" << endl;
        	cout << "5. Report on all Associations" << endl;
        	cout << "6. Report on Clubs in an Association" << endl;
        	cout << "7. Report on Clubs not in an Association" << endl;
        	cout << "8. Search Association" << endl;
        	cout << "9. Exit\n" << endl;
        	
        	cout << "Enter choice: ";
			cin >> machoice;
			
			switch(machoice){
				case 1:
					admin->AddOrEditAssociation();
					break;
				case 2:
					admin->ViewAssociation();
					break;
				case 3:
					admin->DeleteAssociation();
					break;
				case 4:
					admin->AddOrRemoveClubFromAsso();
					break;
				case 5:
					admin->AllAssociationsReport();
					break;
				case 6:
					admin->ClubsInAnAssociationReport();
					break;
				case 7:
					admin->ClubsNotInAnAssociationReport();
					break;
				case 8:
					admin->SearchAssociation();
					break;
				case 9:
					cout << "\nExiting association management section. Goodbye." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
					break; //maybe keep this out for now	
			}
        	
		} while(machoice !=9);
		
	delete admin;
	delete association;
	delete club;
	delete coach;
	delete athlete;
	delete sponsor;
		//you’re not deleting these objects after using them, which can lead to memory leaks. In C++, when you create an object using new, you should always delete it using delete when you’re done with it. If you don’t, the memory allocated for the object will not be freed until the program ends, which can cause your program to use more memory than it needs to.
					
}

void manageClub(){
	int mcchoice;
	
	// Create the objects
	Association* association = new Association();
	Club* club = new Club();
	Coach* coach = new Coach();
	Athlete* athlete = new Athlete();
	Sponsor* sponsor = new Sponsor();
	
	// Create the Admin object and pass the objects as parameters
	Admin* admin = new Admin(association, club, coach, athlete, sponsor);
		
		do{
			cout << "Select section: " << endl;
			cout << "1. Add or Edit Club account" << endl;
			cout << "2. View Club account" << endl;
			cout << "3. Delete Club account" << endl;
			cout << "4. Add or Remove Athlete from Club" << endl;
			cout << "5. Add or Remove Coach from Club" << endl;
			cout << "6. Report on all Clubs" << endl;
			cout << "7. Report on Athletes in a Club" << endl;
			cout << "8. Report on Athletes not in a Club" << endl;
			cout << "9. Report on Coaches in a Club" << endl;
			cout << "10. Report on Coaches not in a Club" << endl;
			cout << "11. Search Club" << endl;
			cout << "12. Exit\n" << endl;
			
			cout << "Enter choice: ";
			cin >> mcchoice;
			
			switch(mcchoice){
				case 1:
					admin->AddOrEditClub();
					break;
				case 2:
					admin->ViewClub();
					break;
				case 3:
					admin->DeleteClub();
					break;
				case 4:
					admin->AddOrRemoveAthleteFromClub();
					break;
				case 5:
					admin->AddOrRemoveCoachFromClub();
					break;
				case 6:
					admin->AllClubsReport();
					break;
				case 7:
					admin->AthletesInAClubReport();
					break;
				case 8:
					admin->AthletesNotInAClubReport();
					break;
				case 9:
					admin->CoachesInAClubReport();
					break;
				case 10:
					admin->CoachesNotInAClubReport();
					break;
				case 11:
					admin->SearchClub();
					break;
				case 12:
					cout << "\nExiting club management section. Goodbye." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
					break; //maybe keep this out for now	
			}
			
 		} while(mcchoice !=12 );
 		
 	delete admin;
	delete association;
	delete club;
	delete coach;
	delete athlete;
	delete sponsor;
}

void manageCoach(){
	int mcochoice;
	
	// Create the objects
	Association* association = new Association();
	Club* club = new Club();
	Coach* coach = new Coach();
	Athlete* athlete = new Athlete();
	Sponsor* sponsor = new Sponsor();
	
	// Create the Admin object and pass the objects as parameters
	Admin* admin = new Admin(association, club, coach, athlete, sponsor);
	
		do{
			cout << "Select section: " << endl;
			cout << "1. Add or Edit Coach account" << endl;
			cout << "2. View Coach account" << endl;
			cout << "3. Delete account" << endl;
			cout << "4. Report on all Coaches" << endl;
			cout << "5. Search Coach";
			cout << "6. Exit\n" << endl;
			
			cout << "Enter choice: ";
			cin >> mcochoice;
			
			switch(mcochoice){
				case 1:
					admin->AddOrEditCoach();
					break;
				case 2:
					admin->ViewCoach();
					break;
				case 3:
					admin->DeleteCoach();
					break;
				case 4:
					admin->AllCoachesReport();
					break;
				case 5:
					admin->SearchCoach();
					break;
				case 6:
					cout << "\nExiting coach management section. Goodbye." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
					break; //maybe keep this out for now
			}
			
		} while(mcochoice !=4);
		
	delete admin;
	delete association;
	delete club;
	delete coach;
	delete athlete;
	delete sponsor;
}

void manageAthlete(){
	int matchoice;
	
	// Create the objects
	Association* association = new Association();
	Club* club = new Club();
	Coach* coach = new Coach();
	Athlete* athlete = new Athlete();
	Sponsor* sponsor = new Sponsor();
	
	// Create the Admin object and pass the objects as parameters
	Admin* admin = new Admin(association, club, coach, athlete, sponsor);
	
	do{
		cout << "Select section:" << endl;
		cout << "1. Add or Edit Athlete account" << endl;
		cout << "2. View account" << endl;
		cout << "3. Delete account" << endl;
		cout << "4. Add or Remove Sponsor from Athlete" << endl;
		cout << "5. Add or Delete Coach from account" << endl;
		cout << "6. Report on all Athletes" << endl;
		cout << "7. Report on Athletes with a Sponsor" << endl;
		cout << "8. Report on Athletes without a Sponsor" << endl;
		cout << "9. Report on Athles with a Coach" << endl;
		cout << "10. Report on Athletes without a Coach" << endl;
		cout << "11. Search Athlete" << endl;
		cout << "12. Exit\n" << endl;
		
		cout << "Enter choice: ";
		cin >> matchoice;
		
		switch(matchoice){
			case 1:
				admin->AddOrEditAthlete();
				break;
			case 2:
				admin->ViewAthlete();
				break;
			case 3:
				admin->DeleteAthlete();
				break;
			case 4:
				admin->AddOrDeleteSponsorFromAthlete();
				break;
			case 5:
				admin->AddOrDeleteCoachFromAthlete();
				break;
			case 6:
				admin->AllAthletesReport();
				break;
			case 7:
				admin->AthletesWithASponsorReport();
				break;
			case 8:
				admin->AthletesWithoutASponsorReport();
				break;
			case 9:
				admin->AthletesWithACoachReport();
				break;
			case 10:
				admin->AthletesWthoutACoachReport();
				break;
			case 11:
				admin->SearchAthlete();
				break;
			case 12:
				cout << "\nExiting athlete management section. Goodbye." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break; //maybe keep this out for now
		}
				
	} while(matchoice != 12);
	
	delete admin;
	delete association;
	delete club;
	delete coach;
	delete athlete;
	delete sponsor;
}

void manageSponsor(){
	int mschoice;
	
	// Create the objects
	Association* association = new Association();
	Club* club = new Club();
	Coach* coach = new Coach();
	Athlete* athlete = new Athlete();
	Sponsor* sponsor = new Sponsor();
	
	// Create the Admin object and pass the objects as parameters
	Admin* admin = new Admin(association, club, coach, athlete, sponsor);
	
		do{
			cout << "Select section:" << endl;
			cout << "1. Add or Edit Sponsor account" << endl;
			cout << "2. View Sponsor account" << endl;
			cout << "3. Delete Sponsor account" << endl;
			cout << "4. Report on all Sponsors" << endl;
			cout << "5. Search Sponsor" << endl;
			cout << "6. Exit\n" << endl;
			
			cout << "Enter choice: ";
			cin >> mschoice;
			
			switch(mschoice){
				case 1: 
					admin->AddOrEditSponsor();
					break;
				case 2: 
					admin->ViewSponsor();
					break;
				case 3: 
					admin->DeleteSponsor();
					break;
				case 4: 
					admin->AllSponsorsReport();
					break;
				case 5: 
					admin->SearchSponsor();
					break;
				case 6:
					cout << "\nExiting sponsor management section. Goodbye." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
					break; //maybe keep this out for now
			}
			
		}while(mschoice !=6);
		
	delete admin;
	delete association;
	delete club;
	delete coach;
	delete athlete;
	delete sponsor;
}

void userSection(){
	int uchoice;
	
	cout << "\nYou are in the User Section\n";
	
	do{
		cout << "Select section: " << endl;
		cout << "1. Association" << endl;
		cout << "2. Club" << endl;
		cout << "3. Coach" << endl;
		cout << "4. Athlete" << endl;
		cout << "5. Sponsor" <<endl;
		cout << "6. Exit\n" << endl;
		
		cout << "Enter choice: ";
		cin >> uchoice;
		
		switch(uchoice){
			case 1:
				association();
				break;
			case 2:
				club();
				break;
			case 3:
				coach();
				break;
			case 4:
				athlete();
				break;
			case 5:
				sponsor();
				break;
			case 6:
				cout << "Exiting user menu. Goodbye." << endl;
				break;
			default: 
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
		
	}while(uchoice != 6);
}

void association(){
	int achoice;
	string username, password;
	Association *aObj = new Association; // Create the Association object once
	
	/*the placement of (*) for the pointer doesn't really matter, its more about readability*/

	
	cout << "\nYou are in the Association Section\n";
	
	std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "\nEnter password: ";
    std::cin >> password;
    
    // Check if username is blank or password is incorrect
    if (!username.empty() || password == "assoPass2024") {
        std::cout << "\nWelcome, Association!\n";
        
        do{
        	cout << "Select section: " << endl;
        	cout << "1. Create association account" << endl;
        	cout << "2. Edit association account" << endl;
        	cout << "3. Search for association account" << endl;
        	cout << "4. Delete association accounr" << endl;
        	cout << "5. View association account" << endl;
        	cout << "6. View all associations" << endl;
        	cout << "7. Add Club" << endl;
        	cout << "8. Remove club" << endl;
        	cout << "9. See clubs in an association" << endl;
        	cout << "10. See clubs without association" << endl;
        	cout << "11. Exit\n" << endl;
        	
        	cout << "Enter choice: ";
			cin >> achoice;
			
			switch(achoice){
				case 1:
					aObj->CreateAccount(); 
					break;
				case 2:
					aObj->EditAccount();
					break;
				case 3:
					aObj->Search();
					break;
				case 4:
					aObj->DeleteAccount();
					break;
				case 5:
					aObj->Show();
					break;
				case 6:
					aObj->ShowAll();
					break;
				case 7:
					aObj->AddClub();
					break;
				case 8:
					aObj->RemoveClub();
					break;
				case 9:
					aObj->GetClubsWithAssociation();
					break;
				case 10:
					aObj->GetClubsWithoutAssociation();
					break;
				case 11:
					cout << "Exiting association user section. Goodbye." << endl;
					break;
				default: 
					cout << "Invalid choice. Please try again." << endl;
					break;
			}
        	
		}while(achoice !=11);
        
        } else {
        std::cout << "\nAccess Denied. Invalid username or password.\n";
    }
    delete aObj; // Delete the Association object when you're done with it
}

void club(){
	int clchoice;
	string username, password;
	Club* clObj = new Club;
	
	cout << "\nYou are in the Club Section\n";
	
	std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "\nEnter password: ";
    std::cin >> password;
    
    // Check if username is blank or password is incorrect
    if (!username.empty() || password == "clubPass2024" || password == "sportsForLife2024") {
        std::cout << "\nWelcome, Club!\n";
        
        do{
        	cout << "Select section:" << endl;
        	cout << "1. Create club account" << endl;
        	cout << "2. Edit club account" << endl;
        	cout << "3. Search for club account" << endl;
        	cout << "4. Delete club accounr" << endl;
        	cout << "5. View club account" << endl;
        	cout << "6. View all clubs" << endl;
        	cout << "7. Add Athlete" << endl;
        	cout << "8. Remove Athlete" << endl;
        	cout << "9. See athletes in a club" << endl;
        	cout << "10. See athletes not in a club" << endl;
        	cout << "11. Add Coach" << endl;
        	cout << "12. Remove Coach" << endl;
        	cout << "13. See coaches in a club" << endl;
        	cout << "14. See coaches not in a club" << endl;
        	cout << "15. Exit\n" << endl;
        	
        	cout << "Enter choice: ";
			cin >> clchoice;
			
			switch(clchoice){
				case 1:
					clObj->CreateAccount();
					break;
				case 2:
					clObj->EditAccount();
					break;
				case 3:
					clObj->Search();
					break;
				case 4:
					clObj->DeleteAccount();
					break;
				case 5:
					clObj->Show();
					break;
				case 6:
					clObj->ShowAll();
					break;
				case 7:
					clObj->AddAthlete();
					break;
				case 8:
					clObj->RemoveAthlete();
					break;
				case 9:
					clObj->GetAthletesWithClub();
					break;
				case 10:
					clObj->GetAthletesWithoutClub();
					break;
				case 11:
					clObj->AddCoach();
					break;
				case 12:
					clObj = new Club;
					clObj->RemoveCoach();
					break;
				case 13:
					clObj->GetCoachesWithClub();
					break;
				case 14:
					clObj->GetCoachesWithoutClub();
					break;
				case 15:
					cout << "Exiting club user section. Goodbye." << endl;
					break;
				default: 
					cout << "Invalid choice. Please try again." << endl;
					break;
			}
        	
		}while(clchoice != 15);
        
	} else {
        std::cout << "\nAccess Denied. Invalid username or password.\n";
    }
    
    delete clObj;
}

void coach(){
	int cochoice;
	string username, password;
	Coach *coObj = new Coach;
	
	cout << "\nYou are in the Coach Section\n";
	
	std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "\nEnter password: ";
    std::cin >> password;
    
    // Check if username is blank or password is incorrect
    if (!username.empty() || password == "coachPass2024") {
        std::cout << "\nWelcome, Coach!\n";
        
        do{
        	cout << "Select section:" << endl;
        	cout << "1. Create coach account" << endl;
        	cout << "2. Edit coach account" << endl;
        	cout << "3. Search for coach account" << endl;
        	cout << "4. Delete coach accounr" << endl;
        	cout << "5. View coach account" << endl;
        	cout << "6. View all coaches" << endl;
        	cout << "7. Switch club" << endl;
        	cout << "8. Exit\n" << endl;
        	
        	cout << "Enter choice: ";
			cin >> cochoice;
			
			switch(cochoice){
				case 1:
					coObj->CreateAccount();
					break;
				case 2:
					coObj->EditAccount();
					break;
				case 3:
					coObj->Search();
					break;
				case 4:
					coObj->DeleteAccount();
					break;
				case 5:
					coObj->Show();
					break;
				case 6:
					coObj->ShowAll();
					break;
				case 7:
					coObj->SwitchClub();
					break;
				case 8:
					cout << "Exiting coach user section. Goodbye." << endl;
					break;
				default: 
					cout << "Invalid choice. Please try again." << endl;
					break;
			}
        	
		}while(cochoice != 8);
        
	} else {
        std::cout << "\nAccess Denied. Invalid username or password.\n";
    }
    delete coObj;
}

void athlete(){
	int atchoice;
	string username, password;
	Athlete* atObj = new Athlete;
	
	cout << "\nYou are in the Athlete Section\n";
	
	std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "\nEnter password: ";
    std::cin >> password;
    
    // Check if username is blank or password is incorrect
    if (!username.empty() || password == "athlPass2024") {
        std::cout << "\nWelcome, Athlete!\n";
        
        do{
        	cout << "Select section:" << endl;
        	cout << "1. Create athlete account" << endl;
        	cout << "2. Edit athlete account" << endl;
        	cout << "3. Search for athlete account" << endl;
        	cout << "4. Delete athlete accounr" << endl;
        	cout << "5. View athlete account" << endl;
        	cout << "6. View all athletes" << endl;
        	cout << "7. Add sponsor" << endl;
        	cout << "8. Remove sponsor" << endl;
        	cout << "9. See all athletes with a sponsor" << endl;
        	cout << "10. See all athletes without a sponsor" << endl;
        	cout << "11. Add coach" << endl;
        	cout << "12. Remove coach" << endl;
        	cout << "13. See all athletes with a coach" << endl;
        	cout << "14. See all athletes without a coach" << endl;
        	cout << "15. Switch club" << endl;
        	cout << "16. Exit\n" << endl;
        	
        	cout << "Enter choice: ";
			cin >> atchoice;
			
			switch(atchoice){
				case 1:
					atObj->CreateAccount();
					break;
				case 2:
					atObj->EditAccount();
					break;
				case 3:
					atObj->Search();
					break;
				case 4:
					atObj->DeleteAccount();
					break;
				case 5:
					atObj->Show();
					break;
				case 6:
					atObj->ShowAll();
					break;
				case 7:
					atObj->AddSponsor();
					break;
				case 8:
					atObj->RemoveSponsor();
					break;
				case 9:
					atObj->GetSponsorsWithAthlete();
					break;
				case 10:
					atObj->GetSponsorsWithoutAthlete();
					break;
				case 11:
					atObj->AddCoach();
					break;
				case 12:
					atObj->RemoveCoach();
					break;
				case 13:
					atObj->GetCoachesWithAthlete();
					break;
				case 14:
					atObj->GetCoachesWithoutAthlete();
					break;
				case 15:
					atObj->SwitchClub();
					break;
				case 16:
					cout << "Exiting athlete user section. Goodbye." << endl;
					break;
				default: 
					cout << "Invalid choice. Please try again." << endl;
					break;
			}
        	
		}while(atchoice != 16);
        
	} else {
        std::cout << "\nAccess Denied. Invalid username or password.\n";
    }
    delete atObj;
}

void sponsor(){
	int schoice;
	string username, password;
	Sponsor *sObj = new Sponsor;
	
	cout << "\nYou are in the Sponsor Section\n";
	
	std::cout << "\nEnter username: ";
    std::cin >> username;

    std::cout << "\nEnter password: ";
    std::cin >> password;
    
    // Check if username is blank or password is incorrect
    if (!username.empty() || password == "sponPass2024") {
        std::cout << "\nWelcome, Sponsor!\n";
        
        do{
        	cout << "Select section:" << endl;
        	cout << "1. Create sponsor account" << endl;
        	cout << "2. Edit sponsor account" << endl;
        	cout << "3. Search for sponsor account" << endl;
        	cout << "4. Delete sponsor accounr" << endl;
        	cout << "5. View sponsor account" << endl;
        	cout << "6. View all sponsors" << endl;
        	cout << "7. Switch athlete being sponsored" << endl;
        	cout << "8. Exit\n" << endl;
        	
        	cout << "Enter choice: ";
			cin >> schoice;
			
			switch(schoice){
				case 1:
					sObj->CreateAccount();
					break;
				case 2:
					sObj->EditAccount();
					break;
				case 3:
					sObj->Search();
					break;
				case 4:
					sObj->DeleteAccount();
					break;
				case 5:
					sObj->Show();
					break;
				case 6:
					sObj->ShowAll();
					break;
				case 7:
					sObj->SwitchAthlete();
					break;
				case 8:
					cout << "Exiting sponsor user section. Goodbye." << endl;
					break;
				default: 
					cout << "Invalid choice. Please try again." << endl;
					break;
			}
        	
		}while(schoice != 8);
        
	} else {
        std::cout << "\nAccess Denied. Invalid username or password.\n";
    }
    delete sObj;
}

/*
// Function to display the main menu
void mainSectionMenu() {
    std::cout << "\n======= Welcome to the Ministry of Entertainment and Sports (MES) Sports Management System =======\n";
    cout << "MAIN MENU - Select section: " << endl;
	cout << "1. Administrator" << endl;
	cout << "2. User" << endl;
	cout << "3. Exit\n" << endl;
}*/

