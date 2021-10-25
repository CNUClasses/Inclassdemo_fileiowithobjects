/*
 * FileIO.cpp
 *
 *  Created on: Oct 25, 2021
 *      Author: keith
 */

#include "FileIO.h"

FileIO::FileIO(std::string &fn):fn(fn) {
	ms.open(fn.c_str(),
		std::fstream::in | std::fstream::out | std::fstream::app); //open for append
	if (!ms.is_open())
		ms.open(fn.c_str(),
			std::fstream::in | std::fstream::out | std::fstream::trunc); //file probs not there force it opened and empty
}


void FileIO::close() {
	if (ms.is_open())
		ms.close();
}

FileIO::~FileIO() {
	close();
}

void FileIO::clear(){
	close();
	ms.open(fn.c_str(),
		std::fstream::in | std::fstream::out | std::fstream::trunc); //file probs not there force it opened and empty

}

/**
 * append to the file
 * @param info what is appended
 * @return 
 */
bool FileIO::writeln(std::string &info){
	if(!ms.is_open())
		return false;
	ms<<info<<std::endl;
	return true;
}

/**
 * read whole file
 * @param info
 * @return
 */
bool FileIO::read(std::string &info){
	if(!ms.is_open())
		return false;
	
	//go to beginning of file
	ms.seekg(std::ios::beg);
	
	std::string line;
	while(!ms.eof()){
		getline(ms,line);
		info+=line+'\n';
	}
	return true;
}

