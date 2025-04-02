//club implementation
//Paris Scott

#include "User.h"
#include "Club.h"
#include "Athlete.h"
#include "Association.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//remember to update association to include club composition

Club::Club()
{
	clubCode = 0;
	clubName = "";
	clubColor = "";
	clubPresi = "";
	clubHeadCoach = "";
	clubMemAmnt = 0.0f;
	clubAssoFee = 0.0f;
	annualFeeToCoach = 0.0f;
	
	// Add this club to the list of all clubs
    allClubs.push_back(this);
}

Club::Club(int ccd, string cn, string ccol, string cp, string chc, float cma, float caf, float af)
{
	clubCode = ccd;
	clubName = cn;
	clubColor = ccol;
	clubPresi = cp;
	clubHeadCoach = chc;
	clubMemAmnt = cma;
	clubAssoFee = caf;
	annualFeeToCoach = af;
	
	// Add this club to the list of all clubs
    allClubs.push_back(this);
}

//mutators
void Club::SetAssociation(Association* as){
	assoc = as;
}

void Club::SetClubCode(int ccd)
{
	clubCode = ccd;
}

void Club::SetClubName(string cn)
{
	clubName = cn;
}

void Club::SetClubColor(string ccol)
{
	clubColor = ccol;
}

void Club::SetClubPresi(string cp)
{
	clubPresi = cp;
}

void Club::SetClubHeadCoach(string chc)
{
	clubHeadCoach = chc;
}

void Club::SetClubMemAmnt(float cma)
{
	clubMemAmnt = cma;
}

void Club::SetClubAssoFee(float caf)
{
	clubAssoFee = caf;
}

void Club::SetAnnualFeeToCoach(float af)
{
	annualFeeToCoach = af;
}

//accessors
Association* Club::GetAssociation()
{
	return assoc;
}

int Club::GetClubCode()
{
	return clubCode;
}

string Club::GetClubName()
{
	return clubName;
}

string Club::GetClubColor()
{
	return clubColor;
}

string Club::GetClubPresi()
{
	return clubPresi;
}

string Club::GetClubHeadCoach()
{
	return clubHeadCoach;
}

float Club::GetClubMemAmnt()
{
	return clubMemAmnt;
}

float Club::GetClubAssoFee()
{
	return clubAssoFee;
}

float Club::GetAnnualFeeToCoach()
{
	return annualFeeToCoach;
}

//methods to manipulate and set endorsement variable to sponsor amount value
void Club::SetEndorsAmnt(Sponsor &spon)
{
	endorsAmnt = spon.GetSponAmnt();
}

float Club::GetEndorsAmnt()
{
	return endorsAmnt;
}

//calculate/ pay methods to set association fee and annual fee
void Club::PayClubAssoFee()
{
	clubAssoFee = endorsAmnt * 0.1;
}

void Club::PayAnnualFeeToCoach()
{
	annualFeeToCoach = endorsAmnt * 0.01;
}

//implement other methods after

//create account
void Club::CreateAccount()
{
	try {
		int count; //counter used in for loop
        int c; //to hold exactly _ records

        //variables to collect info 
        int cc;
        string cn, col, cp, hc;
        float mem, asf, anfc; 

        //creating & writing to AssoSeqFile object of the ofstream class
        ofstream ClubSeqFile("Club.sq1", ios::out);
        
        if(!ClubSeqFile) {
            throw runtime_error("Failed to open file Club.sq1");
        }

        //Enter the total number of records
        cout << "\nEnter number of club accounts to be made: ";
        cin >> c;

        //enter data
        for(count = 0; count < c; ++count)
        {
            cout <<endl;

            cout << "\nEnter the club code: ";
            cin >> cc;

            cout << "\nEnter club name (separate each word with - or _ ): ";
            cin >> cn;

            cout << "\nEnter club color (separate each word with - or _ ): ";
            cin >> col;
            
            cout << "\nEnter club president (separate each word with - or _ ): ";
            cin >> cp;
            
            cout << "\nEnter club head coach (separate each word with - or _ ): ";
            cin >> hc;
            
            cout << "\nEnter club membership amount (0.0): ";
            cin >> mem;
            
            asf = 0; //will be calculated - asso fee
            
            anfc = 0; //will be calculated - annual fee

            //write collected data into clubObj object of the club class
            Club clubObj(cc, cn, col, cp, hc, mem, asf, anfc);

            //store collected data into AssoSeqFile object
            ClubSeqFile << clubObj.GetClubCode() << endl; 
            ClubSeqFile << clubObj.GetClubName() << endl; 
            ClubSeqFile << clubObj.GetClubColor() << endl; 
            ClubSeqFile << clubObj.GetClubPresi() << endl; 
            ClubSeqFile << clubObj.GetClubHeadCoach() << endl; 
            ClubSeqFile << clubObj.GetClubMemAmnt() << endl;
			ClubSeqFile << clubObj.GetClubAssoFee() << endl;  
			ClubSeqFile << clubObj.GetAnnualFeeToCoach() << endl; 
            ClubSeqFile << "------------------------------\n" << endl;
        }
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
	}
}

