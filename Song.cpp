#include "Song.h"

// TODO: finish to convert s to all lower case and return lower case string
string convertToLowercase(string s) {

	return "";
}

// TODO: finish Song default value constructor
Song::Song() {

}

// TODO: finish Song explicit value constructor
// converts title, artist, and genre params to lower case
// calls setRating() to clip to bounds of [1, 5]
Song::Song(string titleParam, string artistParam, string genreParam, string clipParam, int ratingParam) {

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

// TODO: finish to return string value for given attribute "title", "artist", "genre", "clip", or "rating"
// call getters 
// return empty string if attribute doesn't match 
string Song::getStringAttributeValue(string attribute) {
	
	return "";
}

