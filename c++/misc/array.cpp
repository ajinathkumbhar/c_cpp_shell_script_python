#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int signalStrength[] = {23,65,86,12,34};
	int signalStrength_A[3] = {45,87,32};
	int signalStrength_B[5] ={0};

	// 2D char array
	char operatorName[5][15] = {
				"Airtel",
				"JIO",
				"BSNL",
				"Idea",
				"vodafone"
			};
	// string array 
	string operatorName_A[5] = {
				"Airtel",
				"JIO",
				"BSNL",
				"Idea",
				"vodafone"
			};

	// string array using vector
	vector<string> operatorName_B;
	operatorName_B.push_back("Airtel");
	operatorName_B.push_back("JIO");
	operatorName_B.push_back("Idea");
	operatorName_B.push_back("BSNL");
	operatorName_B.push_back("vodafone");

	for (int i = 0; i < operatorName_B.size(); ++i)
	{
		cout << operatorName_B[i] << '\n';
	}


	/****************
	2D array 
	*/

	int pictureSize[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int pictureSize_a[3][4]= {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}
			};
	cout << pictureSize_a[2][3] << endl;

	return 0;

}
