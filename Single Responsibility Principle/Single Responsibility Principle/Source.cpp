//#include "Journal.h"
#include "PersistantManager.h"

int main() {
	Journal journal( "Dear Dairy" );
	journal.addEntries("I ate a bug");
	journal.addEntries("I have to bath");
	//journal.saveIntoFile("save.txt");

	//suppose if we want to save the data into
	//database instead of file then
	// we need to change into the class
	//and apart from saving the file itself 
	//if we want to load somthing then again
	//need to change in class
	//so ensure that there will be no chnage 
	//in class again or mean class will be 
	//persistant we will create a persistant Manager
	//to handle such cases.
	PersistantManager::save(journal,"PM_save.txt");
	return 0;
}