//===================================================================================
// Name        : CandidateElimination.h
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 24/08/2019
// Description : The Candidate Elimination algorithm (chapter 2 of [Mitchell, 1997])
//				 - written in C++, Ansi-style
//===================================================================================

#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include<set>

#ifndef LIBS_CE_H
#define LIBS_CE_H

using namespace std;

namespace DPLKYL002 {

class CandidateElimination

{

private:

	// private members
	int iteration, attribute;

	vector<string> vectSpecificBoundary;

	set<vector<string>> vectGeneralBoundary;

	vector<vector<string>> vectTrainingExample;

	ofstream outputFile;

public:

	// public members
	CandidateElimination(int iter, int attr, string inputData[][6])

	{

		iteration = iter;

		attribute = attr;

		vector<string> initialGeneralBoundary;

		for (int k = 0; k < attr - 1; k++)

		{

			vectSpecificBoundary.push_back("0");

			initialGeneralBoundary.push_back("?");

		}

		vectGeneralBoundary.insert(initialGeneralBoundary);

		vectTrainingExample = vector<vector<string>>(iter,
				vector<string>(attr));

		for (int k = 0; k < iter; k++)

		{

			for (int n = 0; n < attr; n++)

			{

				vectTrainingExample[k][n] = inputData[k][n];

			}

		}

	}
	;

	void candidateElimination(string inputData[][6]);

	bool checkValue(vector<string> k, vector<string> n);

};

}

#endif
