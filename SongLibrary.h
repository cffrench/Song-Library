#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute; 

		void deleteLibrary();
		
		

	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); 
		~SongLibrary();
		Song * getHead(); 
		void setHead(Song *); 
		string getSortAttribute(); 
		void setSortAttribute(string);
		
		void performLoad(string);
		void performSave(string);
		void performSort(); 
		Song * performSearch(string, string, bool *, int *); 
		void performInsertSongInOrder(Song *); 
		void performRemoveSong(Song *); 
		void performEditSong(Song *, string, string); 
		
		void loadLibrary();
		void saveLibrary();
		void displayLibrary();
		void sortLibrary();
		void swapPositions(Song*, Song*, Song*);
		void searchLibrary();
		void playSongClipInLibrary();
		void insertSongInLibraryOrder();
		void removeSongFromLibrary();
		void editSongInLibrary();
		
};

#endif
