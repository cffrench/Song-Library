#ifndef PA5_H
#define PA5_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 10;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 11;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runDigitalMusicManager();

#endif
