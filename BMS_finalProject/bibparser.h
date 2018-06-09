#pragma once
#ifndef BIBPARSER_H
#define BIBPARSER_H
#include <fstream>			// file R/W
#include <iostream>			// input and output functions
#include <string>			// basic string handling
#include <algorithm>		// for UpperCase()
#include <time.h>			// for set_time()
//#include "idate.h"


#include"database.h"

using namespace std;

class bibparser
{
private:
	string d1 = "@", d2 = "{", d3 = "=", d4 = "}", d5 = ","; 									// delimiters to identify the start and end
	string filename = " ", line = " ", key = " ", type = " ", tag = " ", contentvalue = " ";		// holds BibTex filename, line and parsed content/tag 
	char* time;
	int f = 0;																				// stores reference creation/modification time
																							//idate td1;



	void str_parse();
	void checkbib();


	//void str_UpperCase(string &var);
	//void str_delSpaces(string &var);

public:

	string title1, author1, journal1, volume1, number1, pages1, year1, publisher1;
	string author2, booktitle2, title2, year2, volume2=" ", number2=" ", pages2, keywords2, doi2, ISSN2=" ", month2;
	string  author3, title3, publisher3, year3, volume3, series3, address3, edition3, month3, note3, isbn3;

	bibparser();
	~bibparser();
	void reader(string s);
	void articletemp(string, string);
	void inproceedingtemp(string, string);
	void booktemp(string, string);

};
#endif