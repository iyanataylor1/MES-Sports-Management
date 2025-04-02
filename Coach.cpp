//coach implementation
//Kaylen Eastwood

#include "User.h"
#include "Athlete.h"
#include "Club.h"
#include "Coach.h"
#include "Association.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

//default con
Coach::Coach()
{
	coachTRN = "";
	coachFN = "";
	coachMN = "";
	coachLN = "";
	coachDOB = "";
	coachGen = "";
	coachEmpDate = "";
	coachSepDate = "";
	commission = 0.0f;
	
	allCoaches.push_back(this);
}

//primary con
Coach::Coach(string trn, string fn, string mn, string ln, string dob, string gen, string ed, string sd, float com)
{
	coachTRN = trn;
	coachFN = fn;
	coachMN = mn;
	coachLN = ln;
	coachDOB = dob;
	coachGen = gen;
	coachEmpDate = ed;
	coachSepDate = sd;
	commission = com;
	
	allCoaches.push_back(this);
}

//mutators
void Coach::SetAthlete(Athlete* at)
{
	athl = at;
}

void Coach::SetClub(Club* c)
{
	club = c;
}

void Coach::SetCoachTRN(string trn)
{
	coachTRN = trn;
}

void Coach::SetCoachFN(string fn)
{
	coachFN = fn;
}

void Coach::SetCoachMN(string mn)
{
	coachMN = mn;
}

void Coach::SetCoachLN(string ln)
{
	coachLN = ln;
}

void Coach::SetCoachDOB(string dob)
{
	coachDOB = dob;
}

void Coach::SetCoachGen(string gen)
{
	coachGen = gen;
}

void Coach::SetCoachEmpDate(string ed)
{
	coachEmpDate = ed;
}

void Coach::SetCoachSepDate(string sd)
{
	coachSepDate = sd;
}

void Coach::SetCommission(float com)
{
	commission = com;
}

//accessors
Club* Coach::GetClub() {
    return club; 
}

Athlete* Coach::GetAthlete() {
    return athl; 
}

string Coach::GetCoachTRN() {
    return coachTRN; 
}

string Coach::GetCoachFN() {
    return coachFN;  
}

string Coach::GetCoachMN() {
    return coachMN;  
}

string Coach::GetCoachLN() {
    return coachLN;  
}

string Coach::GetCoachDOB() {
    return coachDOB; 
}

string Coach::GetCoachGen() {
    return coachGen; 
}

string Coach::GetCoachEmpDate() {
    return coachEmpDate; 
}

string Coach::GetCoachSepDate() {
    return coachSepDate;  
}

float Coach::GetCommission() {
    return commission;  
}

//switch coach's club
void Coach::SwitchClub() {
    int clubCode;
    // Ask for the club code
    std::cout << "\nEnter the code of the club to switch to: ";
    std::cin >> clubCode;

    // Find the club based on the code
    Club* newClub = association->findClubByCode(clubCode); 

    if(newClub != NULL) {
        if (club != NULL) {
            // If the athlete is currently in a club, remove them from that club
            club->RemoveAthlete();
        }
        // Add the athlete to the new club
        newClub->AddAthlete();
    } else {
        std::cout << "\nClub not found. Cannot perform operation.\n";
    }
}
		
