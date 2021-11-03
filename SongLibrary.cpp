#include "SongLibrary.h"


SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	sortAttribute = "title";
}


// calls Song's copy constructor
SongLibrary::SongLibrary(const SongLibrary& other) {
	head = NULL;
	sortAttribute = other.sortAttribute;
	Song * otherSong = other.head;
	Song * copySong = NULL;
	
	while (otherSong != NULL) {
		Song * copy = new Song(*otherSong);
		copy->setNext(NULL);
		if (head == NULL) {
			head = copy;
		}
		if (copySong != NULL) {
			copySong->setNext(copy);
		}
		copySong = copy;
		otherSong = otherSong->getNext();
	}
}

SongLibrary::~SongLibrary() {
	deleteLibrary();
}

void SongLibrary::deleteLibrary() {
	Song * hold = head; 								//holds the value of the pointer.
	Song * dummySong;
	 while (hold != NULL) {
		dummySong = hold;
		hold = dummySong->getNext();
		delete dummySong;
		dummySong = NULL;
	}
	head = NULL;
}

Song * SongLibrary::getHead() {
	return head;
}

void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		deleteLibrary();
		newHead->setNext(head);
	}
	head = newHead;
}

void SongLibrary::loadLibrary() {
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;
	performLoad(filename);
}

void SongLibrary::saveLibrary() {
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;
	performSave(filename);
}

void SongLibrary::displayLibrary() {
	Song * currentSong = head;
	while (currentSong != NULL) {
		currentSong->displaySong();
		currentSong = currentSong->getNext();
	}
}

string SongLibrary::getSortAttribute() {
	return sortAttribute;
}

void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

void SongLibrary::performLoad(string filename) {
	deleteLibrary();
	string title;
	string artist;
	string genre;
	string clip;
	string rating;
	string filler;								//a filler line to collect line breaks.
	Song * dummySong;							//a Song used to temportatily store information.
	ifstream fin;
	fin.open(filename);
	while(!fin.eof()){
		getline(fin, title);
		getline(fin, artist);
		getline(fin, genre);
		getline(fin, clip);
		getline(fin, rating);
		dummySong = new Song(title, artist, genre, clip, std::stoi(rating));
		if (head == NULL) {
			head = dummySong;
		}
		dummySong->displaySong();
		performInsertSongInOrder(dummySong);
		getline(fin, filler);
	} 
	fin.close();
}

void SongLibrary::performSave(string filename) {
	Song * currentSong;
	currentSong = head;
	string title;
	string artist;
	string genre;
	string clip;
	string rating;
	string filler;
	cout << "Saving file" << endl;
	ofstream fout;
	fout.open(filename);						//opens the file desinated.  
	while(currentSong != NULL) {
		fout << currentSong->getTitle() << endl;
		fout << currentSong->getArtist() << endl;
		fout << currentSong->getGenre() << endl;
		fout << currentSong->getClip() << endl;
		fout << currentSong->getRating() << endl;
		if(currentSong->getNext() != NULL) {
			fout << endl;
		}
		currentSong = currentSong->getNext();
	} 
	fout.close();	
	
}

void SongLibrary::sortLibrary() {
	cout << "Enter what you wish to sort by: ";
	cin >> sortAttribute;
	cout << endl;
	performSort(); 
}

void SongLibrary::performSort() {
	Song * previousSong = NULL;
	Song * currentSong = head;
	Song * nextSong;	
	bool swap = false;
	while (currentSong != NULL) {				//bubble sort, but with while loops
		nextSong = currentSong->getNext();
		while (nextSong != NULL) {
			swap = false;
			if(getSortAttribute() == "title") {		
				if(currentSong->getTitle() > nextSong->getTitle()) {
					swap = true;
				}
			}
			else if (getSortAttribute() == "artist") {
				if(currentSong->getArtist() > nextSong->getArtist()) {
					swap = true;
				}
			}
			else if (getSortAttribute() == "genre") {
				if(currentSong->getGenre() > nextSong->getGenre()) {
					swap = true;
				}
			}
			else if (getSortAttribute() == "clip") {
				if(currentSong->getClip() > nextSong->getClip()) {
					swap = true;
				}
			}
			else if (getSortAttribute() == "rating") {
				if(currentSong->getRating() > nextSong->getRating()) {
					swap = true;
				}
			}
			if (swap) {
				if (currentSong == head) {
					head = nextSong;
				}
				swapPositions(previousSong, currentSong, nextSong);
				currentSong = nextSong; 
				
			}
			previousSong = nextSong;
			nextSong = nextSong->getNext();
		}
		previousSong = currentSong;
		currentSong = currentSong->getNext();
	}	
}

