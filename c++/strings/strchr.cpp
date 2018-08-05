#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
	const char * email = "ajinathkumbhar@gmail.com";
	const char * tmp = email;

	char c = tmp[0];

	while (c != '\0') {
		if (isspace(c)) {
			cout << "entered email is not valid : " << email << '\n' ;
			return -1;
		}
		tmp++;
		c = tmp[0];
	}


	const char * domain =  (char * )strchr(email,'@');
	cout << "at : " << domain - email + 1 << " : " << domain + 1 << '\n';

	const char * user = "akumbhar";
	char new_email[20] = {0};
	cout << strncat(new_email,user,9) << '\n';
	cout << strncat(new_email,domain,11) << '\n';
	cout << new_email << '\n';	

	if ( strpbrk(domain,"g") != 0)
		cout << "its gmail address " << '\n';
	else 
		cout << "its not gmail address " << '\n';

	string domain_string(domain);
	cout << domain_string.substr(0,5) << '\n';
	return 0;
}
