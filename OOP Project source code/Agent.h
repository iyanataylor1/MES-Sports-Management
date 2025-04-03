//agent class definition
//Travis Callam

#ifndef AGENT_H
#define AGENT_H

#include "Athlete.h"

#include <iostream>
#include <string>
using namespace std;

class Agent{
	private:
		string agentTRN, agentFN, agentMN, agentLN, agentEmail, agentPhone;
	public: 
		//class constructors
		
		Agent();
		Agent(string, string, string, string, string, string);
		
		//mutators
		void SetAgentTRN(string);
		void SetAgentFN(string);
		void SetAgentMN(string);
		void SetAgentLN(string);
		void SetAgentEmail(string);
		void SetAgentPhone(string);
		
		//accessors
		string GetAgentTRN();
		string GetAgentFN();
		string GetAgentMN();
		string GetAgentLN();
		string GetAgentEmail();
		string GetAgentPhone();
		
		
};

#endif

