//============================================================================
// Name        : Object_fileio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "FileIO.h"

int main() {
	string data ="goats";
	string fn ="test.txt";
	FileIO mio(fn);
	
	mio.writeln(data);
	mio.writeln(data);
	
	mio.clear();
	
	string nd;
	mio.read(nd);
	cout<<nd<<endl;
	return 0;
}
