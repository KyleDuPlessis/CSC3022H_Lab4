//===================================================================================
// Name        : CandidateElimination.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 24/08/2019
// Description : The Candidate Elimination algorithm (chapter 2 of [Mitchell, 1997])
//				 - written in C++, Ansi-style
//===================================================================================

#include "CandidateElimination.h"

void DPLKYL002::CandidateElimination::candidateElimination(
		string inputData[][6])

		{

	outputFile = ofstream("answers.txt");

	outputFile << "***** Input training examples *****" << endl << endl;

	outputFile << "Origin Manufacturer Colour Decade Type Label" << endl;

	for (int n = 0; n < 4; ++n) {

		for (int m = 0; m < 6; ++m) {

			outputFile << inputData[n][m] << " ";

		}

		outputFile << endl;

	}

	outputFile << "\n***** The Candidate Elimination algorithm *****" << endl
			<< endl;

	for (int a = 0; a < iteration; a++)

	{

		if (vectTrainingExample[a][attribute - 1].compare("Positive") == 0)

		{

			for (int b = 0; b < attribute - 1; b++)

			{

				if (vectSpecificBoundary[b] == "0") {

					vectSpecificBoundary[b] = vectTrainingExample[a][b];

				}

				if (vectSpecificBoundary[b].compare(vectTrainingExample[a][b])) {

					vectSpecificBoundary[b] = "?";

				}

			}

			set<vector<string>>::iterator iterate;

			for (iterate = vectGeneralBoundary.begin();

					iterate != vectGeneralBoundary.end(); iterate++)

					{

				for (int b = 0; b < attribute - 1; b++)

				{

					if ((*iterate)[b] != vectSpecificBoundary[b]
							&& vectSpecificBoundary[b] == "?")

							{

						vectGeneralBoundary.erase(iterate);

						iterate = vectGeneralBoundary.begin();

					}

				}

			}

		}

		else

		{

			set<vector<string>>::iterator iterate;

			for (iterate = vectGeneralBoundary.begin();
					iterate != vectGeneralBoundary.end();)

					{

				vector<string> vectTemp;

				for (int b = 0; b < attribute - 1; b++)

				{

					vectTemp.push_back((*iterate)[b]);

				}

				if (checkValue(vectTemp, vectTrainingExample[a]))

				{

					for (int b = 0; b < attribute - 1; b++)

					{

						if (vectSpecificBoundary[b] != "?"
								&& vectSpecificBoundary[b]
										!= vectTrainingExample[a][b]
								&& vectTemp[b] == "?")

								{

							vectTemp[b] = vectSpecificBoundary[b];

							vectGeneralBoundary.insert(
									vectGeneralBoundary.begin(), vectTemp);

							vectTemp[b] = "?";

						}

					}

					vectGeneralBoundary.erase(iterate);

					iterate = vectGeneralBoundary.begin();

				}

				else {

					iterate++;

				}

				vectTemp.clear();

			}

		}

		outputFile << "S" << a + 1 << ": {(";

		for (int k = 0; k < attribute - 1; k++)

		{

			outputFile << vectSpecificBoundary[k];

			if (k != (attribute - 2)) {

				outputFile << ", ";

			}

		}

		outputFile << ")}" << endl;

		set<vector<string>>::iterator iterate, tempIterate;

		outputFile << "G" << a + 1 << ": {(";

		for (iterate = vectGeneralBoundary.begin();
				iterate != vectGeneralBoundary.end(); iterate++)

				{

			tempIterate = iterate;

			for (int n = 0; n < attribute - 1; n++)

			{

				outputFile << (*iterate)[n];

				if (n != (attribute - 2)) {

					outputFile << ", ";

				}

			}

			if (!(++tempIterate == vectGeneralBoundary.end()))

			{

				outputFile << ',';

			}

		}

		outputFile << ")}" << endl << endl;

	}

	outputFile << "***** Learned the target concept *****" << endl;

	outputFile
			<< "\nTherefore, the minimum number of training examples to learn the above concept is 4."
			<< endl;

	outputFile.close();

	cout << "answers.txt written successfully" << endl;

}

bool DPLKYL002::CandidateElimination::checkValue(vector<string> k,
		vector<string> n)

		{

	for (int b = 0; b < attribute - 1; b++)

	{

		if (k[b] != n[b] && k[b] != "?") {

			return false;

		}

	}

	return true;

}

