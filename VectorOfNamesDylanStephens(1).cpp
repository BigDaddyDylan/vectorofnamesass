//Dylan Stephens
//Vector of names assignment
//C++ programming

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintIntro();
void PlayGame();
void AddName();
void RemoveName();
void ChangeName();
void SortNames();
char QuitGame();

vector<string> names; //TODO build a vector of names
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;

bool bQuit = true; //End program

int main() {
	
	names.push_back("Dylan");
	names.push_back("Sabrina");
	names.push_back("Axel");
	names.push_back("Elle");
	names.push_back("Matt");	
	
	PrintIntro();

	do {  		
		PlayGame();		
	}while(bQuit == true);     
  
  //TODO quit program
  return 0;
}

void PrintIntro() {
	cout << "\nWelcome to the Name Listing program!\n";
	
	return;
}


void PlayGame() {
	
	cout << "\nThe current names on the the list are:\n";

	//TODO FOR loop to iterate through list
	for(iter = names.begin(); iter != names.end(); iter++) {
		cout << *iter << endl;
	}
	
	//TODO give the player options
	string choice = "";
	
	cout << "\nPlease pick an option:\n";
	cout << "Type Add name\n";
	cout << "Type Remove name\n";
	cout << "Type Change name\n";
	cout << "Type Show names\n";
	cout << "Type Quit to end\n\n";
	getline(cin, choice);
	
	if(choice == "add name" || choice == "Add name") {
		AddName();
	} else if (choice == "remove name" || choice == "Remove name") {
		RemoveName();
	} else if (choice == "change name" || choice == "Change name") {
		ChangeName();
	} else if (choice == "show names" || choice == "Show names") {
		SortNames();
	} else if (choice == "quit" || choice == "Quit") {
		char quit = QuitGame();
		//test char from quitgame function to determine end
		if(quit == 'y' || quit == 'Y') {
			cout << "Have a nice day!\n";
			bQuit = false;
		} else {
			bQuit = true;
		}
	} else {
		cout << "Invalid Option\n";
	}
	return;
}

void AddName() {
	string addedName = "";
    cout << "Enter the name to add: ";    
    getline(cin, addedName);
    names.push_back(addedName); //TODO add name 
}

void RemoveName() {
	string remove = "";
	cout << "Enter a name to remove: ";
	getline(cin, remove);
	iter = names.begin();

    while (iter != names.end()) { //TODO remove name
        if(*iter == remove) {
            iter = names.erase(iter);
		} else {
           	iter++;
		}
    }
}

void ChangeName() {
	string change = "";
	cout << "Enter a name to change: ";
	getline(cin, change);
	myIterator = find(names.begin(), names.end(), change);	
	
	if(*myIterator == change) { //TODO change name
		string newName = "";
		cout << "Enter new name: ";
		getline(cin, newName);
		*myIterator = newName;
	}
}

void SortNames() {
	sort(names.begin(), names.end());//TODO show sorted names
}

char QuitGame() { //Quit game function
	cout << "Are you sure you want to quit? ";
    string response = "";
    getline(cin, response);
	// return the 1st character in string response
	return response[0]; 	
}







