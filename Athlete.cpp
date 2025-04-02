//athlete implementation
//Kaylen Eastwood

#include "User.h"
#include "Athlete.h"
#include "Club.h"
#include "Sponsor.h"
#include "Coach.h"
#include "Agent.h"
#include "Association.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

Athlete::Athlete() 
{
    athTRN = "";
    athFN = "";
    athMN = "";
    athLN = "";
    athGen = "";
    athDOB = "";
    athNationality = "";
    athHeight = 0.0f;
    athWeight = 0.0f;
    annualFee = 0.0f;
    
    allAthletes.push_back(this);
}

Athlete::Athlete(string trn, string fn, string mn, string ln, string gen, string dob, string nat, float height, float weight, float anf, string agtrn, string agfn, string agmn, string agln, string agem, string agp)
: agent(agtrn, agfn, agmn, agln, agem, agp)
{
    athTRN = trn;
    athFN = fn;
    athMN = mn;
    athLN = ln;
    athGen = gen;
    athDOB = dob;
    athNationality = nat;
    athHeight = height;
    athWeight = weight;
    annualFee = anf;
}

//mutators
void Athlete::SetClub(Club* c)
{
	club = c;
}

void Athlete::SetAthTRN(string trn)
{
    athTRN = trn;
}

void Athlete::SetAthFN(string fn)
{
    athFN = fn;
}

void Athlete::SetAthMN(string mn)
{
    athMN = mn;
}

void Athlete::SetAthLN(string ln)
{
    athLN = ln;
}

void Athlete::SetAthGen(string gen)
{
    athGen = gen;
}

void Athlete::SetAthDOB(string dob)
{
    athDOB = dob;
}

void Athlete::SetAthNationality(string nat)
{
    athNationality = nat;
}

void Athlete::SetAthHeigtht(float height)
{
    athHeight = height;
}

void Athlete::SetAthWeight(float weight)
{
    athWeight = weight;
}

void Athlete::SetAnnualFee(float anf)
{
    annualFee = anf;
}

//accessors
Club* Athlete::GetClub()
{
	return club;
}

string Athlete::GetAthTRN()
{
    return athTRN;
}

string Athlete::GetAthFN()
{
    return athFN;
}

string Athlete::GetAthMN()
{
    return athMN;
}

string Athlete::GetAthLN()
{
    return athLN;
}

string Athlete::GetAthGen()
{
    return athGen;
}

string Athlete::GetAthDOB()
{
    return athDOB;
}

string Athlete::GetAthNationality()
{
    return athNationality;
}

float Athlete::GetAthHeigtht()
{
    return athHeight;
}

float Athlete::GetAthWeight()
{
    return athWeight;
}

float Athlete::GetAnnualFee()
{
    return annualFee;
}

//methods to manipulate and set endorsement variable to sponsor amount value
void Athlete::SetEndorsAmnt(Sponsor &spon)
{
	if (club != NULL) {  // Check if club points to a valid object
    	club->SetEndorsAmnt(spon);
	}
}

float Athlete::GetEndorsAmnt() 
{
	if (club != NULL) {  // Check if club points to a valid object
    	return club->GetEndorsAmnt();
	}
	return 0.0f;  // Return a default value if club is not pointing to a valid object
}

//calculate/ pay annual fee
void Athlete::PayAnnualFee()
{
	annualFee = endorsAmnt * 0.1;
}

