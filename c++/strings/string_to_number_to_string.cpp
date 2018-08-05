#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <boost/lexical_cast.hpp>
using namespace std;

int main(int argc, char const *argv[])
{
	// 1. string to number
	// atoi
	const char * model = "345234";
	int modelInt = atoi(model);
	printf("%d\n",modelInt);

	// stoi
	string model_string(model);
	modelInt = stoi(model_string);
	printf("%d\n", modelInt);

	//istring stream 
	istringstream model_stream(model_string);
	model_stream >> modelInt;
	printf("%d\n", modelInt);

	// boost lib lexical_cast
	// sudo apt-get install libboost-all-dev
	modelInt = boost::lexical_cast<int>(model);
	printf("%d\n", modelInt);


	// 2. number to string
	// ostringstream
	int part_number = 22443245;
	ostringstream part_number_stream;
	part_number_stream << part_number;
	string part_number_string = part_number_stream.str();
	printf("%s\n",part_number_string.c_str());

	//to_string
	part_number_string = to_string(part_number);
	printf("%s\n",part_number_string.c_str());

	//boost::lexical_cast
	part_number_string = boost::lexical_cast<string> (part_number);
	printf("%s\n",part_number_string.c_str());

	return 0;
}