//sponsor implementation
//Travis Callam

#include "User.h"
#include "Athlete.h"
#include "Sponsor.h"
#include "Club.h"
#include "Global.h"

#include <iostream>
#include <string>
using namespace std;

//default con
Sponsor::Sponsor()
{
	sponName = "";
	sponAmnt = 0.0f;
	
	allSponsors.push_back(this);
}

//primary con
Sponsor::Sponsor(string sn, float sa)
{
	sponName = sn;
	sponAmnt = sa;
	
	allSponsors.push_back(this);
}

//mutators
void Sponsor::SetAthlete(Athlete* at)
{
	athlete = at;
}

void Sponsor::SetSponName(string sn)
{
	sponName = sn;
}

void Sponsor::SetSponAmnt(float sa)
{
	sponAmnt = sa;
}

//accessors
Athlete* Sponsor::GetAthlete()
{
	return athlete;
}

string Sponsor::GetSponName()
{
	return sponName;
}

float Sponsor::GetSponAmnt()
{
	return sponAmnt;
}

//switch athlete's sponsors
void Sponsor::SwitchAthlete() {
    string athleteTRN;
    // Ask for the athlete TRN
    std::cout << "Enter the TRN of the athlete to switch to: ";
    std::cin >> athleteTRN;

    // Find the athlete based on the TRN
    Athlete* newAthlete = club->findAthleteByTRN(athleteTRN); 

    if(newAthlete != NULL) {
        if (athlete != NULL) {
            // If the sponsor is currently sponsoring an athlete, remove them
            athlete->RemoveSponsor();
        }
        // Add the sponsor to the new athlete
        newAthlete->AddSponsor();
        // Update the athlete member to the new athlete
        athlete = newAthlete;
    } else {
        std::cout << "Athlete not found. Cannot perform operation.\n";
    }
}

		
//account manipulation
//create account
void Sponsor::CreateAccount()
{
	try {
        int count; //counter used in for loop
        int s; //to hold exactly _  records

        //variables to collect  info 
        string sn;
        float sa; 

        //creating & writing to SponSeqFile object of the ofstream class
        ofstream SponSeqFile("Sponsor.sq1", ios::out);

        if(!SponSeqFile) {
            throw runtime_error("Failed to open file Sponsor.sq1");
        }

        //Enter the total number of records
        cout << "\nEnter number of sponsor accounts to be made: ";
        cin >> s;

        //enter data for associations
        for(count = 0; count < s; ++count)
        {
            cout <<endl;

            cout << "\nEnter sponsor name: ";
            cin >> sn;

            cout << "\nEnter sponsor endorsement amount (0.0): ";
            cin >> sa;

            //write collected data into assoObj object of the association class
            Sponsor sponObj(sn, sa);

            //store collected data into AssoSeqFile object
            SponSeqFile << sponObj.GetSponName() << endl; 
            SponSeqFile << sponObj.GetSponAmnt() << endl; 
            SponSeqFile << "------------------------------\n" << endl;
        }
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//edit account
void Sponsor::EditAccount()
{
    try {
        string sn; // to hold sponsor name

        // creating & reading from SponSeqFile object of the ifstream class
        ifstream SponSeqFile("Sponsor.sq1", ios::in);

        if(!SponSeqFile) {
            throw runtime_error("Failed to open file Sponsor.sq1");
        }

        // Enter the name of the sponsor account to be edited
        cout << "\nEnter the name of the sponsor account to be edited: ";
        cin >> sn;

        // variables to hold data read from file
        string fileSn;
        float fileSa;

        // creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        // read data from SponSeqFile and write to TempSeqFile
        while (getline(SponSeqFile, fileSn)) {
            SponSeqFile >> fileSa;

            // if the name matches, prompt for new details
            if (fileSn == sn) {
            	//variables to collect  info 
        		float sa; 
                cout << "\nEnter new details for the sponsor account:\n";
                cout << "\nEnter sponsor name: ";
                cin >> sn;
                cout << "\nEnter sponsor endorsement amount (0.0): ";
                cin >> sa;

                // write new details to TempSeqFile
                TempSeqFile << sn << endl; 
                TempSeqFile << sa << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            } else {
                // write old details to TempSeqFile
                TempSeqFile << fileSn << endl;
                TempSeqFile << fileSa << endl;
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        // close the files
        SponSeqFile.close();
        TempSeqFile.close();

        // delete the original file and rename the temporary file
        remove("Sponsor.sq1");
        rename("Temp.sq1", "Sponsor.sq1");

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//search
void Sponsor::Search() {
    try {
        // Prompt the user for the sponsor name
        string name;
        cout << "Enter the name of the sponsor you want to search for: ";
        cin >> name;

        //creating & reading from SponSeqFile object of the ifstream class
        ifstream SponSeqFile("Sponsor.sq1", ios::in);

        if(!SponSeqFile) {
            throw runtime_error("Failed to open file Sponsor.sq1");
        }

        bool found = false;
        //read data from sponsors
        while(SponSeqFile >> sponName >> sponAmnt)
        {
            if (sponName == name) {
                found = true;
                cout << "\nSponsor Name: " << sponName << endl;
                cout << "Sponsor Endorsement Amount: " << sponAmnt << endl;
                cout << "------------------------------\n" << endl;
                break;
            }
        }

        if (!found) {
            cout << "No record found with name " << name << endl;
        }

        SponSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}


//delete account
void Sponsor::DeleteAccount()
{
    try {
        string sn; // to hold sponsor name

        // creating & reading from SponSeqFile object of the ifstream class
        ifstream SponSeqFile("Sponsor.sq1", ios::in);

        if(!SponSeqFile) {
            throw runtime_error("Failed to open file Sponsor.sq1");
        }

        // Enter the name of the sponsor account to be deleted
        cout << "\nEnter the name of the sponsor account to be deleted: ";
        cin >> sn;

        // variables to hold data read from file
        string fileSn;
        float fileSa;

        // creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        // read data from SponSeqFile and write to TempSeqFile
        while (getline(SponSeqFile, fileSn)) {
            SponSeqFile >> fileSa;

            // if the name does not match, write old details to TempSeqFile
            if (fileSn != sn) {
                TempSeqFile << fileSn << endl;
                TempSeqFile << fileSa << endl;
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        // close the files
        SponSeqFile.close();
        TempSeqFile.close();

        // delete the original file and rename the temporary file
        remove("Sponsor.sq1");
        rename("Temp.sq1", "Sponsor.sq1");

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//display
void Sponsor::Show()
{
    try {
        string sn; // to hold sponsor name

        // creating & reading from SponSeqFile object of the ifstream class
        ifstream SponSeqFile("Sponsor.sq1", ios::in);

        if(!SponSeqFile) {
            throw runtime_error("Failed to open file Sponsor.sq1");
        }

        // Enter the name of the sponsor account to be displayed
        cout << "\nEnter the name of the sponsor account to be displayed: ";
        cin >> sn;

        // variables to hold data read from file
        string fileSn;
        float fileSa;

        // read data from SponSeqFile
        while (getline(SponSeqFile, fileSn)) {
            SponSeqFile >> fileSa;

            // if the name matches, display the details
            if (fileSn == sn) {
                cout << "\nSponsor Name: " << fileSn << endl;
                cout << "Sponsor Endorsement Amount: " << fileSa << endl;
                break;
            }
        }

        // close the file
        SponSeqFile.close();

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

void Sponsor::ShowAll()
{
    try {
        //creating & reading from SponSeqFile object of the ifstream class
        ifstream SponSeqFile("Sponsor.sq1", ios::in);

        if(!SponSeqFile) {
            throw runtime_error("Failed to open file Sponsor.sq1");
        }

        cout << "\n------------------ All Sponsors Report ------------------\n";

        //variables to hold data read from file
        string fileSn;
        float fileSa;

        //read data from SponSeqFile
        while (getline(SponSeqFile, fileSn)) {
            SponSeqFile >> fileSa;

            cout << "\nSponsor Name: " << fileSn << endl;
            cout << "Sponsor Endorsement Amount: " << fileSa << endl;
            cout << "------------------------------------------------------------\n" << endl;
        }

        // close the file
        SponSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

