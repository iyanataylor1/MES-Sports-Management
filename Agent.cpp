//agent class implementation
//Travis Callam

#include "Agent.h"
#include "Athlete.h"

#include <iostream>
#include <string>
using namespace std;

Agent::Agent()
{
	agentTRN = "";
	agentFN = "";
	agentMN = "";
	agentLN = "";
	agentEmail = "";
	agentPhone = "";
}

Agent::Agent(string atrn, string afn, string amn, string aln, string ae, string ap)
{
	agentTRN = atrn;
	agentFN = afn;
	agentMN = amn;
	agentLN = aln;
	agentEmail = ae;
	agentPhone = ap;
}

void Agent::SetAgentTRN(string atrn)
{
	agentTRN = atrn;
}

void Agent::SetAgentFN(string afn)
{
	agentFN = afn;
}

void Agent::SetAgentMN(string amn)
{
	agentMN = amn;
}

void Agent::SetAgentLN(string aln)
{
	agentLN = aln;
}

void Agent::SetAgentEmail(string ae)
{
	agentEmail = ae;
}

void Agent::SetAgentPhone(string ap)
{
	agentPhone = ap;
}

string Agent::GetAgentTRN()
{
	return agentTRN;
}

string Agent::GetAgentFN()
{
	return agentFN;
}

string Agent::GetAgentMN()
{
	return agentMN;
}

string Agent::GetAgentLN()
{
	return agentLN;
}

string Agent::GetAgentEmail()
{
	return agentEmail;
}

string Agent::GetAgentPhone()
{
	return agentPhone;
}

//remove this main method when i create the driver
/*
int main()
{
	return 0;
}
*/

