#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;


int main(int argc, char const *argv[])
{
	// using getline 
	string email = "test sdf ";
	istringstream email_stream(email);
	std::vector<string> wordList;
	string word;
	while(getline(email_stream,word,' ')) {
		wordList.push_back(word);
	}
	for (int i = 0; i < wordList.size(); ++i)
	{
		cout << wordList[i] << '\n';
	}

	// using strtok
	char address[] = "Police, battalion, kondapur, hyderabard";
	char * token = strtok(address,",");
	// printf("%s\n", token);

	while(token != NULL) {
		printf("%s\n",token);
		token = strtok(NULL,",");
	}


	char path[] = "/usr/bin:/usr/etc/bin:/home/ajinath/bin";
	char * tok;
	char *rest = path;

	while((tok = strtok_r(rest,":",&rest))) {
		cout << tok << endl ;
	}

	return 0;
}