/* Kevin Kan
 * ECE 2620-001
 * Post-Class Homework B2: Question 3:
 * Write a program to process the results of a local election as follows.
	The program first asks the user for the number of candidates in a local election, n. The program then
	dynamically creates an array of structures of size n with a pointer pointing to this array. Each structure in the
	array has two fields: last name of the candidate, and the number of votes received by her/him. The program
	then computes the percentage vote received by each candidate and outputs the voting data as shown below. (A
	sample of the output is shown).

	Candidate   Votes Received  % of Total Votes
	Johnson		5000			25.91
	Liu			4000			20.72
	Duffy		6000			31.09
	Robinson	2500			12.95
	Miller		1800  			9.33
	Total		19300			100.00
	The Winner of the Election is **Duffy**.
	Three cheers for **Duffy**.
 */

#include <iostream>
#include "candidate.h"

using namespace std;

double percentage(int a, int b){
	return ((double)a) / ((double) b) * 100;
}

int main(){
	int total = 0;		//Holds total number of votes
	candidate* winner;	//Holds winner of the election
	// PROMPT USER FOR NUMBER OF CANDIDATES
	int n; //Number of candidates in local election
	cout << "Please input number of candidates:";
	cin >> n;
	cout << "There are " << n << " candidates running." << endl;

	//CREATE ARRAY OF STRUCTURE CANDIDATE
	candidate* candidateP = new candidate[n];

	// PROMPT USER TO INPUT NAMES
	cout << "Please input last names of candidate(s):" << endl;
	for (int i = 0; i < n; i++){
		cout << "Candidate " << i+1 << ": ";
		cin >> (candidateP + i) -> lastname;
	}

	// PROMPT USER TO INPUT NUMBER OF VOTES
	winner = candidateP;
	for (int i = 0; i < n; i++){
		cout << "How many votes did " << (candidateP + i) -> lastname << " get?";
		cin >> (candidateP + i) -> numVotes;
		total = total + (candidateP + i) -> numVotes; //adds up votes
		if (((candidateP + i) -> numVotes) > (winner -> numVotes)){
			*winner = *(candidateP + i); //sets winner to candidate with highest number of votes
		}
	}

	// PRINT TABLE OF VOTING DATA
	cout << "Candidate \tVotes Received \t% of total votes" << endl;
	for (int i = 0; i < n; i++){
		cout << (candidateP + i) -> lastname << "\t\t" << (candidateP + i) -> numVotes << "\t\t" << percentage((candidateP + i) -> numVotes, total) << endl;
	}
	cout << "Total \t\t" << total << "\t\t100" << endl;

	// PRINT WINNER
	cout << "The Winner of the Election is **" << winner -> lastname << "**." << endl;
	cout << "Three cheers for **" << winner -> lastname << "**." << endl;
		
	return 0;
}

