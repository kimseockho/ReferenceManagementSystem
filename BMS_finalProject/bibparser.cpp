#include "bibparser.h"

bibparser::bibparser()
{
}

bibparser::~bibparser()
{
}

void bibparser::reader(string s)
{
	filename = s;

	ifstream bibtext;					// to read the BibTeX document
	bibtext.open(filename);



	// loop until there is not any unread line in file
	while (getline(bibtext, line))
	{
		if (!bibtext.eof()) {

			if (f == 0)
			{

				checkbib();
			}
			else if (f == 1)
			{

				str_parse();
				articletemp(tag, contentvalue);
			}
			else if (f == 2)
			{
				str_parse();
				inproceedingtemp(tag, contentvalue);
			}
			else
			{
				str_parse();
				booktemp(tag, contentvalue);
			}

		}
	}

	if (type == "article" || type=="ARTICLE")
	{
		data::addarticle(title1, author1, journal1, volume1, number1, pages1, year1, publisher1);
	}
	else if (type == "inproceeding" || type=="INPROCEEDINGS")
	{

		data::addinproceeding(author2, booktitle2, title2, year2, volume2, number2, pages2, keywords2, doi2, ISSN2, month2);
	}
	else
	{
		data::addbook(author3, title3, publisher3, year3, volume3, series3, address3, edition3, month3, note3, isbn3);
	}

	bibtext.close();
}


void bibparser::str_parse()
{
	unsigned d2_id = 0, d3_id = 0, d4_id = 0, d2s = 0;				// to store Start and End indices of d1 and d2
																	// Find the start of first delimiter (d1)

	d2_id = line.find(d2);
	d3_id = line.find(d3);
	d4_id = line.find(d4);
	// identify "key" and "value" when start of the first delimiter (d1) is found
	if (d3_id == string::npos)
	{
		cout << "Information not found!" << endl;
	}

	else
	{
		tag = line.substr(2, d3_id - 2);
		d2s = d2_id + d2.length();
		contentvalue = line.substr(d2s, d4_id - d2s);
	}
}


void bibparser::checkbib()
{
	unsigned d1_idxS = 0, d1_idxE = 0, d2_idxS = 0;


	d1_idxS = line.find(d1);

	// checks whether delimiter found or not
	if (d1_idxS == string::npos)
	{
		std::cout << "No delimiter was found!" << endl;
	}

	key = line.substr(0, d1_idxS);
	d1_idxE = d1_idxS + d1.length();
	d2_idxS = line.find(d2);

	type = line.substr(d1_idxE, d2_idxS - d1_idxE);
	
	if (type == "article" ||type== "ARTICLE")
	{
		cout << "Atricle bibtex found" << endl;
		f = 1;
	}
	else if (type == "inproceeding" || type=="INPROCEEDINGS")
	{
		cout << "Inproceeding bibtex found" << endl;
		f = 2;
	}
	else
	{
		cout << "Book bibtex found" << endl;
		f = 3;
	}
}

void bibparser::articletemp(string t, string c)
{
	if (t == "title")
		title1 = c;
	if (t == "author")
		author1 = c;
	if (t == "journal")
		journal1 = c;
	if (t == "volume")
		volume1 = c;
	if (t == "number")
		number1 = c;
	if (t == "pages")
		pages1 = c;
	if (t == "year")
		year1 = c;
	if (t == "publisher")
		publisher1 = c;
}


void bibparser::inproceedingtemp(string t, string c)
{

	if (t == "author")
		author2 = c;
	if (t == "booktitle")
		booktitle2 = c;
	if (t == "title")
		title2 = c;
	if (t == "year")
		year2 = c;
	if (t == "volume")
		volume2 = c;
	if (t == "number")
		number2 = c;
	if (t == "pages")
		pages2 = c;
	if (t == "keywords")
		keywords2 = c;
	if (t == "doi")
		doi2 = c;
	if (t == "ISSN")
		ISSN2 = c;
	if (t == "month")
		month2 = c;
}


void bibparser::booktemp(string t, string c)
{

	if (t == "author")
		author3 = c;
	if (t == "title")
		title3 = c;
	if (t == "publisher")
		publisher3 = c;
	if (t == "year")
		year3 = c;
	if (t == "volume")
		volume3 = c;
	if (t == "series")
		series3 = c;
	if (t == "address")
		address3 = c;
	if (t == "edition")
		edition3 = c;
	if (t == "month")
		month3 = c;
	if (t == "note")
		note3 = c;
	if (t == "isbn")
		isbn3 = c;
}
