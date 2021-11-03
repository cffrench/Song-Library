#include "SongLibrary.h"

SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

// TODO: finish SongLibrary destructor
// be sure to properly free memory!!
SongLibrary::~SongLibrary() {
	
}

int SongLibrary::getNumSongs() {
	return numSongs;
}

void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

Song * SongLibrary::getSongsList() {
	return songs;
}

void SongLibrary::setSongsList(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

void SongLibrary::loadLibrary() {
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;
	performLoad(filename);
}

// TODO: finish this function
void SongLibrary::performLoad(string filename) {

}

// TODO: finish this function
void SongLibrary::performSave(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSort(string attribute) {
	
}

// TODO: finish this function
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	
	return false;
}

// TODO: finish this function
void SongLibrary::performAddSong(Song newSong) {
	
}

// TODO: finish this function
// set songs to NULL if list becomes empty after remove
void SongLibrary::performRemoveSong(int indexToRemove) {
	
}

// TODO: finish this function
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	
}
