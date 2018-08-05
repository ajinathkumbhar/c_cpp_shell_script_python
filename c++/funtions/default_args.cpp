#include <stdlib.h>
#include <stdio.h>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string.h>
#include <iostream>
#include <tuple>

#define DEFAULT_FILE "/tmp/log.txt"
using namespace std;

class logStream {
	private:
		char * path;
 	public:
 		logStream(const char * path = DEFAULT_FILE) {
 			this->path = new char[256];
 			strcpy(this->path,path);
 		}

 		~logStream() {
 			delete[] this->path;
 		}

 		void printPath() {
 			std::cout << this->path << '\n';
 		}

 		char * getpath(void);

};

inline char * logStream::getpath(void) {
	return this->path;
}

inline int getModel(void) {
	return 123123;
}

tuple<const char *,const char * , int> getDeviceInfo() {
	return make_tuple("rimo","phone",2);
}

pair<const char *,float> getThermalData() {
	return make_pair("Back Panel",45.4);
}


int main(int argc,const char * argv[]) {
	logStream mainlog;
	mainlog.printPath();
	logStream radiolog("/tmp/radio.txt");
	radiolog.printPath();
	cout << radiolog.getpath() << '\n';
	int model = getModel();
	cout << model << '\n';

	const char * board, * name;
	int type;
	tie(board,name,type) = getDeviceInfo();
	cout << board << setw(10) << name << setw(10) << type << '\n';

	pair<const char *,float> thermal_data = getThermalData();
	cout << thermal_data.first << setw(10) << thermal_data.second << '\n';

}