void SongLibrary::swapPositions(Song *one, Song *two, Song *three) {	//swaps the postions of the songs for sorting
	two->setNext(three->getNext());										//and repoints their pointers
	three->setNext(two);
	if (one != NULL) {
		one->setNext(three);
	}
}

void SongLibrary::searchLibrary() {
	string searchAttribute;
	string searchAttributeValue;
	Song * foundSong;
	int index;
	bool found = false;
	cout << "Enter the attribute you wish to search for: ";
	cin >> searchAttribute;
	cout << endl;
	cout << "Enter the value you wish to find: ";
	cin >> searchAttributeValue;
	cout << endl;
	foundSong = performSearch(searchAttribute, searchAttributeValue, &found, &index);
	if (found) {
		foundSong->displaySong();
	}
	else {
		cout << "No matching song found." << endl;
	}
}


Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	Song * currentSong = head;
	*found = false;
	*index = 0;
	while (currentSong != NULL) {
		if(searchAttribute == "title") {		
			if(currentSong->getTitle() == searchAttributeValue) {
				*found = true;
				break;
			}
		}
		else if (searchAttribute == "artist") {
			if(currentSong->getArtist() == searchAttributeValue) {
				*found = true;
				break;
			}
		}
		else if (searchAttribute == "genre") {
			if(currentSong->getGenre() == searchAttributeValue) {
				*found = true;
				break;
			}
		}
		else if (searchAttribute == "clip") {
			if(currentSong->getClip() == searchAttributeValue) {
				*found = true;
				break;
			}
		}
		else if (searchAttribute == "rating") {
			if(currentSong->getRating() == std::stoi(searchAttributeValue)) {
				*found = true;
				break;
			}
		}
		currentSong = currentSong->getNext();
		(*index)++;								//increase the index if the item is not found.
		
	}
	if (*found == false) {
		*index = -1;							//If it is not found, the index is set to -1.
	}
	return currentSong; 
}

void SongLibrary::playSongClipInLibrary() {
	string searchAttribute;
	string searchAttributeValue;
	Song * songClip;
	bool foundSong = false;
	int index;
	cout << "Enter the attribute you wish to search for: ";
	cin >> searchAttribute;
	cout << endl;
	cout << "Enter the value you wish to find: ";
	cin >> searchAttributeValue;
	cout << endl;
	songClip = performSearch(searchAttribute, searchAttributeValue, &foundSong, &index);
	if (foundSong) {
		string commandStr = "cvlc --play-and-exit " + songClip->getClip() + " 2> /dev/null &";

		system(commandStr.c_str());
	}
	else {
		cout << "No matching song found." << endl;
	}
}

void SongLibrary::insertSongInLibraryOrder() {
	Song * newSong;
	string title; 									//holds values to be entered into the Song.
	string artist;
	string genre;
	string clip;
	int rating;										//same but for ints.
	cout << "Enter the title of the new song: ";
	cin >> title;
	cout << endl;
	cout << "Enter the artist of the new song: ";
	cin >> artist;
	cout << endl;
	cout << "Enter the genre of the new song: ";
	cin >> genre;
	cout << endl;
	cout << "Enter the clip of the new song: ";
	cin >> clip;
	cout << endl;
	cout << "Enter the rating of the new song: ";
	cin >> rating;
	cout << endl;
	newSong = new Song(title, artist, genre, clip, rating);
	performInsertSongInOrder(newSong);					//adds the song to the library.
}

