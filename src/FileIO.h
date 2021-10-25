/*
 * FileIO.h
 *
 *  Created on: Oct 25, 2021
 *      Author: keith
 */

#ifndef FILEIO_H_
#define FILEIO_H_
#include <string>
#include <fstream>

class FileIO {
private:
	std::string fn;
	std::fstream ms;

	void close();

public:
	FileIO(std::string &fn);
	virtual ~FileIO();
	
	/**
	 * empties the file
	 */
	void clear();
	/**
	 * append a line to the file
	 * @param info what is appended
	 * @return 
	 */
	bool writeln(std::string &info);	
	/**
	 * read whole file
	 * @param info
	 * @return
	 */
	bool read(std::string &info);	
};

#endif /* FILEIO_H_ */
