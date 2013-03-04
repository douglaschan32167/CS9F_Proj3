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
int main();

void InterpretCommands (istream& cmds) {
	string line, cmdWord;
	//____________________________ ;	// other definitions go here
	while ( getline(cmds, line) ) {		// get a line
		istringstream lineIn (line.c_str());
		//cmdWord = line.substr(0, line.find(' '));
		if ( lineIn >> cmdWord == false) {	// get the line's first word
			cerr << "Error: No command inputted." << endl;
		} else if (cmdWord=="update") {
			InterpretUpdate (lineIn);
		} else if (cmdWord=="list") {
			InterpretList (lineIn);
		} else if (cmdWord=="batch") {
			InterpretBatch (lineIn);
		} else if (cmdWord=="quit") {
			InterpretQuit (lineIn);
		} else {
			cerr << "Unrecognizable command word: " << cmdWord << endl;
		}
	}
}

void InterpretList(istream& lineIn) {
	string word, extra;
	if (!(lineIn >> word)) {
    cerr << "Error: No valid option provided for command list" << endl; 
    return;
	} else if (word.compare("names")!= 0 && word.compare("quantities") != 0) {
    cerr << "Error: Unknown option " << word << endl;
    return;
	}
  if (lineIn >> extra) {
    cerr << "Error: too many arguments provided for list : " << word << ", " << extra;
    while (lineIn >> extra) {
      cerr << ", " << extra;
    }
    cerr << endl;
    return;
	}
  
  // DO STUFF HERE
  cout << "list " << word << endl;
	
}

void InterpretQuit(istream& lineIn) {
	cout << "---Exiting application... ---" << endl;
	exit(0);

}

void InterpretUpdate(istream& lineIn) { 
	string word, extra;
  int number;
  
  // throw error if arguments are not of the correct type or not enough arguments have been provided
  if (!(lineIn >> word >> number)) {
    cerr << "Error: too few arguments of correct type (string, number) for update : " << word << ", " << number << endl;
    return;
  }
  // throw error if too many arguments given
  if (lineIn >> extra) {
    cerr << "Error: too many arguments provided for update : " << word << " " << number << " " << extra;
    while (lineIn >> extra) {
      cerr << ", " << extra;
    }
    cerr << endl;
    return;
	}
	
  // DO STUFF HERE (default: print command and arguments)
  cout << "update " << word << " " << number << endl;
	
  
}

void InterpretBatch(istream& lineIn) {
	string filename, filecontent, extra;
	if (!(lineIn >> filename)) {
    cerr << "Error: no file name provided for command batch. " << endl;
    return;
	}
	
	// ensure that only one argument is present
	if (lineIn >> extra) {
    cerr << "Error: too many arguments provided for batch : "<< filename << ", " << extra;
    while (lineIn >> extra) {
      cerr << ", " << extra;
    }
    cerr << endl;
    return;
	}
	
	// DO STUFF HERE
	
	ifstream filestr;
  filestr.open(filename.c_str());
	if (filestr.fail()) {
    cerr << "Error: File with name " << filename << " cannot be found." << endl;
    return;
	}
	while (getline(filestr, filecontent)) {
	  istringstream content (filecontent.c_str());
    InterpretCommands(content);
	}
	
	// resume reading input
  main();
}
















/* -- TESTS FOR PART 1 -- */
int partOneTest() {
  string input;
  // test blank input
  input = "\n";
  istringstream content1 (input.c_str());
  InterpretCommands(content1);
  cout << "Above should say: Error: No command inputted." << endl;
  
  // test three scenarios for update
  cout << "---TESTING UPDATE---" << endl;
  input = "update blah blah";
  istringstream content2 (input.c_str());
  InterpretCommands(content2);
  cout << "Above should say: Error: too few arguments of correct type" << endl;
  
  input = "update blah";
  istringstream content3 (input.c_str());
  InterpretCommands(content3);
  cout << "Above should say: Error: too few arguments of correct type" << endl;
  
  input = "update blah 5 blah";
  istringstream content4 (input.c_str());
  InterpretCommands(content4);
  cout << "Above should say: Error: too many arguments provided for update" << endl;
  
  
  // test three scenarios for list
  cout << "---TESTING LIST---" << endl;
  input = "list blah";
  istringstream content5 (input.c_str());
  InterpretCommands(content5);
  cout << "Above should say: Error: unknown option blah" << endl;
  
  input = "list";
  istringstream content6 (input.c_str());
  InterpretCommands(content6);
  cout << "Above should say: Error: no valid option provided for command list" << endl;
  
  input = "list names 5 blah";
  istringstream content7 (input.c_str());
  InterpretCommands(content7);
  cout << "Above should say: Error: too many arguments provided for list" << endl;
  
  
  // test three scenarios for batch
  cout << "---TESTING BATCH---" << endl;
  input = "batch nonexistentfile";
  istringstream content8 (input.c_str());
  InterpretCommands(content8);
  cout << "Above should say: Error: filename with nonexistentfile cannot be found" << endl;
  
  input = "batch";
  istringstream content9 (input.c_str());
  InterpretCommands(content9);
  cout << "Above should say: Error: no filename provided for command batch" << endl;
  
  input = "batch blah 5 blah";
  istringstream content10 (input.c_str());
  InterpretCommands(content10);
  cout << "Above should say: Error: too many arguments provided for batch" << endl;
  
  
  
  return 0;
}
/* -- END OF PART 1 TESTING -- */
















int main () {
  /* tests
  partOneTest();
  */
	InterpretCommands (cin);
	return 0;
}