void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	Song * trackerPrevious = NULL;
	Song * trackerCurrent = head;
	bool insert = false;
	while(trackerCurrent != NULL) {
		if(getSortAttribute() == "title") {		
			if(songToInsert->getTitle() < trackerCurrent->getTitle()) {
				insert = true;
			}
		}
		else if (getSortAttribute() == "artist") {
			if(songToInsert->getArtist() < trackerCurrent->getArtist()) {
				insert = true;
			}
		}
		else if (getSortAttribute() == "genre") {
			if(songToInsert->getGenre() < trackerCurrent->getGenre()) {
				insert = true;
			}
		}
		else if (getSortAttribute() == "clip") {
			if(songToInsert->getClip() < trackerCurrent->getClip()) {
				insert = true;
			}
		}
		else if (getSortAttribute() == "rating") {
			if(songToInsert->getRating() < trackerCurrent->getRating()) {
				insert = true;
			}
		}
		if (insert) {
			break;
		}
		trackerPrevious = trackerCurrent; 
		trackerCurrent = trackerCurrent->getNext();
	}
	if(trackerPrevious == NULL) {
		head = songToInsert;
	}
	else {
		trackerPrevious->setNext(songToInsert); 
	}
	songToInsert->setNext(trackerCurrent);
}

void SongLibrary::removeSongFromLibrary() {
	string attribute;
	string attributeValue;
	bool found = false;
	int index = 0;
	cout << "Enter an attribute you wish to use to identify the song you would like to remove: ";
	cin >> attribute;
	cout << endl;
	cout << "Enter the " << attribute << " of the song you wish to remove: ";
	cin >> attributeValue;
	cout << endl; 
	performRemoveSong(performSearch(attribute, attributeValue, &found, &index));
}

void SongLibrary::performRemoveSong(Song * songToRemove) {
	Song * previousSong = NULL;
	Song * currentSong = head;
	while (currentSong != NULL) {
		if(songToRemove == currentSong) {
			if(previousSong == NULL) {
				head = songToRemove->getNext();
			}
			else {
				previousSong->setNext(songToRemove->getNext());
			}
			break;
		}
		previousSong = currentSong;
		currentSong = currentSong->getNext();
	}
}

void SongLibrary::editSongInLibrary() {
	string attribute;
	string attributeValue;
	bool found = false;
	int index = 0;
	Song * songToEdit;
	cout << "Enter an attribute you wish to use to identify the song you would like to edit: ";
	cin >> attribute;
	cout << endl;
	cout << "Enter the " << attribute << " of the song you wish to edit: ";
	cin >> attributeValue;
	cout << endl; 
	songToEdit = (performSearch(attribute, attributeValue, &found, &index));
	cout << "Enter an attribute you wish to edit: ";
	cin >> attribute;
	cout << endl;
	cout << "Enter the new " << attribute << ": ";
	cin >> attributeValue;
	cout << endl; 
	performEditSong(songToEdit, attribute, attributeValue);
}

void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	Song * currentSong = head;
	while (currentSong != NULL) {
		if(attribute == "title") {		
			if(currentSong == songToEdit) {
				currentSong->setTitle(newAttributeValue);
				break;
			}
		}
		else if (attribute == "artist") {
			if(currentSong == songToEdit) {
				currentSong->setArtist(newAttributeValue);
				break;
			}
		}
		else if (attribute == "genre") {
			if(currentSong == songToEdit) {
				currentSong->setGenre(newAttributeValue);
				break;
			}
		}
		else if (attribute == "clip") {
			if(currentSong == songToEdit) {
				currentSong->setClip(newAttributeValue);
				break;
			}
		}
		else if (attribute == "rating") {
			if(currentSong == songToEdit) {
				currentSong->setRating(std::stoi(newAttributeValue));
				break;
			}
		}
		currentSong = currentSong->getNext();
	}
}