//account manipulation
//create account
void Coach::CreateAccount()
{
	try {
        int count; //counter used in for loop
        int coa; //to hold exactly _ records

        //variables to collect association info 
        string ctrn, cfn, cmn, cln, cdob, cgen, ced, csd;
        float comm; 

        //creating & writing to AssoSeqFile object of the ofstream class
        ofstream CoachSeqFile("Coach.sq1", ios::out);

        if(!CoachSeqFile) {
            throw runtime_error("Failed to open file Coach.sq1");
        }

        //Enter the total number of records
        cout << "\nEnter number of coach accounts to be made: ";
        cin >> coa;

        //enter data for associations
        for(count = 0; count < coa; ++count)
        {
            cout <<endl;

            cout << "\nEnter coach TRN (xxx-yyy-zzz): ";
            cin >> ctrn;

            cout << "\nEnter coach first name (separate each word with - or _ ): ";
            cin >> cfn;

            cout << "\nEnter coach middle name (separate each word with - or _ ): ";
            cin >> cmn;

            cout << "\nEnter coach last name (separate each word with - or _ ): ";
            cin >> cln;
            
            cout << "\nEnter coach DOB [dd/mm/yyyy]: ";
            cin >> cdob;
            
            cout << "\nEnter coach gender [m/M for Male or f/F for Female]: ";
            cin >> cgen;
            
            cout << "\nEnter coach employment date [dd/mm/yyyy]: ";
            cin >> ced;
            
            cout << "\nEnter coach separation date [dd/mm/yyyy]: ";
            cin >> csd;
            
            cout << "\nEnter coach commission amount (0.0): ";
            cin >> comm;

            //write collected data into assoObj object of the association class
            Coach coachObj(ctrn, cfn, cmn, cln, cdob, cgen, ced, csd, comm);

            //store collected data into AssoSeqFile object
            CoachSeqFile << coachObj.GetCoachTRN() << endl; 
            CoachSeqFile << coachObj.GetCoachFN() << endl; 
            CoachSeqFile << coachObj.GetCoachMN() << endl; 
            CoachSeqFile << coachObj.GetCoachLN() << endl; 
            CoachSeqFile << coachObj.GetCoachDOB() << endl; 
            CoachSeqFile << coachObj.GetCoachGen() << endl; 
            CoachSeqFile << coachObj.GetCoachEmpDate() << endl; 
            CoachSeqFile << coachObj.GetCoachSepDate()<< endl;
			CoachSeqFile << coachObj.GetCommission() << endl;  
            CoachSeqFile << "------------------------------\n" << endl;
        }
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//edit account
void Coach::EditAccount()
{
    try {
        string ctrn; // to hold coach TRN

        // creating & reading from CoachSeqFile object of the ifstream class
        ifstream CoachSeqFile("Coach.sq1", ios::in);

        if(!CoachSeqFile) {
            throw runtime_error("Failed to open file Coach.sq1");
        }

        // Enter the TRN of the coach account to be edited
        cout << "\nEnter the TRN of the coach account to be edited: ";
        cin >> ctrn;

        // variables to hold data read from file
        string fileCtrn, fileCfn, fileCmn, fileCln, fileCdob, fileCgen, fileCed, fileCsd;
        float fileComm;

        // creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        // read data from CoachSeqFile and write to TempSeqFile
        while (getline(CoachSeqFile, fileCtrn)) {
            getline(CoachSeqFile, fileCfn);
            getline(CoachSeqFile, fileCmn);
            getline(CoachSeqFile, fileCln);
            getline(CoachSeqFile, fileCdob);
            getline(CoachSeqFile, fileCgen);
            getline(CoachSeqFile, fileCed);
            getline(CoachSeqFile, fileCsd);
            CoachSeqFile >> fileComm;

            // if the TRN matches, prompt for new details
			if (fileCtrn == ctrn) {
				
				//variables to collect association info 
		        string ctrn, cfn, cmn, cln, cdob, cgen, ced, csd;
		        float comm; 
        
			    cout << "\nEnter new details for the coach account:\n";
			
			    // similar prompts as in CreateAccount method
			    cout << "\nEnter coach TRN (xxx-yyy-zzz): ";
			    cin >> ctrn;
			
			    cout << "\nEnter coach first name (separate each word with - or _ ): ";
			    cin >> cfn;
			
			    cout << "\nEnter coach middle name (separate each word with - or _ ): ";
			    cin >> cmn;
			
			    cout << "\nEnter coach last name (separate each word with - or _ ): ";
			    cin >> cln;
			    
			    cout << "\nEnter coach DOB [dd/mm/yyyy]: ";
			    cin >> cdob;
			    
			    cout << "\nEnter coach gender [m/M for Male or f/F for Female]: ";
			    cin >> cgen;
			    
			    cout << "\nEnter coach employment date [dd/mm/yyyy]: ";
			    cin >> ced;
			    
			    cout << "\nEnter coach separation date [dd/mm/yyyy]: ";
			    cin >> csd;
			
			    // write new details to TempSeqFile
			    TempSeqFile << ctrn << endl; 
			    TempSeqFile << cfn << endl; 
			    TempSeqFile << cmn << endl; 
			    TempSeqFile << cln << endl; 
			    TempSeqFile << cdob << endl; 
			    TempSeqFile << cgen << endl; 
			    TempSeqFile << ced << endl; 
			    TempSeqFile << csd << endl;
			    TempSeqFile << "------------------------------\n" << endl;
			} else {
			    // write old details to TempSeqFile
				TempSeqFile << fileCtrn << endl; 
				TempSeqFile << fileCfn << endl; 
				TempSeqFile << fileCmn << endl; 
				TempSeqFile << fileCln << endl; 
				TempSeqFile << fileCdob << endl; 
				TempSeqFile << fileCgen << endl; 
				TempSeqFile << fileCed << endl; 
				TempSeqFile << fileCsd << endl;
				TempSeqFile << "------------------------------\n" << endl;
			}

        }

        // close the files
        CoachSeqFile.close();
        TempSeqFile.close();

        // delete the original file and rename the temporary file
        remove("Coach.sq1");
        rename("Temp.sq1", "Coach.sq1");

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//search
void Coach::Search() {
    try {
        // Prompt the user for the coach TRN
        string trn;
        cout << "\nEnter the TRN of the coach you want to search for: ";
        cin >> trn;

        //creating & reading from CoachSeqFile object of the ifstream class
        ifstream CoachSeqFile("Coach.sq1", ios::in);

        if(!CoachSeqFile) {
            throw runtime_error("Failed to open file Coach.sq1");
        }

        bool found = false;
        //read data from coaches
        while(CoachSeqFile >> coachTRN >> coachFN >> coachMN >> coachLN >> coachDOB >> coachGen >> coachEmpDate >> coachSepDate >> commission)
        {
            if (coachTRN == trn) {
                found = true;
                cout << "\nCoach TRN: " << coachTRN << endl;
                cout << "Coach First Name: " << coachFN << endl;
                cout << "Coach Middle Name: " << coachMN << endl;
                cout << "Coach Last Name: " << coachLN << endl;
                cout << "Coach DOB: " << coachDOB << endl;
                cout << "Coach Gender: " << coachGen << endl;
                cout << "Coach Employment Date: " << coachEmpDate << endl;
                cout << "Coach Separation Date: " << coachSepDate << endl;
                cout << "Coach Commission: " << commission << endl;
                cout << "------------------------------\n" << endl;
                break;
            }
        }

        if (!found) {
            cout << "No record found with TRN " << trn << endl;
        }

        CoachSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}


//delete account
void Coach::DeleteAccount()
{
    try {
        string ctrn; // to hold coach TRN

        // creating & reading from CoachSeqFile object of the ifstream class
        ifstream CoachSeqFile("Coach.sq1", ios::in);

        if(!CoachSeqFile) {
            throw runtime_error("Failed to open file Coach.sq1");
        }

        // Enter the TRN of the coach account to be deleted
        cout << "\nEnter the TRN of the coach account to be deleted: ";
        cin >> ctrn;

        // variables to hold data read from file
        string fileCtrn, fileCfn, fileCmn, fileCln, fileCdob, fileCgen, fileCed, fileCsd;

        // creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        // read data from CoachSeqFile and write to TempSeqFile
        while (getline(CoachSeqFile, fileCtrn)) {
            getline(CoachSeqFile, fileCfn);
            getline(CoachSeqFile, fileCmn);
            getline(CoachSeqFile, fileCln);
            getline(CoachSeqFile, fileCdob);
            getline(CoachSeqFile, fileCgen);
            getline(CoachSeqFile, fileCed);
            getline(CoachSeqFile, fileCsd);

            // if the TRN does not match, write old details to TempSeqFile
            if (fileCtrn != ctrn) {
                TempSeqFile << fileCtrn << endl; 
                TempSeqFile << fileCfn << endl; 
                TempSeqFile << fileCmn << endl; 
                TempSeqFile << fileCln << endl; 
                TempSeqFile << fileCdob << endl; 
                TempSeqFile << fileCgen << endl; 
                TempSeqFile << fileCed << endl; 
                TempSeqFile << fileCsd << endl;
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        // close the files
        CoachSeqFile.close();
        TempSeqFile.close();

        // delete the original file and rename the temporary file
        remove("Coach.sq1");
        rename("Temp.sq1", "Coach.sq1");

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//display
void Coach::Show()
{
    try {
        string ctrn; // to hold coach TRN

        // creating & reading from CoachSeqFile object of the ifstream class
        ifstream CoachSeqFile("Coach.sq1", ios::in);

        if(!CoachSeqFile) {
            throw runtime_error("Failed to open file Coach.sq1");
        }

        // Enter the TRN of the coach account to be displayed
        cout << "\nEnter the TRN of the coach account to be displayed: ";
        cin >> ctrn;

        // variables to hold data read from file
        string fileCtrn, fileCfn, fileCmn, fileCln, fileCdob, fileCgen, fileCed, fileCsd;

        // read data from CoachSeqFile
        while (getline(CoachSeqFile, fileCtrn)) {
            getline(CoachSeqFile, fileCfn);
            getline(CoachSeqFile, fileCmn);
            getline(CoachSeqFile, fileCln);
            getline(CoachSeqFile, fileCdob);
            getline(CoachSeqFile, fileCgen);
            getline(CoachSeqFile, fileCed);
            getline(CoachSeqFile, fileCsd);

            // if the TRN matches, display the details
            if (fileCtrn == ctrn) {
                cout << "\nCoach TRN: " << fileCtrn << endl;
                cout << "Coach First Name: " << fileCfn << endl;
                cout << "Coach Middle Name: " << fileCmn << endl;
                cout << "Coach Last Name: " << fileCln << endl;
                cout << "Coach DOB: " << fileCdob << endl;
                cout << "Coach Gender: " << fileCgen << endl;
                cout << "Coach Employment Date: " << fileCed << endl;
                cout << "Coach Separation Date: " << fileCsd << endl;
                break;
            }
        }

        // close the file
        CoachSeqFile.close();

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

void Coach::ShowAll()
{
    try {
        //creating & reading from CoachSeqFile object of the ifstream class
        ifstream CoachSeqFile("Coach.sq1", ios::in);

        if(!CoachSeqFile) {
            throw runtime_error("Failed to open file Coach.sq1");
        }

        cout << "\n------------------ All Coaches Report ------------------\n";

        //variables to hold data read from file
        string fileCtrn, fileCfn, fileCmn, fileCln, fileCdob, fileCgen, fileCed, fileCsd;

        //read data from CoachSeqFile
        while (getline(CoachSeqFile, fileCtrn)) {
            getline(CoachSeqFile, fileCfn);
            getline(CoachSeqFile, fileCmn);
            getline(CoachSeqFile, fileCln);
            getline(CoachSeqFile, fileCdob);
            getline(CoachSeqFile, fileCgen);
            getline(CoachSeqFile, fileCed);
            getline(CoachSeqFile, fileCsd);

            cout << "\nCoach TRN: " << fileCtrn << endl;
            cout << "Coach First Name: " << fileCfn << endl;
            cout << "Coach Middle Name: " << fileCmn << endl;
            cout << "Coach Last Name: " << fileCln << endl;
            cout << "Coach DOB: " << fileCdob << endl;
            cout << "Coach Gender: " << fileCgen << endl;
            cout << "Coach Employment Date: " << fileCed << endl;
            cout << "Coach Separation Date: " << fileCsd << endl;
            cout << "------------------------------------------------------------\n" << endl;
        }

        // close the file
        CoachSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}