//switch athlete's club
void Athlete::SwitchClub() {
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

// Implement the remaining methods here
	
//account manipulation
//create account
void Athlete::CreateAccount()
{
	try {
        int count; //counter used in for loop
        int at; //to hold exactly _ records

        //variables to collect info 
        string atrn, afn, amn, aln, agen, adob, anat;
        float h, w, af;
        string agtrn, agfn, agmn, agln, agem, agp;

        //creating & writing to AssoSeqFile object of the ofstream class
        ofstream AthlSeqFile("Athlete.sq1", ios::out);

        if(!AthlSeqFile) {
            throw runtime_error("Failed to open file Athlete.sq1");
        }

        //Enter the total number of records
        cout << "\nEnter number of athlete accounts to be made: ";
        cin >> at;

        //enter data 
        for(count = 0; count < at; ++count)
        {
            cout <<endl;

            cout << "\nEnter athlete TRN (xxx-yyy-zzz): ";
            cin >> atrn;

            cout << "\nEnter athlete first name (separate each word with - or _ ): ";
            cin >> afn;

            cout << "\nEnter athlete middle name (separate each word with - or _ ): ";
            cin >> amn;

            cout << "\nEnter athlete last name (separate each word with - or _ ): ";
            cin >> aln;
            
            cout << "\nEnter athlete gender (as m/M for Male or f/F for Female): ";
            cin >> agen;
            
            cout << "\nEnter athlete DOB (dd/mm/yyyy): ";
            cin >> adob;
            
            cout << "\nEnter athlete nationality (separate each word with - or _ ): ";
            cin >> anat;
            
            cout << "\nEnter athlete height (0.0): ";
            cin >> h;
            
            cout << "\nEnter athlete weight (0.0): ";
            cin >> w;
            
            af = 0;
            
            cout << "\nEnter agent TRN (xxx-yyy-zzz): ";
            cin >> agtrn;
            
            cout << "\nEnter agent first name (separate each word with - or _ ): ";
            cin >> agfn;

            cout << "\nEnter agent middle name (separate each word with - or _ ): ";
            cin >> agmn;

            cout << "\nEnter agent last name (separate each word with - or _ ): ";
            cin >> agln;
            
            cout << "\nEnter agent email: ";
            cin >> agem;

            cout << "\nEnter agent phone (aaa-bbb-cccc): ";
            cin >> agp;

            //write collected data into assoObj object of the association class
            Athlete athlObj(atrn, afn, amn, aln, agen, adob, anat, h, w, af, agtrn, agfn, agmn, agln, agem, agp);

            //store collected data into AssoSeqFile object 
            AthlSeqFile << athlObj.GetAthTRN() << endl; 
            AthlSeqFile << athlObj.GetAthFN() << endl; 
            AthlSeqFile << athlObj.GetAthMN() << endl; 
            AthlSeqFile << athlObj.GetAthMN() << endl; 
            AthlSeqFile << athlObj.GetAthLN() << endl; 
            AthlSeqFile << athlObj.GetAthGen() << endl; 
            AthlSeqFile << athlObj.GetAthDOB() << endl; 
            AthlSeqFile << athlObj.GetAthNationality() << endl; 
            AthlSeqFile << athlObj.GetAthHeigtht() << endl; 
            AthlSeqFile << athlObj.GetAthWeight() << endl; 
            AthlSeqFile << athlObj.GetAnnualFee() << endl; 
            
            AthlSeqFile << athlObj.agent.GetAgentTRN() << endl; 
            AthlSeqFile << athlObj.agent.GetAgentFN() << endl; 
            AthlSeqFile << athlObj.agent.GetAgentMN() << endl; 
            AthlSeqFile << athlObj.agent.GetAgentLN() << endl; 
            AthlSeqFile << athlObj.agent.GetAgentEmail() << endl; 
            AthlSeqFile << athlObj.agent.GetAgentPhone() << endl; 
            AthlSeqFile << "------------------------------\n" << endl;
        }
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//edit account
void Athlete::EditAccount()
{
    try {
        string atrn; // to hold athlete TRN

        // creating & reading from AthlSeqFile object of the ifstream class
        ifstream AthlSeqFile("Athlete.sq1", ios::in);

        if(!AthlSeqFile) {
            throw runtime_error("Failed to open file Athlete.sq1");
        }

        // Enter the TRN of the athlete account to be edited
        cout << "\nEnter the TRN of the athlete account to be edited: ";
        cin >> atrn;

        // variables to hold data read from file
        string fileAtrn, fileAfn, fileAmn, fileAln, fileAgen, fileAdob, fileAnat;
        float fileH, fileW, fileAf;
        string fileAgtrn, fileAgfn, fileAgmn, fileAgln, fileAgem, fileAgp;

        // creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        // read data from AthlSeqFile and write to TempSeqFile
        while (getline(AthlSeqFile, fileAtrn)) {
            getline(AthlSeqFile, fileAfn);
            getline(AthlSeqFile, fileAmn);
            getline(AthlSeqFile, fileAln);
            getline(AthlSeqFile, fileAgen);
            getline(AthlSeqFile, fileAdob);
            getline(AthlSeqFile, fileAnat);
            AthlSeqFile >> fileH;
            AthlSeqFile >> fileW;
            AthlSeqFile >> fileAf;
            getline(AthlSeqFile, fileAgtrn);
            getline(AthlSeqFile, fileAgfn);
            getline(AthlSeqFile, fileAgmn);
            getline(AthlSeqFile, fileAgln);
            getline(AthlSeqFile, fileAgem);
            getline(AthlSeqFile, fileAgp);

            // if the TRN matches, prompt for new details
			if (fileAtrn == atrn) {
				//variables to collect info 
		        string atrn, afn, amn, aln, agen, adob, anat;
		        float h, w, af;
		        string agtrn, agfn, agmn, agln, agem, agp;
        
			    cout << "\nEnter new details for the athlete account:\n";
			
			    // similar prompts as in CreateAccount method
			    cout << "\nEnter athlete TRN (xxx-yyy-zzz): ";
			    cin >> atrn;
			
			    cout << "\nEnter athlete first name (separate each word with - or _ ): ";
			    cin >> afn;
			
			    cout << "\nEnter athlete middle name (separate each word with - or _ ): ";
			    cin >> amn;
			
			    cout << "\nEnter athlete last name (separate each word with - or _ ): ";
			    cin >> aln;
			    
			    cout << "\nEnter athlete gender (as m/M for Male or f/F for Female): ";
			    cin >> agen;
			    
			    cout << "\nEnter athlete DOB (dd/mm/yyyy): ";
			    cin >> adob;
			    
			    cout << "\nEnter athlete nationality (separate each word with - or _ ): ";
			    cin >> anat;
			    
			    cout << "\nEnter athlete height (0.0): ";
			    cin >> h;
			    
			    cout << "\nEnter athlete weight (0.0): ";
			    cin >> w;
			    
			    af = 0;
			    
			    cout << "\nEnter agent TRN (xxx-yyy-zzz): ";
			    cin >> agtrn;
			    
			    cout << "\nEnter agent first name (separate each word with - or _ ): ";
			    cin >> agfn;
			
			    cout << "\nEnter agent middle name (separate each word with - or _ ): ";
			    cin >> agmn;
			
			    cout << "\nEnter agent last name (separate each word with - or _ ): ";
			    cin >> agln;
			    
			    cout << "\nEnter agent email: ";
			    cin >> agem;
			
			    cout << "\nEnter agent phone (xxx-yyy-zzzz): ";
			    cin >> agp;
			
			    // write new details to TempSeqFile
			    TempSeqFile << atrn << endl; 
			    TempSeqFile << afn << endl; 
			    TempSeqFile << amn << endl; 
			    TempSeqFile << aln << endl; 
			    TempSeqFile << agen << endl; 
			    TempSeqFile << adob << endl; 
			    TempSeqFile << anat << endl; 
			    TempSeqFile << h << endl; 
			    TempSeqFile << w << endl; 
			    TempSeqFile << af << endl; 
			    TempSeqFile << agtrn << endl; 
			    TempSeqFile << agfn << endl; 
			    TempSeqFile << agmn << endl; 
			    TempSeqFile << agln << endl; 
			    TempSeqFile << agem << endl; 
			    TempSeqFile << agp << endl; 
			    TempSeqFile << "------------------------------\n" << endl;
			} else {
			    // write old details to TempSeqFile
			    // write old details to TempSeqFile
				TempSeqFile << fileAtrn << endl; 
				TempSeqFile << fileAfn << endl; 
				TempSeqFile << fileAmn << endl; 
				TempSeqFile << fileAln << endl; 
				TempSeqFile << fileAgen << endl; 
				TempSeqFile << fileAdob << endl; 
				TempSeqFile << fileAnat << endl; 
				TempSeqFile << fileH << endl; 
				TempSeqFile << fileW << endl; 
				TempSeqFile << fileAf << endl; 
				TempSeqFile << fileAgtrn << endl; 
				TempSeqFile << fileAgfn << endl; 
				TempSeqFile << fileAgmn << endl; 
				TempSeqFile << fileAgln << endl; 
				TempSeqFile << fileAgem << endl; 
				TempSeqFile << fileAgp << endl; 
				TempSeqFile << "------------------------------\n" << endl;
			}
        }

        // close the files
        AthlSeqFile.close();
        TempSeqFile.close();

        // delete the original file and rename the temporary file
        remove("Athlete.sq1");
        rename("Temp.sq1", "Athlete.sq1");

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//search
void Athlete::Search()
{
    try {
        string atrn; // to hold athlete TRN

        // Prompt the user to enter the TRN of the athlete account to be searched
        cout << "\nEnter the TRN of the athlete account to be searched: ";
        cin >> atrn;

        // creating & reading from AthlSeqFile object of the ifstream class
        ifstream AthlSeqFile("Athlete.sq1", ios::in);

        if(!AthlSeqFile) {
            throw runtime_error("Failed to open file Athlete.sq1");
        }

        // variables to hold data read from file
        string fileAtrn, fileAfn, fileAmn, fileAln, fileAgen, fileAdob, fileAnat;
        float fileH, fileW, fileAf;
        string fileAgtrn, fileAgfn, fileAgmn, fileAgln, fileAgem, fileAgp;

        bool found = false; // flag to indicate if the record is found

        // read data from AthlSeqFile
        while (getline(AthlSeqFile, fileAtrn)) {
            getline(AthlSeqFile, fileAfn);
            getline(AthlSeqFile, fileAmn);
            getline(AthlSeqFile, fileAln);
            getline(AthlSeqFile, fileAgen);
            getline(AthlSeqFile, fileAdob);
            getline(AthlSeqFile, fileAnat);
            AthlSeqFile >> fileH;
            AthlSeqFile >> fileW;
            AthlSeqFile >> fileAf;
            getline(AthlSeqFile, fileAgtrn);
            getline(AthlSeqFile, fileAgfn);
            getline(AthlSeqFile, fileAgmn);
            getline(AthlSeqFile, fileAgln);
            getline(AthlSeqFile, fileAgem);
            getline(AthlSeqFile, fileAgp);

            // if the TRN matches, display the details
            if (fileAtrn == atrn) {
                cout << "\nAthlete TRN: " << fileAtrn << endl;
                cout << "Athlete First Name: " << fileAfn << endl;
                cout << "Athlete Middle Name: " << fileAmn << endl;
                cout << "Athlete Last Name: " << fileAln << endl;
                cout << "Athlete Gender: " << fileAgen << endl;
                cout << "Athlete DOB: " << fileAdob << endl;
                cout << "Athlete Nationality: " << fileAnat << endl;
                cout << "Athlete Height: " << fileH << endl;
                cout << "Athlete Weight: " << fileW << endl;
                cout << "Annual Fee: " << fileAf << endl;
                cout << "Agent TRN: " << fileAgtrn << endl;
                cout << "Agent First Name: " << fileAgfn << endl;
                cout << "Agent Middle Name: " << fileAgmn << endl;
                cout << "Agent Last Name: " << fileAgln << endl;
                cout << "Agent Email: " << fileAgem << endl;
                cout << "Agent Phone: " << fileAgp << endl;
                found = true;
                break;
            }
        }

        // if the record is not found, display a message
        if (!found) {
            cout << "\nNo record found for the entered TRN." << endl;
        }

        // close the file
        AthlSeqFile.close();

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}



//delete account
void Athlete::DeleteAccount()
{
    try {
        string atrn; // to hold athlete TRN

        // creating & reading from AthlSeqFile object of the ifstream class
        ifstream AthlSeqFile("Athlete.sq1", ios::in);

        if(!AthlSeqFile) {
            throw runtime_error("Failed to open file Athlete.sq1");
        }

        // Enter the TRN of the athlete account to be deleted
        cout << "\nEnter the TRN of the athlete account to be deleted: ";
        cin >> atrn;

        // variables to hold data read from file
        string fileAtrn, fileAfn, fileAmn, fileAln, fileAgen, fileAdob, fileAnat;
        float fileH, fileW, fileAf;
        string fileAgtrn, fileAgfn, fileAgmn, fileAgln, fileAgem, fileAgp;

        // creating & writing to TempSeqFile object of the ofstream class
        ofstream TempSeqFile("Temp.sq1", ios::out);

        // read data from AthlSeqFile and write to TempSeqFile
        while (getline(AthlSeqFile, fileAtrn)) {
            getline(AthlSeqFile, fileAfn);
            getline(AthlSeqFile, fileAmn);
            getline(AthlSeqFile, fileAln);
            getline(AthlSeqFile, fileAgen);
            getline(AthlSeqFile, fileAdob);
            getline(AthlSeqFile, fileAnat);
            AthlSeqFile >> fileH;
            AthlSeqFile >> fileW;
            AthlSeqFile >> fileAf;
            getline(AthlSeqFile, fileAgtrn);
            getline(AthlSeqFile, fileAgfn);
            getline(AthlSeqFile, fileAgmn);
            getline(AthlSeqFile, fileAgln);
            getline(AthlSeqFile, fileAgem);
            getline(AthlSeqFile, fileAgp);

            // if the TRN does not match, write old details to TempSeqFile
            if (fileAtrn != atrn) {
                TempSeqFile << fileAtrn << endl; 
                TempSeqFile << fileAfn << endl; 
                TempSeqFile << fileAmn << endl; 
                TempSeqFile << fileAln << endl; 
                TempSeqFile << fileAgen << endl; 
                TempSeqFile << fileAdob << endl; 
                TempSeqFile << fileAnat << endl; 
                TempSeqFile << fileH << endl; 
                TempSeqFile << fileW << endl; 
                TempSeqFile << fileAf << endl; 
                TempSeqFile << fileAgtrn << endl; 
                TempSeqFile << fileAgfn << endl; 
                TempSeqFile << fileAgmn << endl; 
                TempSeqFile << fileAgln << endl; 
                TempSeqFile << fileAgem << endl; 
                TempSeqFile << fileAgp << endl; 
                TempSeqFile << "------------------------------\n" << endl;
            }
        }

        // close the files
        AthlSeqFile.close();
        TempSeqFile.close();

        // delete the original file and rename the temporary file
        remove("Athlete.sq1");
        rename("Temp.sq1", "Athlete.sq1");

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//display
void Athlete::Show()
{
    try {
        string atrn; // to hold athlete TRN

        // creating & reading from AthlSeqFile object of the ifstream class
        ifstream AthlSeqFile("Athlete.sq1", ios::in);

        if(!AthlSeqFile) {
            throw runtime_error("Failed to open file Athlete.sq1");
        }

        // Enter the TRN of the athlete account to be displayed
        cout << "\nEnter the TRN of the athlete account to be displayed: ";
        cin >> atrn;

        // variables to hold data read from file
        string fileAtrn, fileAfn, fileAmn, fileAln, fileAgen, fileAdob, fileAnat;
        float fileH, fileW, fileAf;
        string fileAgtrn, fileAgfn, fileAgmn, fileAgln, fileAgem, fileAgp;

        // read data from AthlSeqFile
        while (getline(AthlSeqFile, fileAtrn)) {
            getline(AthlSeqFile, fileAfn);
            getline(AthlSeqFile, fileAmn);
            getline(AthlSeqFile, fileAln);
            getline(AthlSeqFile, fileAgen);
            getline(AthlSeqFile, fileAdob);
            getline(AthlSeqFile, fileAnat);
            AthlSeqFile >> fileH;
            AthlSeqFile >> fileW;
            AthlSeqFile >> fileAf;
            getline(AthlSeqFile, fileAgtrn);
            getline(AthlSeqFile, fileAgfn);
            getline(AthlSeqFile, fileAgmn);
            getline(AthlSeqFile, fileAgln);
            getline(AthlSeqFile, fileAgem);
            getline(AthlSeqFile, fileAgp);

            // if the TRN matches, display the details
            if (fileAtrn == atrn) {
                cout << "\nAthlete TRN: " << fileAtrn << endl;
                cout << "Athlete First Name: " << fileAfn << endl;
                cout << "Athlete Middle Name: " << fileAmn << endl;
                cout << "Athlete Last Name: " << fileAln << endl;
                cout << "Athlete Gender: " << fileAgen << endl;
                cout << "Athlete DOB: " << fileAdob << endl;
                cout << "Athlete Nationality: " << fileAnat << endl;
                cout << "Athlete Height: " << fileH << endl;
                cout << "Athlete Weight: " << fileW << endl;
                cout << "Annual Fee: " << fileAf << endl;
                cout << "Agent TRN: " << fileAgtrn << endl;
                cout << "Agent First Name: " << fileAgfn << endl;
                cout << "Agent Middle Name: " << fileAgmn << endl;
                cout << "Agent Last Name: " << fileAgln << endl;
                cout << "Agent Email: " << fileAgem << endl;
                cout << "Agent Phone: " << fileAgp << endl;
                break;
            }
        }

        // close the file
        AthlSeqFile.close();

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

void Athlete::ShowAll()
{
    try {
        //creating & reading from AthlSeqFile object of the ifstream class
        ifstream AthlSeqFile("Athlete.sq1", ios::in);

        if(!AthlSeqFile) {
            throw runtime_error("Failed to open file Athlete.sq1");
        }

        cout << "\n------------------ All Athletes Report ------------------\n";

        //variables to hold data read from file
        string fileAtrn, fileAfn, fileAmn, fileAln, fileAgen, fileAdob, fileAnat;
        float fileH, fileW, fileAf;
        string fileAgtrn, fileAgfn, fileAgmn, fileAgln, fileAgem, fileAgp;

        //read data from AthlSeqFile
        while (getline(AthlSeqFile, fileAtrn)) {
            getline(AthlSeqFile, fileAfn);
            getline(AthlSeqFile, fileAmn);
            getline(AthlSeqFile, fileAln);
            getline(AthlSeqFile, fileAgen);
            getline(AthlSeqFile, fileAdob);
            getline(AthlSeqFile, fileAnat);
            AthlSeqFile >> fileH;
            AthlSeqFile >> fileW;
            AthlSeqFile >> fileAf;
            getline(AthlSeqFile, fileAgtrn);
            getline(AthlSeqFile, fileAgfn);
            getline(AthlSeqFile, fileAgmn);
            getline(AthlSeqFile, fileAgln);
            getline(AthlSeqFile, fileAgem);
            getline(AthlSeqFile, fileAgp);

            cout << "\nAthlete TRN: " << fileAtrn << endl;
            cout << "Athlete First Name: " << fileAfn << endl;
            cout << "Athlete Middle Name: " << fileAmn << endl;
            cout << "Athlete Last Name: " << fileAln << endl;
            cout << "Athlete Gender: " << fileAgen << endl;
            cout << "Athlete DOB: " << fileAdob << endl;
            cout << "Athlete Nationality: " << fileAnat << endl;
            cout << "Athlete Height: " << fileH << endl;
            cout << "Athlete Weight: " << fileW << endl;
            cout << "Annual Fee: " << fileAf << endl;
            cout << "Agent TRN: " << fileAgtrn << endl;
            cout << "Agent First Name: " << fileAgfn << endl;
            cout << "Agent Middle Name: " << fileAgmn << endl;
            cout << "Agent Last Name: " << fileAgln << endl;
            cout << "Agent Email: " << fileAgem << endl;
            cout << "Agent Phone: " << fileAgp << endl;
            cout << "------------------------------------------------------------\n" << endl;
        }

        // close the file
        AthlSeqFile.close();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Caught unknown exception" << endl;
    }
}

//add sponsor to athlete
void Athlete::AddSponsor() {
    string sn;
    // Ask for the sponsor name
    std::cout << "\nEnter the name of the sponsor to add: ";
    std::cin >> sn;

    // Find the sponsor based on the name
    Sponsor* s = findSponsorByName(sn); 

    if(s != NULL) {
        // Add the sponsor to the list
        sponsors.push_back(s); //add sponsor to the club's list
    } else {
        std::cout << "\nSponsor not found. Cannot perform operation.\n";
    }
    
    if (std::find(allSponsors.begin(), allSponsors.end(), s) == allSponsors.end()) {
        allSponsors.push_back(s);
	}
}

//remove sponsor from club
void Athlete::RemoveSponsor() {
    string sn;
    // Ask for the sponsor name
    std::cout << "\nEnter the name of the sponsor to remove: ";
    std::cin >> sn;

    // Find the sponsor based on the name
    Sponsor* s = findSponsorByName(sn); 

    if(s != NULL) {
        // Find the sponsor in the list and remove them
        for (auto vector<Sponsor*>::iterator it = sponsors.begin(); it != sponsors.end(); ++it) {
            if (*it == s) {
                // Remove the sponsor from the list
                sponsors.erase(it);
                break;
            }
        }
    } else {
        std::cout << "\nSponsor not found. Cannot perform operation.\n";
    }
}

// Method to return all sponsors that have an athlete
std::vector<Sponsor*> Athlete::GetSponsorsWithAthlete() {
    std::vector<Sponsor*> sponsorsWithAthlete;
    for (std::vector<Sponsor*>::iterator it = allSponsors.begin(); it != allSponsors.end(); ++it) {
        Sponsor* sponsor = *it;
        if (sponsor->GetAthlete() != NULL) {
            sponsorsWithAthlete.push_back(sponsor);
        }
    }
    return sponsorsWithAthlete;
}

// Method to return all sponsors that don't have an athlete
std::vector<Sponsor*> Athlete::GetSponsorsWithoutAthlete() {
    std::vector<Sponsor*> sponsorsWithoutAthlete;
    for (std::vector<Sponsor*>::iterator it = allSponsors.begin(); it != allSponsors.end(); ++it) {
        Sponsor* sponsor = *it;
        if (sponsor->GetAthlete() == NULL) {
            sponsorsWithoutAthlete.push_back(sponsor);
        }
    }
    return sponsorsWithoutAthlete;
}

//add coach to athlete
void Athlete::AddCoach() {
    string ctrn;
    // Ask for the coach TRN
    std::cout << "\nEnter the TRN of the coach to add: ";
    std::cin >> ctrn;

    // Find the coach based on the TRN
    Coach* c = findCoachByTRN(ctrn); 

    if(c != NULL) {
        // Add the coach to the list
        coaches.push_back(c); //add coach to the club's list
        c->SetAthlete(this); //set coach's club to this one
    } else {
        std::cout << "\nCoach not found. Cannot perform operation.\n";
    }
    
    if (std::find(allCoaches.begin(), allCoaches.end(), c) == allCoaches.end()) {
        allCoaches.push_back(c);
	}
}

//remove coach from club
void Athlete::RemoveCoach() {
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

// Method to return all coaches that have an athlete
std::vector<Coach*> Athlete::GetCoachesWithAthlete() {
    std::vector<Coach*> coachesWithAthlete;
    for (std::vector<Coach*>::iterator it = allCoaches.begin(); it != allCoaches.end(); ++it) {
        Coach* coach = *it;
        if (coach->GetAthlete() != NULL) {
            coachesWithAthlete.push_back(coach);
        }
    }
    return coachesWithAthlete;
}

// Method to return all coaches that don't have an athlete
std::vector<Coach*> Athlete::GetCoachesWithoutAthlete() {
    std::vector<Coach*> coachesWithoutAthlete;
    for (std::vector<Coach*>::iterator it = allCoaches.begin(); it != allCoaches.end(); ++it) {
        Coach* coach = *it;
        if (coach->GetAthlete() == NULL) {
            coachesWithoutAthlete.push_back(coach);
        }
    }
    return coachesWithoutAthlete;
}

//find coach by TRN
Coach* Athlete::findCoachByTRN(string trn) {
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


//find sponsor by name
Sponsor* Athlete::findSponsorByName(string name) {
    //creating & reading from SponSeqFile object of the ifstream class
    ifstream SponSeqFile("Sponsor.sq1", ios::in);

    if(!SponSeqFile) {
        throw runtime_error("Failed to open file Sponsor.sq1");
    }

    Sponsor* sponsor = NULL;
    string sn;
    float sa;

    //read data from sponsors
    while (getline(SponSeqFile, sn)) {
        SponSeqFile >> sa;

        if (sn == name) {
            sponsor = new Sponsor(sn, sa);
            break;
        }
    }

    SponSeqFile.close();
    return sponsor; // Return NULL if no sponsor found with the given name
}


//remove main() after implementing the main.cpp
/*
int main(){
	return 0;
}
*/

