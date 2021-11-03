#include "Song.h"

string convertToLowercase(string s) {
	for(unsigned int i=0; i<s.size(); i++) {
		s.at(i) = tolower(s.at(i));
	}
	return s;
}

Song::Song() {
	title = "";
	artist = "";
	genre = "";
	clip = "";
	rating = 1;
	next = NULL;
}

Song::Song(string titleParam, string artistParam, string genreParam, string clipParam, int ratingParam) {
	setTitle(titleParam);
	setArtist(artistParam);
	setGenre(genreParam);
	setClip(clipParam);
	setRating(ratingParam);
	next = NULL;
}

Song::Song(const Song& other) {
	title = other.title;
	artist = other.artist;
	genre = other.genre;
	clip = other.clip;
	rating = other.rating;
	next = other.next; 
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

string Song::getClip() {
	return clip;
}

void Song::setClip(string newClip) {
	clip = newClip;
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

Song * Song::getNext() {
	return next;
}

void Song::setNext(Song * newNext) {
	next = newNext;
}

string Song::getStringAttributeValue(string attribute) {
	if (attribute == "title") {
		getTitle();
		return title;
	}
	if (attribute == "artist") {
		getArtist();
		return artist;
	}
	if (attribute == "genre") {
		getGenre();
		return genre;
	}
	if (attribute == "clip") {
		getClip();
		return clip;
	}
	if (attribute == "rating") {
		getRating();
		return to_string(rating);
	}
	return "";
}

void Song::displaySong() {
	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Genre: " << genre << endl;
	cout << "Clip: " << clip << endl;
	cout << "Rating: " << rating << endl;
	cout << endl;
}

