//association implementation
//Paris Scott

#include "User.h"
#include "Association.h"
#include "Club.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>
using namespace std;

//default constructor
Association::Association()
{
	assoID = 0;
	assoClubAm = 0;
	assoName = "";
	assoAddr = "";
}

//primary constructor
Association::Association(int id, int aca, string an, string aad)
{
	assoID = id;
	assoClubAm = aca;
	assoName = an;
	assoAddr = aad;
}

//mutators
void Association::SetAssoID(int id)
{
	assoID = id;
}

void Association::SetAssoClubAm(int aca)
{
	assoClubAm = aca;
}

void Association::SetAssoName(string an)
{
	assoName = an;
}

void Association::SetAssoAddr(string aad)
{
	assoAddr = aad;
}


//accessors
int Association::GetAssoID()
{
	return assoID;
}

int Association::GetAssoClubAm()
{
	return assoClubAm;
}

string Association::GetAssoName()
{
	return assoName;
}

string Association::GetAssoAddr()
{
	return assoAddr;
}

//implement the other methods here if they ever get declared in the class def
		
//create account method 
void Association::CreateAccount()
{
    try {
        int count; //counter used in for loop
        int a; //to hold exactly _ association records

        //variables to collect association info 
        int aid, acn;
        string an, ad;
        string un, pa; 

        //creating & writing to AssoSeqFile object of the ofstream class
        ofstream AssoSeqFile("Association.sq1", ios::out);

        if(!AssoSeqFile) {
            throw runtime_error("Failed to open file Association.sq1");
        }

        //Enter the total number of records
        cout << "\nEnter number of association accounts to be made: ";
        cin >> a;

        //enter data for associations
        for(count = 0; count < a; ++count)
        {
            cout <<endl;

            cout << "\nEnter association ID #: ";
            cin >> aid;

            cout << "\nEnter the number of clubs in the association: ";
            cin >> acn;

            cout << "\nEnter association name (separate each word with - or _ ): ";
            cin >> an;

            cout << "\nEnter association address (separate each word with - or _ ): ";
            cin >> ad;

            //write collected data into assoObj object of the association class
            Association assoObj(aid, acn, an, ad);

            //store collected data into AssoSeqFile object
            AssoSeqFile << assoObj.GetAssoID() << endl; 
            AssoSeqFile << assoObj.GetAssoClubAm() << endl; 
            AssoSeqFile << assoObj.GetAssoName() << endl; 
            AssoSeqFile << assoObj.GetAssoAddr() << endl; 
            AssoSeqFile << "------------------------------\n" << endl;
        }
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

		
//edit account method
void Association::EditAccount()
{
    try {
        int aid; //association id to be edited

        //variables to collect association info 
        int acn;
        string an, ad;

        //creating & reading from AssoSeqFile object of the ifstream class
        ifstream AssoSeqFile("Association.sq1", ios::in);

        if(!AssoSeqFile) {
            throw runtime_error("Failed to open file Association.sq1");
        }

        //creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        if(!TempSeqFile) {
            throw runtime_error("Failed to open file Temp.sq1");
        }

        cout << "\nEnter association ID # to edit: ";
        cin >> aid;

        //read data from associations
        while(AssoSeqFile >> assoID >> assoClubAm >> assoName >> assoAddr)
        {
            if(assoID == aid)
            {
                cout << "\nEnter the number of clubs in the association: ";
                cin >> acn;

                cout << "\nEnter association name (separate each word with - or _ ): ";
                cin >> an;

                cout << "\nEnter association address (separate each word with - or _ ): ";
                cin >> ad;

                //write collected data into assoObj object of the association class
                Association assoObj(aid, acn, an, ad);

                //store collected data into TempSeqFile object
                TempSeqFile << assoObj.GetAssoID() << endl; 
                TempSeqFile << assoObj.GetAssoClubAm() << endl; 
                TempSeqFile << assoObj.GetAssoName() << endl; 
                TempSeqFile << assoObj.GetAssoAddr() << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
            else
            {
                //write unedited data into TempSeqFile object
                TempSeqFile << assoID << endl; 
                TempSeqFile << assoClubAm << endl; 
                TempSeqFile << assoName << endl; 
                TempSeqFile << assoAddr << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        AssoSeqFile.close();
        TempSeqFile.close();

        //delete the original file
        remove("Association.sq1");

        //rename the temporary file to original file name
        rename("Temp.sq1", "Association.sq1");

        cout << "\nAssociation account edited successfully.\n";
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//search 
void Association::Search() {
    try {
        // Prompt the user for the ID
        int id;
        cout << "Enter the ID of the association you want to search for: ";
        cin >> id;

        //creating & reading from AssoSeqFile object of the ifstream class
        ifstream AssoSeqFile("Association.sq1", ios::in);

        if(!AssoSeqFile) {
            throw runtime_error("Failed to open file Association.sq1");
        }

        bool found = false;
        //read data from associations
        while(AssoSeqFile >> assoID >> assoClubAm >> assoName >> assoAddr)
        {
            if (assoID == id) {
                found = true;
                cout << "\nAssociation ID: " << assoID << endl;
                cout << "Number of Clubs in the Association: " << assoClubAm << endl;
                cout << "Association Name: " << assoName << endl;
                cout << "Association Address: " << assoAddr << endl;
                cout << "------------------------------\n" << endl;
                break;
            }
        }

        if (!found) {
            cout << "\nNo record found with ID " << id << endl;
        }

        AssoSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//delete account		
void Association::DeleteAccount()
{
    try {
        int aid; //association id to be deleted

        //creating & reading from AssoSeqFile object of the ifstream class
        ifstream AssoSeqFile("Association.sq1", ios::in);

        if(!AssoSeqFile) {
            throw runtime_error("Failed to open file Association.sq1");
        }

        //creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        if(!TempSeqFile) {
            throw runtime_error("Failed to open file Temp.sq1");
        }

        cout << "\nEnter association ID to delete: ";
        cin >> aid;

        //read data from associations
        while(AssoSeqFile >> assoID >> assoClubAm >> assoName >> assoAddr)
        {
            if(assoID != aid)
            {
                //write unedited data into TempSeqFile object
                TempSeqFile << assoID << endl; 
                TempSeqFile << assoClubAm << endl; 
                TempSeqFile << assoName << endl; 
                TempSeqFile << assoAddr << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        AssoSeqFile.close();
        TempSeqFile.close();

        //delete the original file
        remove("Association.sq1");

        //rename the temporary file to original file name
        rename("Temp.sq1", "Association.sq1");

        cout << "\nAssociation account deleted successfully.\n";
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//display association info
void Association::Show()
{
    try {
        //creating & reading from AssoSeqFile object of the ifstream class
        ifstream AssoSeqFile("Association.sq1", ios::in);

        if(!AssoSeqFile) {
            throw runtime_error("Failed to open file Association.sq1");
        }

        cout << "\nAssociation Information:\n";

        //read data from associations
        while(AssoSeqFile >> assoID >> assoClubAm >> assoName >> assoAddr)
        {
            cout << "\nAssociation ID: " << assoID << endl;
            cout << "Number of Clubs in the Association: " << assoClubAm << endl;
            cout << "Association Name: " << assoName << endl;
            cout << "Association Address: " << assoAddr << endl;
            cout << "------------------------------\n" << endl;
        }

        AssoSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

void Association::ShowAll()
{
    try {
        //creating & reading from AssoSeqFile object of the ifstream class
        ifstream AssoSeqFile("Association.sq1", ios::in);

        if(!AssoSeqFile) {
            throw runtime_error("Failed to open file Association.sq1");
        }

        cout << "\n------------------ All Associations Report ------------------\n";

        //read data from associations
        while(AssoSeqFile >> assoID >> assoClubAm >> assoName >> assoAddr)
        {
            cout << "\nAssociation ID: " << assoID << endl;
            cout << "Number of Clubs in the Association: " << assoClubAm << endl;
            cout << "Association Name: " << assoName << endl;
            cout << "Association Address: " << assoAddr << endl;
            cout << "------------------------------------------------------------\n" << endl;
        }

        AssoSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}


//add club to assoc
void Association::AddClub() {
    int clubCode;
    // Ask for the club name
    std::cout << "\nEnter the code of the club to add: ";
    std::cin >> clubCode;

    // Find the club based on the name
    Club* c = findClubByCode(clubCode); 

    if(c != NULL) {
        // Add the club to the list
        clubs.push_back(c); //add club to the assoc's list
        c->SetAssociation(this); //set clubs's assoc to this one
    } else {
        std::cout << "Club not found. Cannot perform operation.\n";
    }
    
    // Add the club to allClubs if it's not already there
    if (std::find(allClubs.begin(), allClubs.end(), c) == allClubs.end()) {
        allClubs.push_back(c);
    }
}

//remove club from assoc
void Association::RemoveClub() {
    int clubCode;
    // Ask for the club name
    std::cout << "Enter the code of the club to remove: ";
    std::cin >> clubCode;

    // Find the club based on the name
    Club* c = findClubByCode(clubCode); 

    if(c != NULL) {
        // Find the club in the list and remove them
        for (auto vector<Club*>::iterator it = clubs.begin(); it != clubs.end(); ++it) {
            if (*it == c) {
                // Remove the club from the list
                clubs.erase(it);
                break;
            }
        }
        // Set the club's assoc to nullptr
        c->SetAssociation(NULL);
    } else {
        std::cout << "\nClub not found. Cannot perform operation.\n";
    }
}

// Method to return all clubs that have an association
std::vector<Club*> Association::GetClubsWithAssociation() {
    std::vector<Club*> clubsWithAssociation;
    for (std::vector<Club*>::iterator it = allClubs.begin(); it != allClubs.end(); ++it) {
        Club* club = *it;
        if (club->GetAssociation() != NULL) {
            clubsWithAssociation.push_back(club);
        }
    }
    return clubsWithAssociation;
}

// Method to return all clubs that don't have an association
std::vector<Club*> Association::GetClubsWithoutAssociation() {
    std::vector<Club*> clubsWithoutAssociation;
    for (std::vector<Club*>::iterator it = allClubs.begin(); it != allClubs.end(); ++it) {
        Club* club = *it;
        if (club->GetAssociation() == NULL) {
            clubsWithoutAssociation.push_back(club);
        }
    }
    return clubsWithoutAssociation;
}

Club* Association::findClubByCode(int clubCode) {
    //creating & reading from ClubSeqFile object of the ifstream class
    ifstream ClubSeqFile("Club.sq1", ios::in);

    if(!ClubSeqFile) {
        throw runtime_error("Failed to open file Club.sq1");
    }

    Club* club = NULL;
    int code;
    string clubName;
    string clubColor;
    string clubPresi;
    string clubHeadCoach;
    float clubMemAmnt;
    float clubAssoFee;
    float annualFeeToCoach;

    //read data from clubs
    while(ClubSeqFile >> code >> clubName >> clubColor >> clubPresi >> clubHeadCoach >> clubMemAmnt >> clubAssoFee >> annualFeeToCoach)
    {
        if (code == clubCode) {
            club = new Club(code, clubName, clubColor, clubPresi, clubHeadCoach, clubMemAmnt, clubAssoFee, annualFeeToCoach);
            break;
        }
    }

    ClubSeqFile.close();
    return club; // Return NULL if no club found with the given name
}


//remove main after driver is added
/*
int main(){
	return 0;
}
*/

