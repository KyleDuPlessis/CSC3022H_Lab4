//===================================================================================
// Name        : Driver.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 24/08/2019
// Description : The Candidate Elimination algorithm (chapter 2 of [Mitchell, 1997])
//				 - written in C++, Ansi-style
//===================================================================================

#include "CandidateElimination.h"

// main function
int main(int argc, char * argv[]) { // argc and argv values passed into main

	// setup using the minimum number of training examples to learn the concept (Japanese Sports Car)
	string inputData[4][6] = { { "Japan", "Honda", "Blue", "1980", "Sports",
			"Positive" }, { "Japan", "Toyota", "Green", "1970", "Sports",
			"Positive" }, { "Japan", "Toyota", "Blue", "1990", "Economy",
			"Negative" }, { "USA", "Chrysler", "Red", "1980", "Sports",
			"Negative" } };

	DPLKYL002::CandidateElimination ce(4, 6, inputData);

	ce.candidateElimination(inputData);

	return 0;

}
