/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
using namespace std;
using namespace constants;

struct wordsAndFreq{
	string word;
	int wordFreq;
};

//TODO add a global array of entry structs (global to this file)

wordsAndFreq myArray[MAX_WORDS];


//TODO add variable to keep track of next available slot in array
int nextEmpty;
//TODO define all functions in header file

//zero out array that tracks words and their occurrences
void clearArray(){
	nextEmpty = 0;
}

//how many unique words are in array
int getArraySize(){

	return nextEmpty;//FIXME

}

//get data at a particular location
std::string getArrayWordAt(int i){
	return myArray[i].word;//FIXME

}
int getArrayWord_NumbOccur_At(int i){
	return myArray[i].wordFreq;//FIXME
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	string line;
	//openFile(myfstream,TEST_DATA_FULL);

	if(myfstream.is_open()){
		while(getline(myfstream,line)){
			processLine(line);
		}
		myfstream.close();
		return true;
	}
	else{
		return false;
	}
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	stringstream ss(myString);
	string tempToken;
	while(getline(ss,tempToken,CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}


}

/*Keep track of how many times each token seen*/
void processToken(std::string &token){
	strip_unwanted_chars(token);

	int i;
	for(i = 0;i<nextEmpty;i++){

		if(myArray[i].word == token){
			myArray[i].wordFreq += 1;
		}else if(myArray[i].word == ""){//myArray[i].word == nullptr ||
			myArray[i].word = token;
			myArray[i].wordFreq = 1;

		}
	}

}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){

	myfile.open(myFileName);
	if(myfile.is_open()){
		return true;
	}
	else{
		return false;//Not sure if i need this if/else statement
	}
}

/*if myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if(myfile.is_open()){
		myfile.close();
	}

}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	fstream myfstream;

	myfstream.open(outputfilename.c_str());

		if(myfstream.is_open()){
			for(int i;i<nextEmpty;i++){
				my
			}
			myfstream <<
			return SUCCESS;
		}
		else{
			return FAIL_FILE_DID_NOT_OPEN;
		}
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	//FIXME
//	switch (so) {
//	case constants::NONE:}

}

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
