#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void InterpretCommands (istream&);
void InterpretUpdate (istream&);
void InterpretList (istream&);
void InterpretBatch (istream&);
void InterpretQuit (istream&);

void InterpretCommands (istream& cmds) {
	string line, cmdWord;
	//____________________________ ;	// other definitions go here
	while ( getline(cin, line) ) {		// get a line
		istringstream lineIn (line.c_str());
		//cmdWord = line.substr(0, line.find(' '));
		if ( lineIn >> cmdWord == false) {	// get the line's first word
			cerr << "no word input" << endl;
			return;	// there weren't any words
		} else if (cmdWord=="update") {
			InterpretUpdate (lineIn);
		} else if (cmdWord=="list") {
			InterpretList (lineIn);
		} else if (cmdWord=="batch") {
			InterpretBatch (lineIn);
		} else if (cmdWord=="quit") {
			InterpretQuit (lineIn);
		} else {
			cerr << "Unrecognizable command word." << cmdWord << endl;
		}
	}
}

void InterpretList(istream& lineIn) {
	string word;
	cout << "list ";
	while (lineIn.eof() == false) {
		lineIn >> word;
		cout << word;
	}
	cout << endl;
}

void InterpretQuit(istream& lineIn) {
	cout << "quit called" << endl;
	exit(0);

}

void InterpretUpdate(istream& lineIn) { 
	cout << "update ";
	string word;
	while (lineIn.eof() == false) {
		lineIn >> word;
		cout << word;
	}
	cout << endl;
}

void InterpretBatch(istream& lineIn) {
	cout << "batch called" << endl;
	string filename;
	lineIn >> filename;
	ifstream filestr (filename, ifstream::in);
	cout << "file name is " << filename << endl;
	
}
int main () {
	InterpretCommands (cin);
	return 0;
}