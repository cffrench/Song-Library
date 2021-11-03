#include "PA6.h"


void displayMenu() {
	cout << endl << "Welcome to the Digital Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Play song clip" << endl;
	cout << "7) Insert song in order" << endl;
	cout << "8) Remove song" << endl;
	cout << "9) Edit song" << endl;
	cout << "10) Exit" << endl;
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flushes the newline out of the buffer
	return choice;
}

void executeUserChoice(int choice, SongLibrary& lib) {
	switch (choice) {
		case 1:
			lib.loadLibrary();
			break;
		case 2:
			lib.saveLibrary();
			break;
		case 3: 
			lib.displayLibrary();
			break;
		case 4:
			lib.sortLibrary();
			break;
		case 5:
			lib.searchLibrary();
			break;
		case 6:
		 	lib.playSongClipInLibrary();
		 	break;
		case 7:
			lib.insertSongInLibraryOrder();
			break;
		case 8:
			lib.removeSongFromLibrary();
			break;
		case 9:
			lib.editSongInLibrary();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runDigitalMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the Digital Music Manager!!" << endl;
}
