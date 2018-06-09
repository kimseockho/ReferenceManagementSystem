#ifndef database_H
#define database_H


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include<string>

using namespace std;
using std::string;


namespace data {


	struct articleRecord {
		std::string title;
		std::string author;
		std::string journal;
		std::string volume;
		std::string number;
		std::string pages;
		std::string year;
		std::string publisher;
	};


	struct inproceedingRecord {
		std::string author;
		std::string booktitle;
		std::string title;
		std::string year;
		std::string volume;
		std::string number;
		std::string pages;
		std::string keyworks;
		std::string doi;
		std::string ISSN;
		std::string month;
	};

	struct bookRecord {
		std::string author;
		std::string title;
		std::string publisher;
		std::string year;
		std::string volume;
		std::string series;
		std::string address;
		std::string edition;
		std::string month;
		std::string note;
		std::string isbn;
	};

	void addarticle(string title, string author, string journal, string volume, string number, string pages, string year, string publisher);


	void addinproceeding(string author, string booktitle, string title, string year, string volume, string number, string pages, string keywords, string doi, string ISSN, string month);

	void addbook(string author, string title, string publisher, string year, string volume, string series, string address, string edition, string month, string note, string isbn);


	void showarticletable();
	void showinproceedingtable();
	void showbooktable();



	void searchdatabase(string,string);

	void searcharticletable(string,string);
	void searchinproceedingtable(string, string);
	void searchbooktable(string, string);




	void exportAPA(string);
	string exportsearch(string);
}



#endif // database_H