//edit account
void Club::EditAccount()
{
    try {
        int cc; //club code to be edited

        //variables to collect info 
        string cn, col, cp, hc;
        float mem, asf, anfc; 

        //creating & reading from ClubSeqFile object of the ifstream class
        ifstream ClubSeqFile("Club.sq1", ios::in);

        if(!ClubSeqFile) {
            throw runtime_error("Failed to open file Club.sq1");
        }

        //creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        if(!TempSeqFile) {
            throw runtime_error("Failed to open file Temp.sq1");
        }

        cout << "\nEnter the club code to edit: ";
        cin >> cc;

        //read data from clubs
        while(ClubSeqFile >> clubCode >> clubName >> clubColor >> clubPresi >> clubHeadCoach >> clubMemAmnt >> clubAssoFee >> annualFeeToCoach)
        {
            if(clubCode == cc)
            {
                cout << "\nEnter club name (separate each word with - or _ ): ";
                cin >> cn;

                cout << "\nEnter club color (separate each word with - or _ ): ";
                cin >> col;
                
                cout << "\nEnter club president (separate each word with - or _ ): ";
                cin >> cp;
                
                cout << "\nEnter club head coach (separate each word with - or _ ): ";
                cin >> hc;
                
                cout << "\nEnter club membership amount (0.0): ";
                cin >> mem;
                
                asf = 0; //will be calculated - asso fee
                
                anfc = 0; //will be calculated - annual fee

                //write collected data into clubObj object of the club class
                Club clubObj(cc, cn, col, cp, hc, mem, asf, anfc);

                //store collected data into TempSeqFile object
                TempSeqFile << clubObj.GetClubCode() << endl; 
                TempSeqFile << clubObj.GetClubName() << endl; 
                TempSeqFile << clubObj.GetClubColor() << endl; 
                TempSeqFile << clubObj.GetClubPresi() << endl; 
                TempSeqFile << clubObj.GetClubHeadCoach() << endl; 
                TempSeqFile << clubObj.GetClubMemAmnt() << endl;
                TempSeqFile << clubObj.GetClubAssoFee() << endl;  
                TempSeqFile << clubObj.GetAnnualFeeToCoach() << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
            else
            {
                //write unedited data into TempSeqFile object
                TempSeqFile << clubCode << endl; 
                TempSeqFile << clubName << endl; 
                TempSeqFile << clubColor << endl; 
                TempSeqFile << clubPresi << endl; 
                TempSeqFile << clubHeadCoach << endl; 
                TempSeqFile << clubMemAmnt << endl;
                TempSeqFile << clubAssoFee << endl;  
                TempSeqFile << annualFeeToCoach << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        ClubSeqFile.close();
        TempSeqFile.close();

        //delete the original file
        remove("Club.sq1");

        //rename the temporary file to original file name
        rename("Temp.sq1", "Club.sq1");

        cout << "\nClub account edited successfully.\n";
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//search
void Club::Search() {
    try {
        // Prompt the user for the club code
        int code;
        cout << "Enter the code of the club you want to search for: ";
        cin >> code;

        //creating & reading from ClubSeqFile object of the ifstream class
        ifstream ClubSeqFile("Club.sq1", ios::in);

        if(!ClubSeqFile) {
            throw runtime_error("Failed to open file Club.sq1");
        }

        bool found = false;
        //read data from clubs
        while(ClubSeqFile >> clubCode >> clubName >> clubColor >> clubPresi >> clubHeadCoach >> clubMemAmnt >> clubAssoFee >> annualFeeToCoach)
        {
            if (clubCode == code) {
                found = true;
                cout << "\nClub Code: " << clubCode << endl;
                cout << "Club Name: " << clubName << endl;
                cout << "Club Color: " << clubColor << endl;
                cout << "Club President: " << clubPresi << endl;
                cout << "Club Head Coach: " << clubHeadCoach << endl;
                cout << "Club Membership Amount: " << clubMemAmnt << endl;
                cout << "Club Association Fee: " << clubAssoFee << endl;
                cout << "Annual Fee To Coach: " << annualFeeToCoach << endl;
                cout << "------------------------------\n" << endl;
                break;
            }
        }

        if (!found) {
            cout << "No record found with code " << code << endl;
        }

        ClubSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}


//delete account
void Club::DeleteAccount()
{
    try {
        int cc; //club code to be deleted

        //creating & reading from ClubSeqFile object of the ifstream class
        ifstream ClubSeqFile("Club.sq1", ios::in);

        if(!ClubSeqFile) {
            throw runtime_error("Failed to open file Club.sq1");
        }

        //creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        if(!TempSeqFile) {
            throw runtime_error("Failed to open file Temp.sq1");
        }

        cout << "\nEnter the club code to delete: ";
        cin >> cc;

        //read data from clubs
        while(ClubSeqFile >> clubCode >> clubName >> clubColor >> clubPresi >> clubHeadCoach >> clubMemAmnt >> clubAssoFee >> annualFeeToCoach)
        {
            if(clubCode != cc)
            {
                //write unedited data into TempSeqFile object
                TempSeqFile << clubCode << endl; 
                TempSeqFile << clubName << endl; 
                TempSeqFile << clubColor << endl; 
                TempSeqFile << clubPresi << endl; 
                TempSeqFile << clubHeadCoach << endl; 
                TempSeqFile << clubMemAmnt << endl;
                TempSeqFile << clubAssoFee << endl;  
                TempSeqFile << annualFeeToCoach << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        ClubSeqFile.close();
        TempSeqFile.close();

        //delete the original file
        remove("Club.sq1");

        //rename the temporary file to original file name
        rename("Temp.sq1", "Club.sq1");

        cout << "\nClub account deleted successfully.\n";
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//display 
void Club::Show()
{
    try {
        //creating & reading from ClubSeqFile object of the ifstream class
        ifstream ClubSeqFile("Club.sq1", ios::in);

        if(!ClubSeqFile) {
            throw runtime_error("Failed to open file Club.sq1");
        }

        cout << "\nClub Information:\n";

        //read data from clubs
        while(ClubSeqFile >> clubCode >> clubName >> clubColor >> clubPresi >> clubHeadCoach >> clubMemAmnt >> clubAssoFee >> annualFeeToCoach)
        {
            cout << "\nClub Code: " << clubCode << endl;
            cout << "Club Name: " << clubName << endl;
            cout << "Club Color: " << clubColor << endl;
            cout << "Club President: " << clubPresi << endl;
            cout << "Club Head Coach: " << clubHeadCoach << endl;
            cout << "Club Membership Amount: " << clubMemAmnt << endl;
            cout << "Club Association Fee: " << clubAssoFee << endl;
            cout << "Annual Fee To Coach: " << annualFeeToCoach << endl;
            cout << "------------------------------\n" << endl;
        }

        ClubSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

void Club::ShowAll()
{
    try {
        //creating & reading from ClubSeqFile object of the ifstream class
        ifstream ClubSeqFile("Club.sq1", ios::in);

        if(!ClubSeqFile) {
            throw runtime_error("Failed to open file Club.sq1");
        }

        cout << "\n------------------ All Clubs Report ------------------\n";

        //read data from clubs
        while(ClubSeqFile >> clubCode >> clubName >> clubColor >> clubPresi >> clubHeadCoach >> clubMemAmnt >> clubAssoFee >> annualFeeToCoach)
        {
            cout << "\nClub Code: " << clubCode << endl;
            cout << "Club Name: " << clubName << endl;
            cout << "Club Color: " << clubColor << endl;
            cout << "Club President: " << clubPresi << endl;
            cout << "Club Head Coach: " << clubHeadCoach << endl;
            cout << "Club Membership Amount: " << clubMemAmnt << endl;
            cout << "Club Association Fee: " << clubAssoFee << endl;
            cout << "Annual Fee To Coach: " << annualFeeToCoach << endl;
            cout << "------------------------------------------------------------\n" << endl;
        }

        ClubSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}


//add athlete to club
void Club::AddAthlete() {
    string atrn;
    // Ask for the athlete TRN
    std::cout << "Enter the TRN of the athlete to add: ";
    std::cin >> atrn;

    // Find the athlete based on the TRN
    Athlete* a = findAthleteByTRN(atrn); 

    if(a != NULL) {
        // Add the athlete to the list
        athletes.push_back(a); //add athlete to the club's list
        a->SetClub(this); //set athlete's club to this one
    } else {
        std::cout << "\nAthlete not found. Cannot perform operation.\n";
    }
    
    // Add the athlete to allAthletes if it's not already there
    if (std::find(allAthletes.begin(), allAthletes.end(), a) == allAthletes.end()) {
        allAthletes.push_back(a);
    }
} // This closing brace was missing


//remove athlete from club
void Club::RemoveAthlete() {
    string atrn;
    // Ask for the athlete TRN
    std::cout << "\nEnter the TRN of the athlete to remove: ";
    std::cin >> atrn;

    // Find the athlete based on the TRN
    Athlete* a = findAthleteByTRN(atrn); 

    if(a != NULL) {
        // Find the athlete in the list and remove them
        for (auto vector<Athlete*>::iterator it = athletes.begin(); it != athletes.end(); ++it) {
            if (*it == a) {
                // Remove the athlete from the list
                athletes.erase(it);
                break;
            }
        }
        // Set the athlete's club to nullptr
        a->SetClub(NULL);
    } else {
        std::cout << "\nAthlete not found. Cannot perform operation.\n";
    }
}

// Method to return all athletes that have a club
std::vector<Athlete*> Club::GetAthletesWithClub() {
    std::vector<Athlete*> athletesWithClub;
    for (std::vector<Athlete*>::iterator it = allAthletes.begin(); it != allAthletes.end(); ++it) {
        Athlete* athlete = *it;
        if (athlete->GetClub() != NULL) {
            athletesWithClub.push_back(athlete);
        }
    }
    return athletesWithClub;
}

// Method to return all athletes that don't have a club
std::vector<Athlete*> Club::GetAthletesWithoutClub() {
    std::vector<Athlete*> athletesWithoutClub;
    for (std::vector<Athlete*>::iterator it = allAthletes.begin(); it != allAthletes.end(); ++it) {
        Athlete* athlete = *it;
        if (athlete->GetClub() == NULL) {
            athletesWithoutClub.push_back(athlete);
        }
    }
    return athletesWithoutClub;
}


//add coach to club
void Club::AddCoach() {
    string ctrn;
    // Ask for the coach TRN
    std::cout << "\nEnter the TRN of the coach to add: ";
    std::cin >> ctrn;

    // Find the coach based on the TRN
    Coach* c = findCoachByTRN(ctrn); 

    if(c != NULL) {
        // Add the coach to the list
        coaches.push_back(c); //add coach to the club's list
        c->SetClub(this); //set coach's club to this one
    } else {
        std::cout << "\nCoach not found. Cannot perform operation.\n";
    }
    
    if (std::find(allCoaches.begin(), allCoaches.end(), c) == allCoaches.end()) {
        allCoaches.push_back(c);
	}
}

//remove coach from club
void Club::RemoveCoach() {
    string ctrn;
    // Ask for the coach TRN
    std::cout << "\nEnter the TRN of the coach to remove: ";
    std::cin >> ctrn;

    // Find the coach based on the TRN
    Coach* c = findCoachByTRN(ctrn); 

    if(c != NULL) {
        // Find the coach in the list and remove them
        for (auto vector<Coach*>::iterator it = coaches.begin(); it != coaches.end(); ++it) {
            if (*it == c) {
                // Remove the coach from the list
                coaches.erase(it);
                break;
            }
        }
        // Set the coach's club to nullptr
        c->SetClub(NULL);
    } else {
        std::cout << "\nCoach not found. Cannot perform operation.\n";
    }
}

// Method to return all coaches that have a club
std::vector<Coach*> Club::GetCoachesWithClub() {
    std::vector<Coach*> coachesWithClub;
    for (std::vector<Coach*>::iterator it = allCoaches.begin(); it != allCoaches.end(); ++it) {
        Coach* coach = *it;
        if (coach->GetClub() != NULL) {
            coachesWithClub.push_back(coach);
        }
    }
    return coachesWithClub;
}

// Method to return all coaches that don't have a club
std::vector<Coach*> Club::GetCoachesWithoutClub() {
    std::vector<Coach*> coachesWithoutClub;
    for (std::vector<Coach*>::iterator it = allCoaches.begin(); it != allCoaches.end(); ++it) {
        Coach* coach = *it;
        if (coach->GetClub() == NULL) {
            coachesWithoutClub.push_back(coach);
        }
    }
    return coachesWithoutClub;
}


Athlete* Club::findAthleteByTRN(string trn)
{
	//find athlete by TRN
    //creating & reading from AthlSeqFile object of the ifstream class
    ifstream AthlSeqFile("Athlete.sq1", ios::in);

    if(!AthlSeqFile) {
        throw runtime_error("Failed to open file Athlete.sq1");
    }

    Athlete* athlete = NULL;
    string atrn, afn, amn, aln, agen, adob, anat;
    float h, w, af;
    string agtrn, agfn, agmn, agln, agem, agp;

    //read data from athletes
    while (getline(AthlSeqFile, atrn)) {
        getline(AthlSeqFile, afn);
        getline(AthlSeqFile, amn);
        getline(AthlSeqFile, aln);
        getline(AthlSeqFile, agen);
        getline(AthlSeqFile, adob);
        getline(AthlSeqFile, anat);
        AthlSeqFile >> h;
        AthlSeqFile >> w;
        AthlSeqFile >> af;
        getline(AthlSeqFile, agtrn);
        getline(AthlSeqFile, agfn);
        getline(AthlSeqFile, agmn);
        getline(AthlSeqFile, agln);
        getline(AthlSeqFile, agem);
        getline(AthlSeqFile, agp);

        if (atrn == trn) {
            athlete = new Athlete(atrn, afn, amn, aln, agen, adob, anat, h, w, af, agtrn, agfn, agmn, agln, agem, agp);
            break;
        }
    }

    AthlSeqFile.close();
    return athlete; // Return NULL if no athlete found with the given TRN
}

//find coach by TRN
Coach* Club::findCoachByTRN(string trn) {
    //creating & reading from CoachSeqFile object of the ifstream class
    ifstream CoachSeqFile("Coach.sq1", ios::in);

    if(!CoachSeqFile) {
        throw runtime_error("Failed to open file Coach.sq1");
    }

    Coach* coach = NULL;
    string ctrn, cfn, cmn, cln, cdob, cgen, ced, csd;
    float comm;

    //read data from coaches
    while (getline(CoachSeqFile, ctrn)) {
        getline(CoachSeqFile, cfn);
        getline(CoachSeqFile, cmn);
        getline(CoachSeqFile, cln);
        getline(CoachSeqFile, cdob);
        getline(CoachSeqFile, cgen);
        getline(CoachSeqFile, ced);
        getline(CoachSeqFile, csd);
        CoachSeqFile >> comm;

        if (ctrn == trn) {
            coach = new Coach(ctrn, cfn, cmn, cln, cdob, cgen, ced, csd, comm);
            break;
        }
    }

    CoachSeqFile.close();
    return coach; // Return NULL if no coach found with the given TRN
}


//remove main after club is added to it
/*
int main(){
	return 0;
}
*/



